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

Vector3 plan(Vector3 vect, Vector3 pixel, Vector3 v1, Vector3 v2, Vector3 v3){
	Vector3 inter;
	int x,y,z;
	int a = (v2.y - v1.y)*(v3.z - v1.z)-(v2.z - v1.z)*(v3.y - v1.y);
	int b = (v2.z - v1.z)*(v3.x - v1.x)-(v2.x - v1.x)*(v3.z - v1.z);
	int c = (v2.x - v1.x)*(v3.y - v1.y)-(v2.y - v1.y)*(v3.x - v1.x);
	int t = (-a * pixel.x - b * pixel.y - c * pixel.z) / (vect.x * a + vect.y * b + vect.y * c);
	
	if (t >= 0){ //il y a intersection entre le rayon et le plan
		
		inter.x = pixel.y + vect.y * t;
		inter.y = pixel.x + vect.x * t;
		inter.z = pixel.z + vect.z * t;
	}
	else{
		inter.x = 0;
		inter.y = 0;
		inter.z = 0;
	}
	return(inter);
}