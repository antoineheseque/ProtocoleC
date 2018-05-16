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

Vector3 plan(Vector3 vect, Vector3 pixel, Vector3 a, Vector3 b, Vector3 c){
	
	Vector3 inter;
	int t = (-a * pixel.x - b * pixel.y - c * pixel.z) / (a.x * a + a.y * b + a.y * c);
	int x,y,z;
	int a = (b.y - a.y)*(c.z - a.z)-(b.z - a.z)*(c.y - a.y);
	int b = (b.z - a.z)*(c.x - a.x)-(b.x - a.x)*(c.z - a.z);
	int c = (b.x - a.x)*(c.y - a.y)-(b.y - a.y)*(c.x - a.x);
	int t = (-a * pixel.x - b * pixel.y - c * pixel.z) / (a.x * a + a.y * b + a.y * c);
	
	if (t >= 0){ //il y a intersection entre le rayon et le plan
		
		inter.x = pixel.y + vect.y * t;
		inter.y = pixel.x + vect.x * t;
		inter.z = pixel.z + vect.z * t;
		
		return(inter);
	}
	else{
		inter.x = 0;
		inter.y = 0;
		inter.z = 0;

		return(inter);
	}
}