#include <stdlib.h>
#include <stdio.h>

#ifndef MY_HEADER_FILE_
#define MY_HEADER_FILE_
#include "structs.h"
#endif

int main(int argc, char *argv[]) {

	printf("+----------------------------+\n| \t  Protocole C\t     |\n+----------------------------+\n");

	if (argc == 2) {
		readFile(argv[1]);
	}
	else {
		printf("[Error] Probleme lors de la lecture du fichier en argument, veuillez reessayer.\n");

		system("pause");
	}

	system("pause");
	return 0;
}