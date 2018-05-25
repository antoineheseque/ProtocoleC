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

int getLightIntensity2(Ray ray, Vector3 normale) {
	//Vector3 V = InvertVector(ray.direction);
	Vector3 L = ray.direction;

	int val = 0;
	val = (int) (60 * maxValue(0, ScalarVector(normale, L)));
	//printf("%d\n", val);
	return val;
}

int getSpecularEffect(Ray ray, Vector3 normale) {
	Vector3 V = normalizeVector(InvertVector(ray.direction));
	Vector3 H = AddVector(V, normale);

	int val = 0;
	val = (int)(maxValue(0, ScalarVector(normale, H)));
	//printf("%d\n", val);
	return val;
}