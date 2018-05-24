#ifndef DEF_MATH
#define DEF_MATH

#include "mathC.h"

typedef struct vector3 {
	double x;
	double y;
	double z;

	int empty;
} Vector3;

typedef struct matrix44 {
	float matrix[4][4];
} Matrix44;

Vector3 normalizeVector(Vector3 vec);
double minValue(double a, double b);
double maxValue(double a, double b);
Vector3 AddVector(Vector3 a, Vector3 b);
Vector3 SubVector(Vector3 a, Vector3 b);
Vector3 ProductVector(Vector3 a, Vector3 b);
Vector3 InvertVector(Vector3 vec);
Vector3 MultiplyVector(Vector3 a, double val);
double ScalarVector(Vector3 a, Vector3 b);
double LengthVector(Vector3 a);
double DistVector(Vector3 a, Vector3 b);
//Vector3 multVecMatrix(Vector3 vec);
#endif