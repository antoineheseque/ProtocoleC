#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "mathC.h"

typedef struct camera{
	Vector3 position;
	Vector3 direction;
	int screenWidth;
	int screenHeight;
} Camera;
#endif