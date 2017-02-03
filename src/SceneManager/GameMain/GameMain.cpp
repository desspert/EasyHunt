#include "GameMain.h"

void GameMain::update(const float& delta_time)
{
	ui.update(delta_time);
	player->update(delta_time);
	for (auto it : objects) {
		it->update(delta_time);
		it->attackPlayer(static_cast<std::shared_ptr<ObjectBase>>(player));
	}
	ANIMATION.update(delta_time);
	
	player->attack(objects);

	for (auto it = objects.begin(); it != objects.end(); it++) {
		if (!(*it)->isActive()) {
			objects.erase(it);
			break;
		}
	}
}

void GameMain::draw()
{
	map.draw();
	game_event.draw();
	ui.draw();
	player->draw();
	for (auto it : objects) {
		it->draw();
	}
	ANIMATION.draw();
	
}

void GameMain::setup()
{
	SE.registerFilePlayerNode("bgm", "Music/Decisive_Battle.mp3");
	SE.find("bgm")->setGain(0.3f);
	SE.find("bgm")->start();

	ui.setup(dess::SceneName::GAMEMAIN);
	player->setup();
	for (auto it : objects) {
		it->setup();
	}
	ANIMATION.setup();
	game_event.setup();
	map.setup(objects);
}

void GameMain::mouseDown(const ci::app::MouseEvent & event)
{
	player->mouseDown(event);
	CAMERA.followingCamera(&player->getPPos(), player->getSize());
	
	
}

void GameMain::mouseDrag(const ci::app::MouseEvent & event)
{
	player->mouseDrag(event);
}

void GameMain::mouseUp(const ci::app::MouseEvent & event)
{
	player->mouseUp(event);
	for (auto it : objects) {
		CAMERA.followingCamera(&it->getPPos(), it->getSize());
	}
}

void GameMain::touchesBegan(ci::app::TouchEvent event)
{
	player->touchesBegan(event);
}

void GameMain::touchesMoved(ci::app::TouchEvent event)
{
	player->touchesMoved(event);
}

void GameMain::touchesEnded(ci::app::TouchEvent event)
{
	player->touchesEnded(event);
}

