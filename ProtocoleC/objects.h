#ifndef DEF_OBJECTS
#define DEF_OBJECTS

#include "mathC.h"
#include "ray.h"
#include "color.h"

typedef struct object {
	Vector3 position;
	
	// Specific to SPHERE
	double radius;

	// Specific to CUBE & PLAN
	Vector3 size;
	Vector3 normale;

	Color color;
	char type[4];
} Object;

Vector3 checkPolygone(Ray ray, int nbPts, Vector3 * pts);
Vector3 CollideWithPlan(Ray ray, Vector3 normale, Vector3 center, Vector3 size);
Vector3 CollideWithSphere(Ray ray, Vector3 orig, int radius);
#endif
