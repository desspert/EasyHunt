#pragma once
#include "../../AnimationBase.h"
#include "../../../dessUI/Easing/Easing.h"


class PlayerSpawn : public AnimationBase {
protected:
	bool is_animaion;
public:

	PlayerSpawn(const ci::vec2& pos, const float& radius) : AnimationBase(pos) {
		this->size = ci::vec2(radius * 5, radius * 5);
		texture = TEX.get("PlayerSpawn");
		cut = ci::vec2(192, 192);
		seets = ci::vec2(5, 3);
		all_seets = 15;
		animation_count = 0;
		is_animaion = true;
	}


	void update(const float& delta_time)override;
	void draw()override;

};