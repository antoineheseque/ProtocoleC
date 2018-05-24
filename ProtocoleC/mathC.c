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

double minValue(double a, double b) {
	if (a > b)
		return b;
	return a;
}

double maxValue(double a, double b) {
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

Vector3 MultiplyVector(Vector3 a, double val) {
	Vector3 vector;
	vector.x = a.x*val;
	vector.y = a.y*val;
	vector.z = a.z*val;
	return vector;
}

Vector3 InvertVector(Vector3 vec) {
	Vector3 vector;
	vector.x = -vec.x;
	vector.y = -vec.y;
	vector.z = -vec.z;
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

/*void multVecMatrix(Vector3 src, Vector3 &dst){

	a = src[0] * x[0][0] + src[1] * x[1][0] + src[2] * x[2][0] + x[3][0];
	b = src[0] * x[0][1] + src[1] * x[1][1] + src[2] * x[2][1] + x[3][1];
	c = src[0] * x[0][2] + src[1] * x[1][2] + src[2] * x[2][2] + x[3][2];
	w = src[0] * x[0][3] + src[1] * x[1][3] + src[2] * x[2][3] + x[3][3];

	dst.x = a / w;
	dst.y = b / w;
	dst.z = c / w;
}*/

/*Vector3 multVecMatrix(Vector3 vec){
	S a, b, c, w;

	a = src[0] * x[0][0] + src[1] * x[1][0] + src[2] * x[2][0] + x[3][0];
	b = src[0] * x[0][1] + src[1] * x[1][1] + src[2] * x[2][1] + x[3][1];
	c = src[0] * x[0][2] + src[1] * x[1][2] + src[2] * x[2][2] + x[3][2];
	w = src[0] * x[0][3] + src[1] * x[1][3] + src[2] * x[2][3] + x[3][3];

	dst.x = a / w;
	dst.y = b / w;
	dst.z = c / w;
}*/