#include "light.h"
#include "mathC.h"
#include "ray.h"
#include <math.h>

float getLightIntensity(Vector3 L, Vector3 normal) {
	float intensity;
	float nbr = cos(ScalarVector(L, normal)/(LengthVector(L) * LengthVector(normal)));
	intensity = 1 - nbr; //LengthVector(L) / (0.466 * ScalarVector(L, normal))
	return intensity;
}

float getLightIntensity2(Ray ray, Vector3 normale) {
	Vector3 V = InvertVector(ray.direction);
	Vector3 L = ray.direction;

	float val = 0;
	val = 0.6 * maxValue(0, ScalarVector(normale, L));
	return val;
}