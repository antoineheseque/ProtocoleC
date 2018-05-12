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
	//Scene scene;
	//Camera cam;
	Object * objects = malloc(sizeof(Object));
	FILE *fp;
	errno_t err;

	err = fopen_s(&fp, "main.scene", "r");
	if (err != 0)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return;
	}

	const size_t line_size = 100;
	char* line = malloc(line_size);
	int lineCounter = 0;
	while (fgets(line, line_size, fp) != NULL) {
		lineCounter++;
		printf(line);
	}
	free(line);    // dont forget to free heap memory

	//scene.camera = cam;
	//debugScene(scene); // Check in console if scene is successfully created from file data.
	fclose(fp);
}