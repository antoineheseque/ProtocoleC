#ifndef DEF_MATH
#define DEF_MATH

#include "mathC.h"

typedef struct vector3 {
	int x;
	int y;
	int z;

	int empty;
} Vector3;

int minValue(int a, int b);
int maxValue(int a, int b);
Vector3 AddVector(Vector3 a, Vector3 b);
Vector3 SubVector(Vector3 a, Vector3 b);
Vector3 ProductVector(Vector3 a, Vector3 b);
int ScalarVector(Vector3 a, Vector3 b);
float DistVector(Vector3 a, Vector3 b);
#endif