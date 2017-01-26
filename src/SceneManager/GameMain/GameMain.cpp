#include "GameMain.h"

void GameMain::update()
{
	ui.update();
	player->update();
}

void GameMain::draw()
{
	ui.draw();
	player->draw();
}

void GameMain::setup()
{
	ui.setup(dess::SceneName::GAMEMAIN);
	ui.ui_data[u8"”wŒi"]->Active();
	ui.ui_data[u8"‚í‚Á‚Ó‚§‚¢"]->Active();

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

