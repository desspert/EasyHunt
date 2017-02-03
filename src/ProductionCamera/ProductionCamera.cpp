#include "ProductionCamera.h"



void ProductionCamera::shakeCamera(const float & scatter, const float & seconds)
{
}

void ProductionCamera::setup(){
	camera_z = -1000.0f;
	camera.setAspectRatio(ci::app::getWindowAspectRatio());
	camera.lookAt(ci::vec3((*reference_pos)->x + camera_size.x / 2, (*reference_pos)->y + camera_size.y / 2, camera_z), ci::vec3(0), ci::vec3(0, -1, 0));
	camera_z = -1500.0f;
	camera.setFarClip(10000);
}

void ProductionCamera::update(const float& delta_time) {
	buf_pos = ci::vec2((*reference_pos)->x, (*reference_pos)->y) - pos;
	buf_pos *= 0.1f;
	pos += buf_pos;
	camera.lookAt(ci::vec3(pos.x + camera_size.x / 2,
		pos.y + camera_size.y,camera_z),
		ci::vec3(pos.x + camera_size.x / 2,
			pos.y + camera_size.y / 2, 0));
}
