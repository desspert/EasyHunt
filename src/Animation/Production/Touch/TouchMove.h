#pragma once
#include "../../AnimationBase.h"
#include "../../../dessUI/Easing/Easing.h"
#include "../../../ProductionCamera/ProductionCamera.h"

class TouchMove : public AnimationBase {
protected:
	bool is_animaion;
	float angle;
public:

	TouchMove(const ci::vec2& pos, const float& radius) : AnimationBase(pos) {
		this->size = ci::vec2(radius, radius);
		texture = TEX.get("TouchMove");
		cut = ci::vec2(120, 120);
		seets = ci::vec2(8, 1);
		all_seets = 8;
		animation_count = 0;
		is_animaion = true;
	}
	void setPos(ci::vec2 pos) {
		this->pos = pos;
	}
	void setSize(float size) {
		this->size.y = size;
	}
	void setAngle(float angle) {
		this->angle = angle;
	}
	void setAnimationCount(int count) {
		this->animation_count = count;
	}

	void update(const float& delta_time)override;
	void draw()override;

};