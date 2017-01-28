#include "GameMain.h"

void GameMain::update(const float& delta_time)
{
	ui.update(delta_time);
	player->update(delta_time);
	enemy->update(delta_time);
	ANIMATION.updae();
	player->attack(objects);
}

void GameMain::draw()
{
	//ui.draw();
	enemy->draw();
	player->draw(enemy);
	
	ANIMATION.draw();
}

void GameMain::setup()
{
	ui.setup(dess::SceneName::GAMEMAIN);
	player->setup();
	enemy->setup();
	ANIMATION.setup();
}

void GameMain::mouseDown(const ci::app::MouseEvent & event)
{
	player->mouseDown(event);
}

void GameMain::mouseDrag(const ci::app::MouseEvent & event)
{
	player->mouseDrag(event);
}

void GameMain::mouseUp(const ci::app::MouseEvent & event)
{
	player->mouseUp(event);
}

