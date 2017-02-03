#pragma once
#include <iostream>
#include "../ObjectBase.h"
#include <cinder/app/App.h>
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include <cinder/gl/gl.h>
#include "../dessUI/Texture.h"
#include "../SoundManager.h"

class AnimationBase {
protected:
	bool is_active;
	ci::vec2 pos;
	ci::vec2 size;
	ci::vec2 cut;
	ci::vec2 seets;
	float radius;
	int all_seets;
	ci::gl::TextureRef texture;
	int animation_count;
	float active_time;
public:
	AnimationBase(){

	}
	AnimationBase(const ci::vec2& pos) :pos(pos), is_active(true) {

	}
	const bool& isActive() {
		return is_active;
	}
	virtual void update(const float& delta_time) = 0;
	virtual void draw() = 0;
};