#pragma once
#include "../UIPlate.h"

class GameMainUI : public UIPlate
{
private :
	int max_hp;
public:
	void setMaxHP(int hp) {
		max_hp = hp;
	}
	void setHP(int hp) {
		ui_data["HPGauge"]->gaugeChangeX(hp, max_hp);
	}

	void setup(const dess::SceneName& name) override;
	void update(const float& delta_time) override;
	void draw() override;
	void mouseDown(ci::app::MouseEvent event);
	void mouseDrag(ci::app::MouseEvent event);
	void mouseUp(ci::app::MouseEvent event);
};