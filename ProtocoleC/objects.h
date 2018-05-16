#ifndef DEF_OBJECTS
#define DEF_OBJECTS

#include "mathC.h"

typedef enum objectType {
	Sphere,
	Cube
} ObjectType;

typedef struct object {
	Vector3 position;
	Vector3 size;
	ObjectType type;
} Object;

char * getObjectType(ObjectType type);

#endif