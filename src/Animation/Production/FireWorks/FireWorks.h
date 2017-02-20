#pragma once
#include "../../AnimationBase.h"
#include "../../../dessUI/Easing/Easing.h"
#include "../../../ProductionCamera/ProductionCamera.h"

class FireWorks : public AnimationBase {
protected:
	bool is_animaion; 
public:

	FireWorks(const ci::vec2& pos, const float& radius) : AnimationBase(pos) {
		this->size = ci::vec2(radius, radius);
		texture = TEX.get("FireWorks");
		cut = ci::vec2(256, 256);
		seets = ci::vec2(10, 6);
		all_seets = 60;
		animation_count = 0;
		is_animaion = true;
	}


	void update(const float& delta_time)override;
	void draw()override;

};