#pragma once
#include "camera.h"
#include "objects.h"

typedef struct scene {
	Camera camera;

	int objectsCount;
	Object * object;
} Scene;

void debugScene(Scene scene);