#include "ray.h"
#include "camera.h"

Ray getRayFromPixel(Camera cam, int x, int y) {
	Ray ray;
	// Position
	Vector3 pos = cam.position;

	ray.position = pos;

	// Direction
	Vector3 dir = cam.direction;
	dir.x += (((float)cam.screenWidth / 2) - x);
	dir.x /= 90;// ((float)cam.screenWidth / (float)cam.screenHeight);
	dir.y += (((float)cam.screenHeight / 2) - y);
	dir.y /= 90;//((float)cam.screenWidth / (float)cam.screenHeight);
	//printf("%.2f %.2f\n", dir.x, dir.y);
	dir.z = 1;

	dir = normalizeVector(dir);

	ray.direction = dir;

	return ray;
}

Vector3 matrixVec(Vector3 vec) {
	Vector3 rslt;
	int x[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	rslt.x = vec.x * x[0][0] + vec.y * x[1][0] + vec.z * x[2][0];
	rslt.y = vec.x * x[0][1] + vec.y * x[1][1] + vec.z * x[2][1];
	rslt.z = vec.x * x[0][2] + vec.y * x[1][2] + vec.z * x[2][2];
	return rslt;
}