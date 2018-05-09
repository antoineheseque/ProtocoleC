/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LECTURE D'UN FICHIER ET RENVOI D'UNE SCENE CONTENANT 
 * TOUT LES PARAMETRES SELECTIONNES.
 * 
 * MODELE DU FICHIER :
 * x;y;z #Position de la caméra
 * x;y;z #Orientation de la caméra
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
#include "scene.c";

scene readFile(char* name) {


	FILE *fp;
	fp = fopen("main.scene", "r");



	fclose(fp);
}