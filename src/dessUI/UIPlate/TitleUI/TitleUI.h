#pragma once
#include "../UIPlate.h"

class TitleUI : public UIPlate
{
public:
	void setup(const dess::SceneName& name) override;
	void update(const float& delta_time) override;
	void draw() override;
	void mouseDown(ci::app::MouseEvent event);
	void mouseDrag(ci::app::MouseEvent event);
	void mouseUp(ci::app::MouseEvent event);
};