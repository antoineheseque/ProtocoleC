#include <math.h>
#include "objects.h"
#include "ray.h"

Vector3 CollideWithPlan(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3){
	Vector3 inter;
	int x,y,z;
	int a = (p2.y - p1.y)*(p3.z - p1.z)-(p2.z - p1.z)*(p3.y - p1.y);
	int b = (p2.z - p1.z)*(p3.x - p1.x)-(p2.x - p1.x)*(p3.z - p1.z);
	int c = (p2.x - p1.x)*(p3.y - p1.y)-(p2.y - p1.y)*(p3.x - p1.x);
	int t = (-a * ray.position.x - b * ray.position.y - c * ray.position.z) / (ray.direction.x * a + ray.direction.y * b + ray.direction.y * c);
	
	if (t >= 0){ //il y a intersection entre le rayon et le plan
		printf("INTERSECTION PLAN DETECTEE");
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
	/*Vector3 L;
	L = SubVector(orig, ray.position);
	Vector3 zero = { 0,0,0,1 };
	Vector3 zero2 = { 0,0,0,0 };
	double tca = ScalarVector(L, ray.direction);
	//printf("%f\n", tca);
	//printf("%.10f %.10f %.10f\n", L.x, L.y, L.z);
	if (tca < 0)
		return zero;
	double d = sqrt(DistVector(orig, ray.position) * DistVector(orig, ray.position) - (tca * tca));
	if (d < 0)
		return zero;
	double thc = sqrt(radius * radius - d * d);
	//printf("%f\n", thc);
	double t0 = tca - thc;
	double t1 = tca + thc;

	Vector3 temp;
	temp.x = ray.position.x + t0 * ray.direction.x;
	temp.y = ray.position.y + t0 * ray.direction.y;
	temp.z = ray.position.z + t0 * ray.direction.z;
	Vector3 inter1 = AddVector(ray.position, temp);

	temp.x = ray.position.x + t1 * ray.direction.x;
	temp.y = ray.position.y + t1 * ray.direction.y;
	temp.z = ray.position.z + t1 * ray.direction.z;
	Vector3 inter2 = AddVector(ray.position, temp);
	printf("%.10f %.10f %.10f", temp.x, temp.y, temp.z);
	if (DistVector(inter1, ray.position) > DistVector(inter2, ray.position))
	{
		if (DistVector(inter2, ray.position) < 0)
			return inter1;
		else {
			if (DistVector(inter1, ray.position) < 0)
				return zero;
			else
				return inter2;
		}
			
	}

	else
		return inter1;*/
	Vector3 inter;
	inter.empty = 0;
	/*
	double a = pow(ray.direction.x, 2) + pow(ray.direction.y, 2) + pow(ray.direction.z, 2);
	double b = (2 * ray.position.x * ray.direction.x) - (2 * orig.x * ray.direction.x) + (2 * ray.position.y * ray.direction.y) - (2 * orig.y * ray.direction.y) + (2 * ray.position.z * ray.direction.z);
	double c = pow(ray.position.x,2) + pow(orig.x,2) - (ray.position.x * orig.x) + pow(orig.y,2) - (2 * ray.position.y * orig.y) + pow(ray.position.z,2) + pow(orig.z,2) - (2 * ray.position.z * orig.z) - pow(radius,2);
	*/

	double a = 1; // Ray dir normalized
	double val = LengthVector(SubVector(ray.position, orig));
	double b = 2 * LengthVector(ray.direction) * val;
	double c = pow(abs(val),2) - radius * radius;

	//printf("%.10f %.10f %.10f\n", a,b,c);

	double delta = pow(b,2) - 4 * a * c;

	if (delta > 0){ //il y a intersection entre le rayon et le plan
		//
		double t1, t2;
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);

		//printf("%.20f %.20f \n", t1, t2);

		if (t1 == t2) { // Seulement 1 point
			inter.x = ray.direction.x * t1 - ray.position.x;
			inter.y = ray.direction.y * t1 - ray.position.y;
			inter.z = ray.direction.z * t1 - ray.position.z;
		}

		else if (t1 > t2 && t2 > 0) {
			inter.x = ray.direction.x * t2 - ray.position.x;
			inter.y = ray.direction.y * t2 - ray.position.y;
			inter.z = ray.direction.z * t2 - ray.position.z;
		}

		else if (t1 < t2 && t1 > 0) {
			inter.x = ray.direction.x * t1 - ray.position.x;
			inter.y = ray.direction.y * t1 - ray.position.y;
			inter.z = ray.direction.z * t1 - ray.position.z;
		}
		else {
			inter.empty = 1;
		}

		/*if (t1 >= 0 && t2 >= 0){
			Vector3 vec1;
			vec1.x = ray.direction.x * t1 - ray.position.x;
			vec1.y = ray.direction.y * t1 - ray.position.y;
			vec1.z = ray.direction.z * t1 - ray.position.z;

			Vector3 vec2;
			vec2.x = ray.direction.x * t2 - ray.position.x;
			vec2.y = ray.direction.y * t2 - ray.position.y;
			vec2.z = ray.direction.z * t2 - ray.position.z;

			if (DistVector(ray.position, vec1) > DistVector(ray.position, vec2))
				return vec2;
			else
				return vec1;
		}
		if (t1 > 0) {
			inter.x = ray.direction.x * t1 - ray.position.x;
			inter.y = ray.direction.y * t1 - ray.position.y;
			inter.z = ray.direction.z * t1 - ray.position.z;
		}
		if (t2 > 0){
			inter.x = ray.direction.x * t2 - ray.position.x;
			inter.y = ray.direction.y * t2 - ray.position.y;
			inter.z = ray.direction.z * t2 - ray.position.z;
		}*/
	}
	else if (delta == 0) {
		double t;
			t = -b / (2 * a);
			Vector3 vec1;
			vec1.x = ray.position.x + ray.direction.x * t;
			inter = vec1;
	}
	else{
		inter.empty = 1;
	}

	return inter;
}