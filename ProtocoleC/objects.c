#ifndef MY_HEADER_FILE_
#define MY_HEADER_FILE_
#include "structs.h"
#endif

char * getObjectType(ObjectType type) {
	switch (type) {
		case Sphere:
			return "Sphere";
			break;
		case Cube:
			return "Cube";
	}
}