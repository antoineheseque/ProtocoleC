#include <stdio.h>
#include <stdlib.h>
#include "scene.h"

int main(int argc, char *argv[]) {

	printf("+----------------------------+\n| \t  Protocole C\t     |\n+----------------------------+\n");
	Scene scene;
	scene = readFile();

	system("pause");
	return 0;
}