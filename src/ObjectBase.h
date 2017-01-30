#pragma once
#include "cinder/app/App.h"
#include "dessUI/Easing/Easing.h"
static bool CollisionCircleToCircle(const ci::vec2& center1, const float& r1, const ci::vec2& center2, const float& r2) {
	float x = (center1.x - center2.x)*(center1.x - center2.x);
	float y = (center1.y - center2.y)*(center1.y - center2.y);
	float r = (r1 + r2) * (r1 + r2);
	if (x + y <= r) {
		return true;
	}
	return false;
}

static ci::vec2 returnCircleToCircle(const ci::vec2& center1, const ci::vec2& center2, const float& r2) {
	ci::vec2 buf =  center2 - center1;
	
	return buf;
}

class ObjectBase {
protected:
	ci::vec2 pos;
	ci::vec2 size;
	ci::vec4 color;
	float radius;
	int hp;
	bool is_dead;
	bool is_active;
public:
	
	ObjectBase(const ci::vec2& pos, const ci::vec2& size) 
		:pos(pos), size(size), radius(size.x / 2),
		color(ci::vec4(1,1,1,1)), is_dead(false),is_active(true){
		
	}
	~ObjectBase() {}


	const ci::vec2& getPos() {
		return pos;
	}
	ci::vec2& getPPos() {
		return pos;
	}
	const ci::vec2& getSize() {
		return size;
	}
	ci::vec2& getPSize() {
		return size;
	}
	const float& getRradius() {
		return radius;
	}
	const ci::vec2& getCenter() {
		return pos + ci::vec2(size.x / 2, size.y / 2);
	}

	void damage(const int& damage) {
		if (c_Easing::isEnd(color.b)) {
			c_Easing::apply(color.g, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.b, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.g, 1, EasingFunction::Linear, 4);
			c_Easing::apply(color.b, 1, EasingFunction::Linear, 4);
		}
		else {
			c_Easing::clear(color.g);
			c_Easing::clear(color.b);
			c_Easing::apply(color.g, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.b, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.g, 1, EasingFunction::Linear, 4);
			c_Easing::apply(color.b, 1, EasingFunction::Linear, 4);
		}
		
		hp -= damage;
	}

	void setPos(const ci::vec2& pos) {
		this->pos = pos;
	}

	void setSize(const ci::vec2& size) {
		this->size = size;
	}
};