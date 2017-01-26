#pragma once
#include "cinder/app/App.h"
class ObjectBase {
public:
	ObjectBase(const ci::vec2& pos, const ci::vec2& size) :pos(pos), size(size) {
	}
	~ObjectBase() {}
	ci::vec2 pos;
	ci::vec2 size;
	
	ci::vec2& getPos() {
		return pos;
	}
	const ci::vec2& getSize() {
		return size;
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