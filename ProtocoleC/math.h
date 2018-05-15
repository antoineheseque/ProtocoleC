#pragma once

typedef struct vector3 {
	float x;
	float y;
	float z;
} Vector3;

int minValue(int a, int b);
int maxValue(int a, int b);
Vector3 AddVector(Vector3 a, Vector3 b);
Vector3 SubVector(Vector3 a, Vector3 b);
Vector3 ProductVector(Vector3 a, Vector3 b);
int ScalarVector(Vector3 a, Vector3 b);
