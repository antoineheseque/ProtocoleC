#include <math.h>
#include "objects.h"
#include "ray.h"

char * getObjectType(ObjectType type) {
	switch (type) {
		case Sphere:
			return "Sphere";
			break;
		case Cube:
			return "Cube";
			break;
		case Plan:
			return "Plan";
			break;
		default:
			return "unknown";
			break;
	}
}

Vector3 CollideWithPlan(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3){
	Vector3 inter;
	int x,y,z;
	int a = (p2.y - p1.y)*(p3.z - p1.z)-(p2.z - p1.z)*(p3.y - p1.y);
	int b = (p2.z - p1.z)*(p3.x - p1.x)-(p2.x - p1.x)*(p3.z - p1.z);
	int c = (p2.x - p1.x)*(p3.y - p1.y)-(p2.y - p1.y)*(p3.x - p1.x);
	int t = (-a * ray.position.x - b * ray.position.y - c * ray.position.z) / (ray.direction.x * a + ray.direction.y * b + ray.direction.y * c);
	
	if (t >= 0){ //il y a intersection entre le rayon et le plan
		
		inter.x = ray.position.y + ray.direction.y * t;
		inter.y = ray.position.x + ray.direction.x * t;
		inter.z = ray.position.z + ray.direction.z * t;
	}
	else{
		inter.empty = 1;
	}
	return(inter);
}

Vector3 CollideWithSphere(Ray ray, Vector3 orig, int radius){
	Vector3 inter;
	int x, y, z;
	int a = pow(ray.direction.x, 2) + pow(ray.direction.y, 2) + pow(ray.direction.z, 2);
	int b = (2 * ray.position.x * ray.direction.x) - (2 * orig.x * ray.direction.x) + (2 * ray.position.y * ray.direction.y) - (2 * orig.y * ray.direction.y) + (2 * ray.position.z * ray.direction.z);
	int c = pow(ray.position.x,2) + pow(orig.x,2) - (ray.position.x * orig.x) + pow(orig.y,2) - (2 * ray.position.y * orig.y) + pow(ray.position.z,2) + pow(orig.z,2) - (2 * ray.position.z * orig.z) - pow(radius,2);

	int delta = pow(b,2) - 4 * a * c;

	if (delta >= 0){ //il y a intersection entre le rayon et le plan
		
		int t1, t2;
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);

		if (t1 >= 0 && t2 >= 0){
			/*inter1.x = pt.x + vect.x * t1;
			inter1.y = pt.y + vect.y * t1;
			inter1.z = pt.z + vect.z * t1;

			inter2.x = pt.x + vect.x * t2;
			inter2.y = pt.y + vect.y * t2;
			inter2.z = pt.z + vect.z * t2;*/
		}
		if (t1 < 0){
			inter.x = ray.position.x + ray.direction.x * t2;
			inter.y = ray.position.y + ray.direction.y * t2;
			inter.z = ray.position.z + ray.direction.z * t2;
		}
		if (t2 < 0){
			inter.x = ray.position.x + ray.direction.x * t1;
			inter.y = ray.position.y + ray.direction.y * t1;
			inter.z = ray.position.z + ray.direction.z * t1;
		}
	}

	else{
		inter.empty = 1;
	}

	return inter;
}