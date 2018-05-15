#include "objects.h"

char * getObjectType(ObjectType type) {
	switch (type) {
		case Sphere:
			return "Sphere";
			break;
		case Cube:
			return "Cube";
			break;
		default:
			return "unknown";
			break;
	}
}