#include "ProductionCamera.h"

void ProductionCamera::followingCamera(const ci::vec2 & obj, const float & seconds)
{
	
}

void ProductionCamera::shakeCamera(const float & scatter, const float & seconds)
{
}

void ProductionCamera::setup(){
	camera_z = -1000.0f;
	camera.setAspectRatio(ci::app::getWindowAspectRatio());
	camera.lookAt(ci::vec3((*camera_pos)->x, (*camera_pos)->y, camera_z), ci::vec3(0), ci::vec3(0, -1, 0));
}

void ProductionCamera::update() {
	camera.lookAt(ci::vec3((*camera_pos)->x, (*camera_pos)->y, camera_z), ci::vec3((*camera_pos)->x, (*camera_pos)->y, 0));
}
