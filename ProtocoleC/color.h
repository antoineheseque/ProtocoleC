#ifndef DEF_COLOR
#define DEF_COLOR

#include "mathC.h"

typedef struct color {
	int r, g, b;
} Color;

Color ApplyLightEffect(Color c, float intensity);
Color AddColorInt(Color a, int b);
Color AddColor(Color a, Color b);
Color RemColor(Color a, Color b);
Color getNormalShadow(Color defaultC, Vector3 dir, Vector3 normale);
Color MultiplyColor(Color a, double b);
#endif