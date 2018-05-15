#include "color.h"

Color AddColor(Color a, Color b) {
	Color color;
	color.r = minValue(a.r + b.r, 255);
	color.g = minValue(a.g + b.g, 255);
	color.b = minValue(a.b + b.b, 255);

	return color;
}