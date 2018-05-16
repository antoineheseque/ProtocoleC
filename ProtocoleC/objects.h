#ifndef DEF_OBJECTS
#define DEF_OBJECTS

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