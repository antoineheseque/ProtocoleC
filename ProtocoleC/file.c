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
		Light * light = (Light *) malloc(sizeof(Light));
		Object * objects = (Object *)malloc(sizeof(Object));

		// AJOUT DU PLAN PAR DEFAUT
		Vector3 normale = { 0,1,0,0 };
		Vector3 pos = { 0,0,0,0 };
		strcpy(objects[0].type, "gro");
		objects[0].position = pos;
		objects[0].normale = normale;

		int nbObjects = 0;
		int nbLights = 0;
		fscanf(fichier, "%lf;%lf;%lf", &cam.position.x, &cam.position.y, &cam.position.z);
		fscanf(fichier, "%lf;%lf;%lf", &cam.direction.x, &cam.direction.y, &cam.direction.z);
		fscanf(fichier, "%d", &cam.screenWidth);
		fscanf(fichier, "%d", &cam.screenHeight);
		fscanf(fichier, "%d", &nbLights);
		for (int i = 0; i < nbLights; i++) {
			light = realloc(light, sizeof(Light) * (i + 2));
			fscanf(fichier, "%3s;%lf;%lf;%lf;%lf", &light[i].type, &light[i].intensity, &light[i].position.x, &light[i].position.y, &light[i].position.z);
		}
		fscanf(fichier, "%d", &nbObjects);
		nbObjects++; // Ajout du plan défini au dessus
		for(int i = 1; i < nbObjects; i++){
			objects = realloc(objects, sizeof(Object) * (i+2));
			fscanf(fichier, "%3s", &objects[i].type);

			if (strcmp(objects[i].type, "sph") == 0) {
				fscanf(fichier, ";%lf;%lf;%lf;%lf;%d;%d;%d", &objects[i].position.x, &objects[i].position.y, &objects[i].position.z, &objects[i].radius, &objects[i].color.r, &objects[i].color.g, &objects[i].color.b);
			}
			else if (strcmp(objects[i].type, "pol") == 0) {
				fscanf(fichier, ";%d", &objects[i].poly.nbPts);
				objects[i].poly.pts = (Vector3 *) malloc(objects[i].poly.nbPts * sizeof(Vector3));
				for(int j = 0; j < objects[i].poly.nbPts; j++){
					fscanf(fichier, ";%lf;%lf;%lf", &objects[i].poly.pts[j].x, &objects[i].poly.pts[j].y, &objects[i].poly.pts[j].z);
					objects[i].poly.pts[j].x = -objects[i].poly.pts[j].x;
				}
				fscanf(fichier, ";%d;%d;%d", &objects[i].color.r, &objects[i].color.g, &objects[i].color.b);
			}
			objects[i].position.x = -objects[i].position.x;
		}

		scene.camera = cam;
		scene.objectsCount = nbObjects;
		scene.object = objects;
		scene.lightsCount = nbLights;
		scene.light = light;
	}

	fclose(fichier);
	return scene;
}
