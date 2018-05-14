typedef struct vector3 {
	float x;
	float y;
	float z;
} Vector3;

typedef struct camera {
	Vector3 position;
	Vector3 direction;
	int screenWidth;
	int screenHeight;
} Camera;

typedef struct color {
	int r, g, b;
} Color;

typedef enum objectType {
	Sphere,
	Cube
} ObjectType;

typedef struct object {
	Vector3 position;
	Vector3 size;
	ObjectType type;
} Object;

typedef struct scene {
	Camera camera;

	int objectsCount;
	Object object[];
} Scene;
