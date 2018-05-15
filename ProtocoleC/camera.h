#pragma once
#include "math.h"

typedef struct camera {
	Vector3 position;
	Vector3 direction;
	int screenWidth;
	int screenHeight;
} Camera;