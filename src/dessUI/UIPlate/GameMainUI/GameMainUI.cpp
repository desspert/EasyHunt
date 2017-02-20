#include "GameMainUI.h"





void GameMainUI::setup(const dess::SceneName & name)
{
	UIPlate::setup(name);
	ui_data["UIBack"]->setActive(true);
	ui_data["HPGauge"]->setActive(true);
	ui_data["Life"]->setActive(true);
	ui_data["Coin"]->setActive(true);
}

void GameMainUI::update(const float& delta_time)
{
	UIPlate::update(delta_time);
}

void GameMainUI::draw()
{
	UIPlate::draw();
}

void GameMainUI::mouseDown(ci::app::MouseEvent event)
{
}

void GameMainUI::mouseDrag(ci::app::MouseEvent event)
{
}

void GameMainUI::mouseUp(ci::app::MouseEvent event)
{
}
