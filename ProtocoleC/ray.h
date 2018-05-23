#ifndef DEF_RAY
#define DEF_RAY

#include "mathC.h"
#include "camera.h"

typedef struct ray {
	Vector3 position;
	Vector3 direction;
} Ray;

Ray getRayFromPixel(Camera cam, int x, int y);
Ray getOrthogonalCam(Camera cam, int x, int y);
Ray getPerspectiveCam(Camera cam, int x, int y);
float deg2rad(float val);
#endif