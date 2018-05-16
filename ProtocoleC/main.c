#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "color.h"
#include "ray.h"

int main(int argc, char *argv[]) {

	printf("+----------------------------+\n| \t  Protocole C\t     |\n+----------------------------+\n");
	Scene scene;
	scene = readFile();

	// -------------------------------------- IMAGE
	for (int y = 0; y < scene.camera.screenHeight; y++) {
		for (int x = 0; x < scene.camera.screenWidth; x++) {
			Color color;
			Ray ray = getRayFromPixel(scene.camera, x, y);
		}
	}

	// -------------------------------------- EXPORT IMG
	Color * color = malloc(sizeof(Color) * scene.camera.screenHeight * scene.camera.screenWidth);

	 

	exportIMG(scene.camera, color);

	system("pause");
	return 0;
}