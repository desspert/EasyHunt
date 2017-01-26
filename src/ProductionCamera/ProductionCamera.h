#pragma once
#include "cinder/app/App.h"
#include "cinder/Camera.h"
#define CAMERA ProductionCamera::get()
class ProductionCamera {
	ci::CameraPersp camera;
	std::shared_ptr<ci::vec2*> camera_pos;
	float camera_z;
public:
	
	ProductionCamera(){
		
		
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
	void setPos(ci::vec2* pos) {
		camera_pos = std::make_shared<ci::vec2*>(pos);
	}
	void followingCamera(const ci::vec2& obj, const float& seconds);

	void shakeCamera(const float& scatter, const float& seconds);
	void setup();

	void update();
};