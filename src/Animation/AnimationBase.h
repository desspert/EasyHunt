#pragma once
#include <iostream>
#include "../ObjectBase.h"
#include <cinder/app/App.h>
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include <cinder/gl/gl.h>

class AnimationBase {
protected:
	bool is_active;
	ci::vec2 pos;
	ci::vec2 size;
	ci::vec2 cut;
	ci::vec2 seets;
	float radius;
	int all_seets;
	ci::gl::TextureRef	texture;
	int animation_count;
public:
	AnimationBase(ci::gl::TextureRef copy_tex) : texture(copy_tex) {

	}
	AnimationBase(ci::gl::TextureRef copy_tex, const ci::vec2& pos) : texture(copy_tex), pos(pos) {

	}
	const bool& isActive() {
		return is_active;
	}
	virtual void update() = 0;
	virtual void draw() = 0;
};