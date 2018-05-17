#include "ray.h"
#include "camera.h"

Ray getRayFromPixel(Camera cam, int x, int y) {
	Ray ray;
	// Position
	Vector3 pos = cam.position;
	ray.position = pos;

	// Direction
	Vector3 dir;
	//dir.x = (x - 0.5 * cam.screenWidth) / 1000 - cam.position.x;
	//dir.y = (y - 0.5 * cam.screenHeight)/ 1000 - cam.position.y;
	//dir.z = -1.0;

	float scale = tan(45 * 2.1415 / 180);
	float imageAspectRatio = cam.screenWidth / (float)cam.screenHeight;

	dir.x = (2 * (x + 0.5) / (float)cam.screenWidth - 1) * imageAspectRatio * scale;
	dir.y = (1 - 2 * (y + 0.5) / (float)cam.screenHeight) * scale;
	dir.z = -1;
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