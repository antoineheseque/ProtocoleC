#include "objects.h"
#include <math.h>

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

Vector3 plan(Vector3 vect, Vector3 pixel, Vector3 p1, Vector3 p2, Vector3 p3){
	
	Vector3 inter;
	int x,y,z;
	int a = (p2.y - p1.y)*(p3.z - p1.z)-(p2.z - p1.z)*(p3.y - p1.y);
	int b = (p2.z - p1.z)*(p3.x - p1.x)-(p2.x - p1.x)*(p3.z - p1.z);
	int c = (p2.x - p1.x)*(p3.y - p1.y)-(p2.y - p1.y)*(p3.x - p1.x);
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

Vector3 Sphere(Vector3 	vect, Vector3 orig, Vector3 pt, int radius){
	Vector3 inter1;
	Vector3 inter2;
	int x, y, z;
	int a = pow(vect.x) + pow(vect.y) + pow(vect.z);
	int b = (2 * pt.x * vect.x) - (2 * orig.x * vect.x) + (2 * pt.y * vect.y) - (2 * orig.y * vect.y) + (2 * pt.z * vect.z);
	int c = pow(pt.x,2) + pow(orig.x,2) - (pt.x * orig.x) + pow(orig.y,2) - (2 * pt.y * orig.y) + pow(pt.z,2) + pow(orig.z,2) - (2 * pt.z * orig.z) - pow(radius,2);

	int delta = pow(b,2) - 4 * a * c;

	if (delta >= 0){ //il y a intersection entre le rayon et le plan
		
		int t1, t2;
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);

		if (t1 >= 0 && t2 >= 0){
			inter1.x = pt.x + vect.x * t1;
			inter1.y = pt.y + vect.y * t1;
			inter1.z = pt.z + vect.z * t1;

			inter2.x = pt.x + vect.x * t2;
			inter2.y = pt.y + vect.y * t2;
			inter2.z = pt.z + vect.z * t2;

			return(inter1); //Reste a calculer le plus proche
		}
		if (t1 < 0){
			inter.x = pt.x + vect.x * t2;
			inter.y = pt.y + vect.y * t2;
			inter.z = pt.z + vect.z * t2;
		
			return(inter);
		}
		if (t2 < 0){
			inter.x = pt.x + vect.x * t1;
			inter.y = pt.y + vect.y * t1;
			inter.z = pt.z + vect.z * t1;
			
			return(inter);
		}
	}

	else{

	}

}