#include <stdlib.h>
#include <stdio.h>
#include "file.c";
int main(int argc, char *argv[]) {

	printf("+----------------------------+\n| \t  Protocole C\t     |\n+----------------------------+\n");

	if (argc == 2) {
		readFile(argv[1]);
	}

	printf("[Error] Probleme lors de la lecture du fichier en argument, veuillez reessayer.\n");

	system("pause");
	return 0;
}