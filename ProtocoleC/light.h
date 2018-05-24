#ifndef DEF_LIGHT
#define DEF_LIGHT

#include "color.h"
#include "ray.h"

typedef struct light {
	Vector3 position;
	Color color;
	double intensity;
	char type[4];
} Light;

float getLightIntensity(Vector3 L, Vector3 normal);
int getLightIntensity2(Ray ray, Vector3 normale);
int getSpecularEffect(Ray ray, Vector3 normale);
#endif