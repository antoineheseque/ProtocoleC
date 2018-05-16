#ifndef DEF_OBJECTS
#define DEF_OBJECTS

#include "mathC.h"
#include "ray.h"

typedef enum objectType {
	Sphere,
	Cube,
	Plan
} ObjectType;

typedef struct object {
	Vector3 position;
	Vector3 size;
	ObjectType type;
} Object;

char * getObjectType(ObjectType type);

Vector3 CollideWithPlan(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);
Vector3 CollideWithSphere(Ray ray, Vector3 orig, int radius);
#endif