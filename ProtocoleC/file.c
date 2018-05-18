/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LECTURE D'UN FICHIER ET RENVOI D'UNE SCENE CONTENANT
 * TOUT LES PARAMETRES SELECTIONNES.
 *
 * MODELE DU FICHIER :
 * x;y;z #Position de la camera
 * x;y;z #Orientation de la camera
 * 1080 (longueur de l'image)
 * 720 (largueur de l'image)
 * formedel'objet1;centerposx;centerposy;centerposy;dimensionsx;dimensionsx;dimensionsx
 * formede2'objet1;centerposx;centerposy;centerposy;dimensionsx;dimensionsx;dimensionsx
 * formede3'objet1;centerposx;centerposy;centerposy;dimensionsx;dimensionsx;dimensionsx
 * ...
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "camera.h"
#include "objects.h"
#include "light.h"

Scene readFile() {
	Scene scene;
	FILE * fichier = fopen("main.scene", "r");

	if (fichier != NULL)
	{
		Camera cam;
		Light light;
		Object * objects = (Object *)malloc(sizeof(Object));

		fscanf(fichier, "%lf;%lf;%lf", &cam.position.x, &cam.position.y, &cam.position.z);
		fscanf(fichier, "%lf;%lf;%lf", &cam.direction.x, &cam.direction.y, &cam.direction.z);
		fscanf(fichier, "%d; %lf;%lf;%lf", &light.add, &light.position.x, &light.position.y, &light.position.z);
		fscanf(fichier, "%d", &cam.screenWidth);
		fscanf(fichier, "%d", &cam.screenHeight);
		fscanf(fichier, "%lf;%lf;%lf;%lf;%lf;%lf;%d;%d;%d;%3s", &objects->position.x, &objects->position.y, &objects->position.z, &objects->size.x, &objects->size.y, &objects->size.z, &objects->color.r, &objects->color.g, &objects->color.b, &objects->type);

		scene.camera = cam;
		scene.objectsCount = 1;
		scene.object = objects;
		scene.light = light;
	}

	fclose(fichier);
	return scene;
}
