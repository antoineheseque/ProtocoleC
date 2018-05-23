#ifndef DEF_LIGHT
#define DEF_LIGHT

#include "color.h"

typedef struct light {
  int add;
	Vector3 position;
	Color color;
	int intensity;
} Light;

float getLightIntensity(Vector3 L, Vector3 normal);
#endif