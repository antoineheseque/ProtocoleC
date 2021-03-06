#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "objects.h"
#include "ray.h"

Vector3 checkPolygone(Ray ray, int nbPts, Vector3 * pts){
	Vector3 inter;
	//si c'est un triangle
	if(nbPts == 3){
		inter = intersect(ray, pts[0], pts[1], pts[2]);
		if(inter.empty == 0){
			return inter;
		}
	}
	//si c'est un quadrilatère
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
	//si c'est un pentagone
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

Vector3 CollideWithGround(Ray ray, Vector3 normale, Vector3 center) {
	Vector3 inter = { 0,0,0,1 };
	normale = normalizeVector(normale);
	double d = ScalarVector(normale, ray.direction);
	if (fabs(d) > 0.0001) {
		Vector3 vec = SubVector(center, ray.position);
		double t = ScalarVector(vec, normale) / d;
		if (t >= 0) { //il y a intersection entre le rayon et le plan
			inter.x = ray.position.x + ray.direction.x * t;
			inter.y = ray.position.y + ray.direction.y * t;
			inter.z = ray.position.z + ray.direction.z * t;

			Vector3 diff = SubVector(center, inter);
				inter.empty = 0;
		}
	}
	return(inter);
}

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

int coplanar(Vector3 a, Vector3 b, Vector3 c){
	int result;

	result = (a.x * b.y * c.z) + (b.x * c.y * a.z) + (c.x * a.y * b.z) - (b.x * a.y * c.x) - (a.x * c.y * b.z) - (c.x * b.y * a.z);

	if(result = 0){
		return 1;
	}
	else{
		return 0;
	}
}

Vector3 intersect(Ray ray, Vector3 v1, Vector3 v2, Vector3 v3){
	Vector3 inter = { 0,0,0,1 };
	double area, area1, area2, area3, areaTot;
	double ab,bc,ca;
	double p, p1, p2, p3;
	double X, Y, Z;
	
	//printf("%.2f %.2f %.2f\n", v1.x, v2.x, v3.x);

	//calcul de l'équation de la droite de la forme ax + by + cz + d = 0
	double a = (v2.y - v1.y)*(v3.z - v1.z)-(v2.z - v1.z)*(v3.y - v1.y);
	double b = (v2.z - v1.z)*(v3.x - v1.x)-(v2.x - v1.x)*(v3.z - v1.z);
	double c = (v2.x - v1.x)*(v3.y - v1.y)-(v2.y - v1.y)*(v3.x - v1.x);
	double d = -(v1.x * a) - (v1.y * b) - (v1.z * c);
	double t = (-a * ray.position.x - b * ray.position.y - c * ray.position.z - d) / (ray.direction.x * a + ray.direction.y * b + ray.direction.y * c);

	if (t >= 0){ //il y a intersection entre le rayon et le plan
		//coordonnées du point d'intersection
		inter.x = ray.position.x + ray.direction.x * t;
		inter.y = ray.position.y + ray.direction.y * t;
		inter.z = ray.position.z + ray.direction.z * t;

		//printf("%.2f %.2f %.2f\n", inter.x, inter.y, inter.z);

		//calcul de la longueur des cotés
		ab = DistVector(v1, v2);
		bc = DistVector(v2, v3);
		ca = DistVector(v3, v1);

		//calcul de l'aire totale du triangle
		area = sqrt( ((ab + bc + ca)/2) * ((-ab + bc + ca)/2) * ((ab - bc + ca)/2) * ((ab + bc - ca)/2) );

		//calcul du demi périmétre
		p = (ab + bc + ca)/2;

		//calcul des normes entre les sommets et le point I
		X = DistVector(v1, inter);
		Y = DistVector(v2, inter);
		Z = DistVector(v3, inter);

		//printf("%.2f %.2f %.2f\n", X, Y, Z);


		//calcul du demi périmétre des sous divisions
		p1 = (X + Y + ab)/2;
		p2 = (Z + Y + bc)/2;
		p3 = (Z + X + ca)/2;

		//calcul des aires des sous divisions
		area1 = sqrt(p1 * (p1 - X) * (p1 - Y) * (p1 - ab));
		area2 = sqrt(p2 * (p2 - Z) * (p2 - Y) * (p2 - bc));
		area3 = sqrt(p3 * (p3 - Z) * (p3 - X) * (p3 - ca));

		//on additionne les aires des 3 sous divisions
		areaTot = area1 + area2 + area3;

		//printf("%.2f %.2f %.2f\n", p1 * (p1 - X) * (p1 - Y) * (p1 - ab), p2 * (p2 - Z) * (p2 - Y) * (p2 - bc), p3 * (p3 - Z) * (p3 - X) * (p3 - ca));

		if (areaTot == area){ //si la somme des aire des 3 sous divisions est égale à l'aire du triangle le point d'intersection est bien dans le triangle
			inter.empty = 0;
			printf("played");
		}
	}

	else{

		//si le t est inférieur à 0 on retourne 1
		inter.empty = 1;
	}
	return inter;
}
