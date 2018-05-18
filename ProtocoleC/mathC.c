#include "mathC.h"
#include <math.h>

Vector3 normalizeVector(Vector3 vec)
{
	Vector3 normalized = vec;
	double d = LengthVector(vec);
	normalized.x /= d;
	normalized.y /= d;
	normalized.z /= d;
	return normalized;
}

int minValue(int a, int b) {
	if (a > b)
		return b;
	return a;
}

int maxValue(int a, int b) {
	if (a < b)
		return b;
	return a;
}

Vector3 AddVector(Vector3 a, Vector3 b) {
	Vector3 vector;
	vector.x = a.x + b.x;
	vector.y = a.y + b.y;
	vector.z = a.z + b.z;

	return vector;
}

Vector3 SubVector(Vector3 a, Vector3 b) {
	Vector3 vector;
	vector.x = a.x - b.x;
	vector.y = a.y - b.y;
	vector.z = a.z - b.z;

	return vector;
}

Vector3 ProductVector(Vector3 a, Vector3 b) {
	Vector3 vector;
	vector.x = (a.y*b.z) - (a.z*b.y);
	vector.y = (a.z*b.x) - (a.x*b.z);
	vector.y = (a.x*b.y) - (a.y*b.x);

	return vector;
}

double ScalarVector(Vector3 a, Vector3 b) {
	double scalar;
	scalar = a.x*b.x + a.y*b.y + a.z*b.z;

	return scalar;
}

double LengthVector(Vector3 vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double DistVector(Vector3 a, Vector3 b){

	if (a.empty == 1 || b.empty == 1) // Si le 2eme vecteur est a l'origine 
		return 0.0;

	double distance;
	distance = pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2);
	distance = sqrt(distance);
	return distance;
}
