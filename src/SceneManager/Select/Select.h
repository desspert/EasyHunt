#pragma once
#include "../SceneBase.h"
#include "../SceneManager.h"
class Select : public SceneBase
{
public:
	Select() {}
	void update(const float& delta_time) override {};
	void draw() override {};
	void setup() override {};
	void mouseDown(const ci::app::MouseEvent& event) {}
	void mouseDrag(const ci::app::MouseEvent& event) {}
	void mouseUp(const ci::app::MouseEvent& event) {}
};