#ifndef MY_HEADER_FILE_
#define MY_HEADER_FILE_
#include "structs.h"
#endif

int minValue(int a, int b) {
	if (a > b)
		return b;
	return a;
}

int maxValue(int a, int b) {
	if (a < b)
		return b;
	return a;
}
