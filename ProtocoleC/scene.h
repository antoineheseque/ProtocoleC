#ifndef DEF_SCENE
#define DEF_SCENE

#include "camera.h"
#include "objects.h"
#include "light.h"

typedef struct scene {
	Camera camera;
	Light light;
	int objectsCount;
	Object * object;
} Scene;
#endif
