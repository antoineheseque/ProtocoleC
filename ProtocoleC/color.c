#include "color.h"
#include "mathC.h"

Color ApplyLightEffect(Color c, float intensity) {
	Color color;

	color.r = minValue(c.r * intensity, 255);
	color.g = minValue(c.g  * intensity, 255);
	color.b = minValue(c.b * intensity, 255);

	return color;
}

Color AddColor(Color a, int b) {
	Color color;

	color.r = minValue(a.r + b, 255);
	color.g = minValue(a.g + b, 255);
	color.b = minValue(a.b + b, 255);

	return color;
}