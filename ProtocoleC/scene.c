#include "header.h"
#include "scene.h"
#include "mathC.h"

void debugScene(Scene scene) {
	printf("\n-------------------\n");
	printf("Camera position: (%d;%d;%d)\n", scene.camera.position.x, scene.camera.position.y, scene.camera.position.z);
	printf("Resolution: %dx%d\n", scene.camera.screenWidth, scene.camera.screenHeight);

	for (int i = 0; i < scene.objectsCount; i++) {
		Vector3 pos = scene.object[i].position;
		printf("Object%d position: (%d;%d;%d)\n", i + 1, pos.x, pos.y, pos.z);
		printf("Object type: %s.\n", getObjectType(scene.object[i].type));
	}
	printf("-------------------\n\n");
}