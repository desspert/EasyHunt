#pragma once
#include "../ObjectBase.h"
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include <cinder/gl/gl.h>
class Enemy : public ObjectBase {
protected:
	int hp;
	int attack;
	ci::gl::TextureRef	texture;
public:
	Enemy(const ci::vec2& pos, const ci::vec2& size,
		const int& hp, const int& attack) : ObjectBase(pos, size) {
		this->hp = hp;
		this->attack = attack;
	}
	virtual void damage(const int damage) {}
	virtual void setup();
	virtual void update(const float& delta_time);
	virtual void draw();
};