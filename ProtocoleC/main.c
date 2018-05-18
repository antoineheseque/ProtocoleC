#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "color.h"
#include "mathC.c"
#include "ray.h"
#include "objects.h"

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
			for (int i = 0; i < scene.objectsCount; i++) {
				Vector3 tempIntersect;
				if (strcmp(scene.object[i].type, "sph") == 0) {
					tempIntersect = CollideWithSphere(ray, scene.object[i].position, scene.object[i].size.x);
				}



				if (tempIntersect.empty == 0) {
					if(intersection.empty == 1)
						intersection = tempIntersect;
					else if(DistVector(camPos, tempIntersect) < DistVector(camPos, intersection))
						intersection = tempIntersect;
				}
					
			}
			
			if (intersection.empty == 0) { // Si un objet à été touché on change la couleur du pixel
				pixelColor.r = 0;
				pixelColor.g = 0;
				pixelColor.b = 0;
				
			}
			else {
				pixelColor.r = 255;
				pixelColor.g = 255;
				pixelColor.b = 255;
			}

			colors[y * scene.camera.screenWidth + x] = pixelColor;
		}
		
	}
	
	// -------------------------------------- EXPORT IMG
	exportIMG(scene.camera, colors, fileName);
	return 0;
}