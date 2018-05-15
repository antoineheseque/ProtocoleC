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

Vector3 AddVector(Vector3 a, Vector3 b) {
	Vector3 vector;
	vector.x = a.x + b.x;
	vector.y = a.y + b.y;
	vector.z = a.z + b.z;

	return vector;
}

Vector3 subVector(Vector3 a, Vector3 b) {
	Vector3 vector;
	vector.x = a.x - b.x;
	vector.y = a.y - b.y;
	vector.z = a.z - b.z;
	
	return vector;
}

Vector3 productVector(Vector3 a, Vector3 b) {
	Vector3 vector;
	vector.x = (a.y*b.z) - (a.z*b.y);
	vector.y = (a.z*b.x) - (a.x*b.z);
	vector.y = (a.x*b.y) - (a.y*b.x);

	return vector;
}

int scalarVector(Vector3 a, Vector3 b) {
	int scalar;
	scalar = a.x*b.x + a.y*b.y + a.z*b.z;

	return scalar;
}