#include "GameMain.h"
#include "GameMainProductions.cpp"
GameMain::GameMain() : _m(std::make_shared<_coroutine>(*this)) {
	is_clear = false;
	is_start = true;
	pause = false;
	TEX.set("Blade", "attack.png");
	TEX.set("Slashing", "Attack/attack.png");
	TEX.set("player", "Characters/Star3/Blaze/murayakimen02-mv.png");
	TEX.set("Dead", "Enemy/dead.png");
	TEX.set("Spawn", "Enemy/spawn.png");
	TEX.set("FireWorks", "MapData/MapTextures/firework.png");
	SE.registerBufferPlayerNode("dead", "SE/sen_ge_iron_syoutotu04.mp3");
	SE.registerBufferPlayerNode("Spawn", "SE/magic-gravity1.mp3");
	SE.registerBufferPlayerNode("Crear", "SE/crear.mp3");
	SE.registerBufferPlayerNode("FireWorks1", "SE/firework1.mp3");
	SE.registerBufferPlayerNode("FireWorks2", "SE/firework1.mp3");
	SE.registerBufferPlayerNode("FireWorks3", "SE/firework1.mp3");
	player = std::make_shared<Player>(ci::vec2(700, 700), ci::vec2(100, 100), TEX.get("player"), Status(1000, 10, 300, ""), Weapon(10, 0.2f, 300, ""));
	ui.setMaxHP(player->getHP());

	CAMERA.followingCamera(&player->getPPos(), ci::vec2(0));
}



void GameMain::update(const float& delta_time)
{
	ANIMATION.update(delta_time);
	_m->update(delta_time);


	if (pause) return;


	ui.setHP(player->getHP());
	ui.update(delta_time);
	player->update(delta_time);
	for (auto it : objects) {
		it->update(delta_time);
		it->attackPlayer(player);
	}
	
	player->attack(objects);

	for (auto it = objects.begin(); it != objects.end(); it++) {
		if (!(*it)->isActive()) {
			objects.erase(it);
			break;
		}
	}
	is_clear = map.isClear(objects);
}

void GameMain::draw()
{
	
	map.draw();
	player->draw();
	for (auto it : objects) {
		it->draw();
	}
	ANIMATION.draw();
	
	ci::gl::pushModelView();
	ci::gl::translate(ci::vec3(CAMERA.getPos().x - camera_::WIDTH/2, CAMERA.getPos().y - camera_::HEIGHT/2, -1500));
	ui.draw();
	ci::gl::popModelView();
}

void GameMain::setup()
{
	SE.registerFilePlayerNode("bgm", "Music/Decisive_Battle.mp3");
	

	ui.setup(dess::SceneName::GAMEMAIN);
	player->setup();
	ANIMATION.setup();
	map.setup(objects);
	_m->setup();
	for (auto it : objects) {
		it->setup();
	}
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

