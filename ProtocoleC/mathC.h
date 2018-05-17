#ifndef DEF_MATH
#define DEF_MATH

#include "mathC.h"

typedef struct vector3 {
	double x;
	double y;
	double z;

	int empty;
} Vector3;

Vector3 normalizeVector(Vector3 vec);
int minValue(int a, int b);
int maxValue(int a, int b);
Vector3 AddVector(Vector3 a, Vector3 b);
Vector3 SubVector(Vector3 a, Vector3 b);
Vector3 ProductVector(Vector3 a, Vector3 b);
double ScalarVector(Vector3 a, Vector3 b);
double LengthVector(Vector3 a);
double DistVector(Vector3 a, Vector3 b);
#endif