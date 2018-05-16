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

	// -------------------------------------- RECUPERATION PIXEL PAR PIXEL ET RECHERCHE DE LA COULEUR DE CHAQUE PIXEL PAR RAPPORT A CHAQUE OBJETS
	Vector3 camPos = scene.camera.position;
	for (int y = 0; y < scene.camera.screenHeight; y++) {
		for (int x = 0; x < scene.camera.screenWidth; x++) {
			Color pixelColor;
			Ray ray = getRayFromPixel(scene.camera, x, y);

			Vector3 intersection;
			intersection.empty = 1;

			for (int i = 0; i < scene.objectsCount; i++) {
				Vector3 tempIntersect;
				switch (scene.object[i].type) {
					case Sphere:
						tempIntersect = CollideWithSphere(ray, scene.object[i].position, scene.object[i].size.x);
						break;
					default:
						tempIntersect.empty = 1;
				}

				if (tempIntersect.empty != 1 && (DistVector(camPos, tempIntersect) > DistVector(camPos, intersection)))
					intersection = tempIntersect;
			}
			
			if (intersection.empty == 0) { // Si un objet à été touché on change la couleur du pixel
				pixelColor.r = 255;
				pixelColor.g = 255;
				pixelColor.b = 255;
			}
			else {
				pixelColor.r = 0;
				pixelColor.g = 0;
				pixelColor.b = 0;
			}

			colors[y * scene.camera.screenWidth + x] = pixelColor;
		}
	}

	// -------------------------------------- EXPORT IMG
	exportIMG(scene.camera, colors);

	system("pause");
	return 0;
}