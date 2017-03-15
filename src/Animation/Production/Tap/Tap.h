#pragma once
#include "../../AnimationBase.h"
#include "../../../dessUI/Easing/Easing.h"
#include "../../../ProductionCamera/ProductionCamera.h"

class Tap : public AnimationBase {
protected:
	bool is_animaion;
public:

	Tap(const ci::vec2& pos, const float& radius) : AnimationBase(pos) {
		this->size = ci::vec2(radius, radius);
		texture = TEX.get("Tap");
		cut = ci::vec2(120, 120);
		seets = ci::vec2(8, 1);
		all_seets = 8;
		animation_count = 0;
		is_animaion = true;
	}


	void update(const float& delta_time)override;
	void draw()override;

};