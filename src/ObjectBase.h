#pragma once
#include "cinder/app/App.h"
#include "dessUI/Easing/Easing.h"
#include "HPGauge/HPGauge.h"
#include "dessUI/Texture.h"
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
	HPGauge gauge;
	ci::vec2 pos;
	ci::vec2 size;
	ci::vec4 color;
	ci::gl::TextureRef	texture;
	float radius;
	int hp;
	int hp_max;
	bool is_dead;
	float dead_count;
	bool is_active;
public:
	
	ObjectBase(const ci::vec2& pos, const ci::vec2& size)
		:pos(pos), size(size), radius(size.x / 2),
		color(ci::vec4(1,1,1,1)), is_dead(false),is_active(true),dead_count(0){
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
	const bool& isActive() {
		return is_active;
	}

	virtual void damage(const int& damage) {

		if (c_Easing::isEnd(color.b)) {
			c_Easing::apply(color.g, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.b, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.g, 1, EasingFunction::Linear, 4);
			c_Easing::apply(color.b, 1, EasingFunction::Linear, 4);
			c_Easing::apply(pos.x, pos.x +5, EasingFunction::BounceInOut, 1);
			c_Easing::apply(pos.x, pos.x - 5, EasingFunction::BounceInOut, 1);
		}
		else {
			c_Easing::clear(color.g);
			c_Easing::clear(color.b);
			c_Easing::apply(color.g, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.b, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.g, 1, EasingFunction::Linear, 4);
			c_Easing::apply(color.b, 1, EasingFunction::Linear, 4);
			c_Easing::apply(pos.x, pos.x +5, EasingFunction::BounceInOut, 1);
			c_Easing::apply(pos.x, pos.x -5, EasingFunction::BounceInOut, 1);
		}
		
		hp -= damage;
	
	}
	virtual void changeHP(const float& delta_time) {
		gauge.update(delta_time);
		gauge.changeGauge(hp, hp_max);
		if (gauge.getMin()) {

			is_dead = true;
		}
	}
	
	void setPos(const ci::vec2& pos) {
		this->pos = pos;
	}

	void setSize(const ci::vec2& size) {
		this->size = size;
	}
	virtual void attackPlayer(std::shared_ptr<ObjectBase>& player) {};
	virtual void update(const float& delta_time) = 0;
	virtual void draw() = 0;
	virtual void setup() = 0;
};