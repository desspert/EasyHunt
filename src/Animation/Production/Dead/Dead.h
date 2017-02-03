#pragma once
#include "../../AnimationBase.h"
#include "../../../dessUI/Easing/Easing.h"


class Dead : public AnimationBase {
protected:
	//std::map<std::string, SignalType>& signals;
	bool is_animaion;
public:

	Dead(const ci::vec2& pos, const float& radius) : AnimationBase(pos) {
		this->size = ci::vec2(radius*5, radius*3);
		texture = TEX.get("Dead");
		cut = ci::vec2(512, 256);
		seets = ci::vec2(9, 9);
		all_seets = 57;
		animation_count = 0;
		is_animaion = true;
	}
	
	
	void update(const float& delta_time)override;
	void draw()override;

};