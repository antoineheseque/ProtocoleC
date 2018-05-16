#include "ray.h"
#include "camera.h"

Ray getRayFromPixel(Camera cam, int x, int y) {
	Ray ray;
	// Position
	Vector3 pos = cam.position;
	ray.position = pos;

	// Direction


	// Code pour tracer le rayon

	return ray;
}