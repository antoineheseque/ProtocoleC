#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "objects.h"
#include "ray.h"

Vector3 checkPolygone(Ray ray, int nbPts, Vector3 * pts){
	Vector3 inter;
	if(nbPts == 3){
		inter = intersect(ray, pts[0], pts[1], pts[2]);
		if(inter.empty == 0){
			return inter;
		}
	}
	else if(nbPts == 4){
		inter = intersect(ray, pts[0], pts[1], pts[2]);
		if(inter.empty == 0){
			return inter;
		}
		inter = intersect(ray, pts[0], pts[2], pts[3]);
		if(inter.empty == 0){
			return inter;
		}
	}
	else if(nbPts == 5){
		inter = intersect(ray, pts[0], pts[1], pts[2]);
		if(inter.empty == 0){
			return inter;
		}
		inter = intersect(ray, pts[0], pts[2], pts[4]);
		if(inter.empty == 0){
			return inter;
		}
		inter = intersect(ray, pts[2], pts[3], pts[4]);
		if(inter.empty == 0){
			return inter;
		}
	}
	return inter;
}

Vector3 CollideWithPlan(Ray ray, Vector3 normale, Vector3 center, Vector3 size) {
	Vector3 inter = { 0,0,0,1 };
	//ray.position = normalizeVector(ray.position);
	normale = normalizeVector(normale);
	double d = ScalarVector(normale, ray.direction);
	if (fabs(d) > 0.0001) {
		Vector3 vec = SubVector(center, ray.position);
		double t = ScalarVector(vec, normale) / d;
		//printf("%.2f\n", t);
		if (t >= 0) { //il y a intersection entre le rayon et le plan
			inter.x = ray.position.x + ray.direction.x * t;
			inter.y = ray.position.y + ray.direction.y * t;
			inter.z = ray.position.z + ray.direction.z * t;
			//printf("%.2f %.2f %.2f \n", inter.x, inter.y, inter.z);

			Vector3 diff = SubVector(center, inter);
			//if ((diff.x <= -(size.x / 2) || diff.x >= (size.x / 2))
				//&& (diff.z <= -(size.z / 2) || diff.z >= (size.z / 2))) {
				inter.empty = 0;
			//}
		}
	}
	//printf("%.2f \n", d);


	return(inter);
}

/*Vector3 CollideWithPlan(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3){
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
}*/

Vector3 CollideWithSphere(Ray ray, Vector3 orig, int radius){
	Vector3 inter = { 0,0,0,1 };

	Vector3 m = SubVector(ray.position,orig);
	double b = ScalarVector(m, ray.direction);
	double c = ScalarVector(m, m) - radius * radius;

	if (c > 0.0 && b > 0.0)
		return inter;

	float discr = b * b - c;
	if (discr < 0.0f)
		return inter;

	double t = -b - sqrt(discr);

	inter.x = ray.position.x + ray.direction.x * t;
	inter.y = ray.position.y + ray.direction.y * t;
	inter.z = ray.position.z + ray.direction.z * t;
	inter.empty = 0;
	return inter;
}

/*int coplanar(Vector3 a, Vector3 b, Vector3 c){
	int result;

	result = (a.x * b.y * c.z) + (b.x * c.y * a.z) + (c.x * a.y * b.z) - (b.x * a.y * c.x) - (a.x * c.y * b.z) - (c.x * b.y * a.z);

	if(result = 0){
		return 1;
	}
	else{
		return 0;
	}
}*/
