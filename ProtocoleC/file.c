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

Scene readFile() {
	Scene scene;
	Camera cam;
	Object * objects = (Object *) malloc(sizeof(Object));
	FILE * fichier = fopen("main.scene", "r");

	if (fichier != NULL)
	{
		fscanf(fichier, "%d;%d;%d", &cam.position.x, &cam.position.y, &cam.position.z);
		fscanf(fichier, "%d;%d;%d", &cam.direction.x, &cam.direction.y, &cam.direction.z);
		fscanf(fichier, "%d", &cam.screenWidth);
		fscanf(fichier, "%d", &cam.screenHeight);
		fscanf(fichier, "%s;%d;%d;%d;%d;%d;%d", &objects->type, &objects->position.x, &objects->position.y, &objects->position.z, &objects->size.x, &objects->size.y, &objects->size.z);
	
		scene.camera = cam;
		scene.objectsCount = 1;
		scene.object = objects;
	}

	fclose(fichier);

	return scene;
}
