#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "color.h"
#include "mathC.c"
#include "ray.h"
#include "objects.h"
#include "light.h"

int main(int argc, char *argv[]) {

	printf("+----------------------------+\n| \t  Protocole C\t     |\n+----------------------------+\n");
	Scene scene;
	scene = readFile();

	Color * colors = malloc(sizeof(Color) * scene.camera.screenHeight * scene.camera.screenWidth);
	
	char * fileName = malloc(sizeof(char) * 16);
	if (argc == 2)
		fileName = argv[1];
	else
		fileName = "result";

	// -------------------------------------- RECUPERATION PIXEL PAR PIXEL ET RECHERCHE DE LA COULEUR DE CHAQUE PIXEL PAR RAPPORT A CHAQUE OBJETS
	Vector3 camPos = scene.camera.position;
	for (int y = 0; y < scene.camera.screenHeight; y++) {
		for (int x = 0; x < scene.camera.screenWidth; x++) {
			Color pixelColor;

			// Tracer le rayon et récupérer l'intersection
			Ray ray = getRayFromPixel(scene.camera, x, y);
			Vector3 intersection;
			intersection.empty = 1; // Aucun objet n'a été touché par défaut
			Object intersectedObject;
			for (int i = 0; i < scene.objectsCount; i++) { // Pour tout les objets de la scène
				Vector3 tempIntersect = { 0, 0, 0, 1 };
				Object tempObj;
				if (strcmp(scene.object[i].type, "sph") == 0) { // Si l'objet est une sphere
					tempIntersect = CollideWithSphere(ray, scene.object[i].position, scene.object[i].radius);
					tempObj = scene.object[i];
				}
				if (strcmp(scene.object[i].type, "gro") == 0) { // Si l'objet est un sol
					tempIntersect = CollideWithGround(ray, scene.object[i].normale, scene.object[i].position);
					tempObj = scene.object[i];
				}

				if (tempIntersect.empty == 0) { // Si un objet à été touché...
					if (intersection.empty == 1) { // Si aucun objet n'avais déjà été touché...
						intersection = tempIntersect;
						intersectedObject = tempObj;
					}
					// Sinon si un objet plus proche que celui déjà touché est touché ...
					else if (DistVector(camPos, tempIntersect) < DistVector(camPos, intersection)) { 
						intersection = tempIntersect;
						intersectedObject = tempObj;
					}
				}
			}

			// Si un objet à été touché on change la couleur du pixel
			if (intersection.empty == 0) { 

				// Récupérer la couleur de base
				Color col = { 0,0,0 };

				// ------------------------------------------------------ Afficher le sol de base (sol)
				if (strcmp(intersectedObject.type, "gro") == 0) {
					int x = (int)abs(intersection.x) % 4;
					int y = (int)abs(intersection.z) % 4;

					if ((x > 2 && y > 2) || (x <= 2 && y <= 2)) {
						col.r = 120;
						col.g = 120;
						col.b = 120;
					}
					else {
						col.r = 200;
						col.g = 200;
						col.b = 200;
					}
				}
				// ------------------------------------------------------ FIN Afficher le sol de base (sol)



				// -------------------------------------- APPLIQUER LES JEUX D'OMBRES ET DE LUMIERES
				Vector3 normale = SubVector(intersection, intersectedObject.position);
				Ray ray2;
				ray2.position = AddVector(intersection, MultiplyVector(normale, 0.01)); // AddVector(intersection, intersectedObject.position);

				int intersectWithLight = 0;
				for (int i = 0; i < scene.lightsCount; i++) { // TEMPORAIREMENT UNE SEULE LUMIERE CAR LE CODE PR LES OMBRES EST FAIR PR UNE SEULE LUMIERE WOLAAAA !!!!!!!!!!!!
					ray2.direction = normalizeVector(SubVector(scene.light[i].position, intersection));

					// VERIFIER SI L'OBJET PEUT ATTEINDRE LA LUMIERE
					Vector3 canTouchLight = { 0,0,0,1 };
					for (int i = 0; i < scene.objectsCount; i++) {
						Vector3 temp = { 0,0,0,1 };
						if (strcmp(scene.object[i].type, "sph") == 0) {
							temp = CollideWithSphere(ray2, scene.object[i].position, scene.object[i].radius);
						}

						if (canTouchLight.empty == 1 && temp.empty == 0)
							canTouchLight = temp;
					}

					// SI LE RAYON ATTEINT LA LUMIERE
					if (canTouchLight.empty == 1) {
						intersectWithLight = 1;
						if(col.r == 0 && col.g == 0 && col.b == 0) // Appliquer la couleur de base si au moins une lumière atteint l'objet
							col = AddColor(col, intersectedObject.color);

						// SI C'EST UNE LUMIERE NORMALE
						if (strcmp(scene.light[i].type, "nor") == 0) {
							if (strcmp(intersectedObject.type, "gro") != 0) //Si ce n'est pas le sol
								//col = ApplyLightEffect(intersectedObject.color, 4 * getLightIntensity(ray2.direction, normale));
								col = AddColorInt(col, getLightIntensity2(ray2, normale));
						}

						// SI C'EST UNE LUMIERE SPECULAIRE
						if (strcmp(scene.light[i].type, "spe") == 0) {
							if (strcmp(intersectedObject.type, "gro") != 0)
								col = AddColorInt(col, getSpecularEffect(ray2, normale));
						}

						// SI C'EST UNE LUMIERE QUI FAIT LES DEUX
						if (strcmp(scene.light[i].type, "all") == 0) {
							if (strcmp(intersectedObject.type, "gro") != 0) { //Si ce n'est pas le sol
								//col = ApplyLightEffect(intersectedObject.color, 4 * getLightIntensity(ray2.direction, normale));
								col = AddColorInt(col, getLightIntensity2(ray2, normale));
								col = AddColorInt(col, getSpecularEffect(ray2, normale));
							}
						}
					}

					if (intersectWithLight == 0) { // SI AUCUNE LUMIERE N'A ETE TOUCHE
						col.r = 0;
						col.g = 0;
						col.b = 0;
					}
				}
				pixelColor.r = col.r;
				pixelColor.g = col.g;
				pixelColor.b = col.b;
			}
			// --------------------------------------------------------- AFFICHER UN BACKGROUND
			else {
				int c = 127 * cos(ray.direction.y * 100 / 360) + 127;
				pixelColor.r = 0;
				pixelColor.g = 0;
				pixelColor.b = (int) c;
			}

			colors[y * scene.camera.screenWidth + x] = pixelColor;
		}
	}
	
	// -------------------------------------- EXPORT IMG
	exportIMG(scene.camera, colors, fileName);
	system("pause");
	return 0;
}