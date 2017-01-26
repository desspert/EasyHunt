#pragma once
#include "cinder/app/App.h"


class ObjectBase {
protected:
	ci::vec2 pos;
	ci::vec2 size;
	float radius;
public:
	ObjectBase(const ci::vec2& pos, const ci::vec2& size) :pos(pos), size(size),radius(size.x/2) {
		
	}
	~ObjectBase() {}
	
	
	ci::vec2& getPos() {
		return pos;
	}
	ci::vec2& getSize() {
		return size;
	}

	ci::vec2& getCenter() {
		return pos + ci::vec2(size.x / 2, size.y / 2);
	}
	void setPos(const ci::vec2& pos) {
		this->pos = pos;
	}

	void setSize(const ci::vec2& size) {
		this->size = size;
	}
};