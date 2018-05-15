#include "header.h"
#include "file.h"

int main(int argc, char *argv[]) {

	printf("+----------------------------+\n| \t  Protocole C\t     |\n+----------------------------+\n");
	Scene scene;
	scene = readFile();

	system("pause");
	return 0;
}