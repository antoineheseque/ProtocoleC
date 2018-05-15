#ifndef DEF_SCENE
#define DEF_SCENE

typedef struct scene {
	Camera camera;

	int objectsCount;
	Object * object;
} Scene;


void debugScene(Scene scene);

#endif