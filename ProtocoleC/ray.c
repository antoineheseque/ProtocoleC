#include "ray.h"
#include "camera.h"

Ray getRayFromPixel(Camera cam, int x, int y) {
	Ray ray;
	// Position
	Vector3 pos = cam.position;
	ray.position = pos;

	// Direction
	Vector3 dir;
	dir.x = (x - 0.5 * cam.screenWidth) / 100 - cam.position.x;
	dir.y = (y - 0.5 * cam.screenHeight) / 100 - cam.position.y;
	dir.z = 10.0 - cam.position.z;
	ray.direction = dir;

	//printf("%f %f %f\n", dir.x, dir.y, dir.z);

	return ray;
}