#include <stdlib.h>
#include <stdio.h>

#ifndef MY_HEADER_FILE_
#define MY_HEADER_FILE_
#include "structs.h"
#endif

int main(int argc, char *argv[]) {

	printf("+----------------------------+\n| \t  Protocole C\t     |\n+----------------------------+\n");

	readFile();

	system("pause");
	return 0;
}