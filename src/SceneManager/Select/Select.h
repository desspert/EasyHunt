#pragma once
#include "../SceneBase.h"
#include "../SceneManager.h"
class Select : public SceneBase
{
public:
	Select() {}
	void update() override {};
	void draw() override {};
	void setup() override {};
	void mouseDown(const ci::app::MouseEvent& event) {}
	void mouseDrag(const ci::app::MouseEvent& event) {}
	void mouseUp(const ci::app::MouseEvent& event) {}
};