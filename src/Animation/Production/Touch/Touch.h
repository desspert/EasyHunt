#pragma once
#include "../../AnimationBase.h"
#include "../../../dessUI/Easing/Easing.h"
#include "../../../ProductionCamera/ProductionCamera.h"

class Touch : public AnimationBase {
protected:
	bool is_animaion;
public:

	Touch(const ci::vec2& pos, const float& radius) : AnimationBase(pos) {
		this->size = ci::vec2(radius, radius);
		texture = TEX.get("Touch");
		cut = ci::vec2(256, 256);
		seets = ci::vec2(5, 6);
		all_seets = 30;
		animation_count = 0;
		is_animaion = true;
	}
	void setPos(ci::vec2 pos) {
		this->pos = pos;
	}
	void setAnimationCount(int count) {
		this->animation_count = count;
	}

	void update(const float& delta_time)override;
	void draw()override;

};