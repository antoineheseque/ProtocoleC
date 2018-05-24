#include "ray.h"
#include "camera.h"
#include <math.h>

Ray getRayFromPixel(Camera cam, int x, int y) {
	//Ray ray = getOrthogonalCam(cam, x, y);
	Ray ray = getPerspectiveCam(cam, x, y);

	return ray;
	/*Vector3 dir = cam.direction;
	dir.x += (((float)cam.screenWidth / 2) - x);
	dir.x /= 90;// ((float)cam.screenWidth / (float)cam.screenHeight);
	dir.y += (((float)cam.screenHeight / 2) - y);
	dir.y /= 90;//((float)cam.screenWidth / (float)cam.screenHeight);
	dir = normalizeVector(dir);*/
	//printf("%.2f %.2f\n", dir.x, dir.y)
}

Ray getPerspectiveCam(Camera cam, int x, int y) {
	Ray ray;
	Vector3 pos = cam.position;
	ray.position = pos;

	Vector3 dir;
	dir.x = ((double) (cam.screenWidth / 2) - x + 0.5) / 90;
	dir.y = ((double) (cam.screenHeight / 2) - y + 0.5) / 90;
	dir.z = 10;

	dir = normalizeVector(dir);

	//printf("%.2f %.2f \n", dir.x, dir.y);
	ray.direction = dir;

	return ray;
}

Ray getOrthogonalCam(Camera cam, int x, int y) {
	Ray ray;
	// Position
	Vector3 pos = cam.position;
	pos.x += (((float)cam.screenWidth / 2) - x);
	pos.x /= 90;// ((float)cam.screenWidth / (float)cam.screenHeight);
	pos.y += (((float)cam.screenHeight / 2) - y + 150);
	pos.y /= 90;//((float)cam.screenWidth / (float)cam.screenHeight);
	ray.position = pos;

	Vector3 dir = { 0, 0, 1, 0 };
	ray.direction = dir;

	return ray;
}

float deg2rad(float val) {
	return val * 3.1415 / 180;
}