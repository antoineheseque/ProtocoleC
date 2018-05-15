/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LECTURE D'UN FICHIER ET RENVOI D'UNE SCENE CONTENANT
 * TOUT LES PARAMETRES SELECTIONNES.
 *
 * MODELE DU FICHIER :
 * x;y;z #Position de la cam�ra
 * x;y;z #Orientation de la cam�ra
 * 1080 (longueur de l'image)
 * 720 (largueur de l'image)
 * formedel'objet1;centerposx;centerposy;centerposy;dimensionsx;dimensionsx;dimensionsx
 * formede2'objet1;centerposx;centerposy;centerposy;dimensionsx;dimensionsx;dimensionsx
 * formede3'objet1;centerposx;centerposy;centerposy;dimensionsx;dimensionsx;dimensionsx
 * ...
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdlib.h>
#include <stdio.h>

#ifndef MY_HEADER_FILE_
#define MY_HEADER_FILE_
#include "structs.h"
#endif

Scene readFile() {
	Scene scene;
	Camera cam;
	Object * objects = malloc(sizeof(Object));
	FILE * fichier = fopen("main.scene", "r");

	if (fichier == NULL)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return;
	}
	else
	{
		fscanf(fichier, "%f;%f;%f", &cam.position.x, &cam.position.y, &cam.position.z);
		fscanf(fichier, "%f;%f;%f", &cam.direction.x, &cam.direction.y, &cam.direction.z);
		fscanf(fichier, "%d", &cam.screenWidth);
		fscanf(fichier, "%d", &cam.screenHeight);
		fscanf(fichier, "%s;%f;%f;%f;%f;%f;%f", &objects->type, &objects->position.x, &objects->position.y, &objects->position.z, &objects->size.x, &objects->size.y, &objects->size.z);
	}

	scene.camera = cam;
	debugScene(scene); // Check in console if scene is successfully created from file data.
	fclose(fichier);
}
