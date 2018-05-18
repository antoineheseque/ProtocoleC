#include "ray.h"
#include "camera.h"

Ray getRayFromPixel(Camera cam, int x, int y) {
	Ray ray;
	// Position
	Vector3 pos = cam.position;
	pos.x += (((float)cam.screenWidth / 2) - x);
	pos.x /= 90;// ((float)cam.screenWidth / (float)cam.screenHeight);
	pos.y += (((float)cam.screenHeight / 2) - y + 150);
	pos.y /= 90;//((float)cam.screenWidth / (float)cam.screenHeight);
	ray.position = pos;

	// Direction
	/*Vector3 dir = cam.direction;
	dir.x += (((float)cam.screenWidth / 2) - x);
	dir.x /= 90;// ((float)cam.screenWidth / (float)cam.screenHeight);
	dir.y += (((float)cam.screenHeight / 2) - y);
	dir.y /= 90;//((float)cam.screenWidth / (float)cam.screenHeight);
	//printf("%.2f %.2f\n", dir.x, dir.y);*/
	Vector3 dir = { 0, 0, 1, 0 };
	//dir.z = 1;

	dir = normalizeVector(dir);

	ray.direction = dir;

	return ray;
}