#pragma once
#include "cinder/app/App.h"
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
	ci::vec2 buf = center2 - center1 ;
	
	return ci::vec2(buf.x/r2 ,buf.y/r2 ) ;
}

class ObjectBase {
protected:
	ci::vec2 pos;
	ci::vec2 size;
	float radius;
	
public:
	
	ObjectBase(const ci::vec2& pos, const ci::vec2& size) :pos(pos), size(size), radius(size.x / 2) {
		
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
	void setPos(const ci::vec2& pos) {
		this->pos = pos;
	}

	void setSize(const ci::vec2& size) {
		this->size = size;
	}
};