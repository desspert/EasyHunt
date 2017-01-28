#pragma once
#include "cinder/app/App.h"
#include "cinder/Camera.h"
#define CAMERA ProductionCamera::get()
class ProductionCamera {
	ci::CameraPersp camera;
	std::shared_ptr<ci::vec2*> camera_pos;
	float camera_z;
	ci::vec2 camera_size;
public:
	
	ProductionCamera(){
		camera_size = ci::vec2(0);
	}
	~ProductionCamera() {
		
	}
	static ProductionCamera& get() {
		static ProductionCamera in;
		return in;
	}

	const ci::CameraPersp& getCamera() {
		return camera;
	}
	void followingCamera(ci::vec2* pos, const ci::vec2& size) {
		camera_pos = std::make_shared<ci::vec2*>(pos);
		camera_size = size;
	}
	

	void shakeCamera(const float& scatter, const float& seconds);
	void setup();

	void update(const float& delta_time);
};