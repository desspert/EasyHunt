#pragma once
#include "../../AnimationBase.h"
#include "../../../dessUI/Easing/Easing.h"
#include "../../../ProductionCamera/ProductionCamera.h"

class Exprode : public AnimationBase {
protected:
	bool is_animaion;
public:

	Exprode(const ci::vec2& pos, const float& radius) : AnimationBase(pos) {
		this->size = ci::vec2(radius, radius);
		TEX.set("Exprode", "Attack/Enemy/Effects/pipo-mapeffect005.png");
		texture = TEX.get("Exprode");
		SE.registerBufferPlayerNode("Exprode", "SE/exprode.mp3");
		cut = ci::vec2(180, 180);
		seets = ci::vec2(10, 1);
		all_seets = 10;
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