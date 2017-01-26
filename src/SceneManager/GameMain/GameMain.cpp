#include "GameMain.h"

void GameMain::update(const int& delta_frame)
{
	ui.update(delta_frame);
	player->update(delta_frame);
	enemy->update(delta_frame);
}

void GameMain::draw()
{
	player->draw();
	enemy->draw();
	ui.draw();
	
}

void GameMain::setup()
{
	ui.setup(dess::SceneName::GAMEMAIN);
	player->setup();
	enemy->setup();
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

