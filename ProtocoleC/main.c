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
			Ray ray = getRayFromPixel(scene.camera, x, y);
			//printf("%.10f %0.10f %.10f\n", ray.direction.x, ray.direction.y, ray.direction.z);
			//printf("%.10f %.10f %.10f", scene.camera.position.x, scene.camera.position.y, scene.camera.position.z);
			Vector3 intersection;
			intersection.empty = 1;
			Object intersectedObject;
			for (int i = 0; i < scene.objectsCount; i++) { // Pour tout les objets de la scène
				Vector3 tempIntersect;
				Object tempObj;
				if (strcmp(scene.object[i].type, "sph") == 0) { // Si l'objet est une sphere
					tempIntersect = CollideWithSphere(ray, scene.object[i].position, scene.object[i].radius);
					tempObj = scene.object[i];
				}
				if (strcmp(scene.object[i].type, "pla") == 0) { // Si l'objet est une sphere
					tempIntersect = CollideWithPlan(ray, scene.object[i].normale, scene.object[i].position, scene.object[i].size);
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
			if (intersection.empty == 0) { // Si un objet à été touché on change la couleur du pixel
				Color col = intersectedObject.color;

				if (strcmp(intersectedObject.type, "pla") == 0) {
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

				Vector3 L = SubVector(scene.light.position, intersection);
				//L = normalizeVector(L);
				Vector3 normal = intersection;

				//printf("%f\n", getLightIntensity(L, normal));
				Ray ray2;
				ray2.position = intersection;// AddVector(intersection, intersectedObject.position);
				ray2.direction = normalizeVector(normal);
				//ray2.position = AddVector(ray2.position, normalizeVector(normal));

				// 0 = TOUCHER UN OBJ
				// 1 = TOUCHER AUCUN OBJ

				Vector3 canTouchLight = { 0,0,0,1 };
				for (int i = 0; i < scene.objectsCount; i++) {
					Vector3 temp = { 0,0,0,1 };
					if (strcmp(scene.object[i].type, "sph") == 0) { 
						temp = CollideWithSphere(ray2, scene.object[i].position, scene.object[i].radius);
					}

					if (canTouchLight.empty == 1 && temp.empty == 0)
						canTouchLight = temp;
				}

				//printf("%d \n", canTouchLight.empty);

				if (canTouchLight.empty == 1) { // Si le rayon entre l'obj touché et la lumière n'est pas coupé
					if (strcmp(intersectedObject.type, "sph") == 0)
						col = ApplyLightEffect(col, 4 * getLightIntensity(L, normal));
					
					pixelColor.r = col.r;
					pixelColor.g = col.g;
					pixelColor.b = col.b;
				} else {
					pixelColor.r = 0;
					pixelColor.g = 0;
					pixelColor.b = 0;
				}
			}
			else {
				int c = 127 * cos(ray.direction.y * 100 / 360) + 127;
				//printf("%d\n", c);
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