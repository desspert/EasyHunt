#pragma once
#include"../../UIBase.h"

class ScrollUI : public UIBase
{
private:
	std::vector<EasingBuf> ease_collision_buf;
public:
	ScrollUI(des::Vec2f _pos, des::Vec2f _size, des::Vec4d _color) :UIBase(_pos, _size, _color)
	{
		own_ui = UITYPE::ScrollUI;
	};

	void animation();
	void update();


	bool collisionToUI(des::Vec2f _pos);
	bool collisionToUI(des::Vec2f _pos, des::Vec2f _size);


	void EaseCollisionApply(std::string start, float end[4], std::function<float(float, float, float)> ease, float time);
	void EaseCollisionUpdate();
};