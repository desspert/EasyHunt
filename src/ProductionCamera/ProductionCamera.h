#pragma once
#include "cinder/app/App.h"
#include "cinder/Camera.h"
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include <cinder/gl/gl.h>
#include "../Animation/Production/FireWorks/FireWorks.h"
#define CAMERA ProductionCamera::get()

namespace camera_ {
	enum WINDOW_SIZE {
		WIDTH = 640,
		HEIGHT = 960,
		TEXTURE_WIDTH = 3000,
		TEXTURE_HEIGHT = 4500
	};
}

class ProductionCamera {
	ci::CameraPersp camera;
	ci::vec2 pos;
	ci::vec2 buf_pos;
	std::shared_ptr<ci::vec2*> reference_pos;
	float camera_z;
	ci::vec2 camera_size;
	
	ci::gl::TextureRef fade_tex;
public:
	//画面のフェード値
	ci::vec4 fade_out;


	ProductionCamera(){
		pos = ci::vec2(0);
		buf_pos = ci::vec2(0);
		camera_size = ci::vec2(0);
		fade_out = ci::vec4(0, 0, 0, 0);
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

	
	ci::vec3 getPos() {
		return ci::vec3(pos.x,pos.y,camera_z);
	}
	void setCameraZ(const int& value) {
		if (9000 < (camera_z + value)) return;
		if (500 > (camera_z + value)) return;
		camera_z += value;
	}
	void followingCamera(ci::vec2* pos, const ci::vec2& size) {
		reference_pos = std::make_shared<ci::vec2*>(pos);
		camera_size = size;
	}
	

	void shakeCamera(const float& scatter, const float& seconds);
	void setup();
	void update(const float& delta_time);
	void draw();
};
