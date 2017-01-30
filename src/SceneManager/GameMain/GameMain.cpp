#include "GameMain.h"

void GameMain::update(const float& delta_time)
{
	ui.update(delta_time);
	player->update(delta_time);
	enemy->update(delta_time);
	ANIMATION.update();
	player->attack(objects);
}

void GameMain::draw()
{
	ui.draw();
	player->draw(enemy);
	enemy->draw();
	ANIMATION.draw();
}

void GameMain::setup()
{
	SE.registerFilePlayerNode("bgm", "Music/Decisive_Battle.mp3");
	SE.find("bgm")->setGain(0.3f);
	SE.find("bgm")->start();
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

