#ifndef DEF_MATH
#define DEF_MATH

#include "mathC.h"
#include <stdio.h>

typedef struct vector3 {
	double x;
	double y;
	double z;

	int empty;
} Vector3;

typedef struct delta {
	double a;
	double b;
	double c;
	double delta;
	double x1;
	double x2;
} Delta;

int minValue(int a, int b);
int maxValue(int a, int b);
Vector3 AddVector(Vector3 a, Vector3 b);
Vector3 SubVector(Vector3 a, Vector3 b);
Vector3 ProductVector(Vector3 a, Vector3 b);
int ScalarVector(Vector3 a, Vector3 b);
float DistVector(Vector3 a, Vector3 b);
double delta(double a, double b, double c);
#endif
