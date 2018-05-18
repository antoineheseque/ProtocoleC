#include "light.h"
#include "mathC.h"
#include <math.h>

float getLightIntensity(Vector3 L, Vector3 normal) {
	float intensity;
	float nbr = cos(ScalarVector(L, normal)/(LengthVector(L) * LengthVector(normal)));
	intensity = LengthVector(L) / (0.466 * ScalarVector(L, normal));; //1-nbr
	return intensity;
}