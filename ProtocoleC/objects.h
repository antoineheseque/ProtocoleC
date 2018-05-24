#ifndef DEF_OBJECTS
#define DEF_OBJECTS

#include "mathC.h"
#include "ray.h"
#include "color.h"

typedef struct poly {
	Vector3 * pts;
	int nbPts;
} Poly;

typedef struct object {
	Vector3 position;

	// Specific to SPHERE
	double radius;

	// Specific to CUBE & PLAN
	Vector3 size;
	Vector3 normale;
	Poly poly;

	Color color;
	char type[4];
} Object;

Vector3 checkPolygone(Ray ray, int nbPts, Vector3 * pts);
Vector3 CollideWithGround(Ray ray, Vector3 normale, Vector3 center, Vector3 size);
Vector3 CollideWithSphere(Ray ray, Vector3 orig, int radius);
int coplanar(Vector3 a, Vector3 b, Vector3 c);
Vector3 intersect(Ray ray, Vector3 v1, Vector3 v2, Vector3 v3);
#endif
