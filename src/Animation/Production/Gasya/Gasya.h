#pragma once
#include "../../AnimationBase.h"
#include "../../../dessUI/Easing/Easing.h"

class Gasya : public AnimationBase {
protected:
	bool is_animaion;
public:

	Gasya(const ci::vec2& pos, const ci::vec2& size) : AnimationBase(pos) {
		this->size = size;
		texture = TEX.get("Gasya");
		cut = ci::vec2(800, 600);
		seets = ci::vec2(10, 2);
		all_seets = 80;
		animation_count = 0;
		is_animaion = true;
	}


	void update(const float& delta_time)override;
	void draw()override;

};