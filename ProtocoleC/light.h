#ifndef DEF_LIGHT
#define DEF_LIGHT

#include "color.h"
#include "ray.h"

typedef struct light {
  int add;
	Vector3 position;
	Color color;
	int intensity;
	char type[4];
} Light;

float getLightIntensity(Vector3 L, Vector3 normal);
float getLightIntensity2(Ray ray, Vector3 normale);
#endif