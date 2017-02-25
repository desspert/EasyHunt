#include "GameMain.h"
#include "GameMainProductions.cpp"
GameMain::GameMain() : _m(std::make_shared<GameMainProduction>(*this))
{
	is_clear = false;
	is_start = true;
	pause = false;
	TEX.set("Blade", "attack.png");
	TEX.set("Slashing", "Attack/attack.png");
	TEX.set("Dead", "Enemy/dead.png");
	TEX.set("Spawn", "Enemy/spawn.png");
	TEX.set("FireWorks", "MapData/MapTextures/firework.png");
	SE.registerBufferPlayerNode("dead", "SE/sen_ge_iron_syoutotu04.mp3");
	SE.registerBufferPlayerNode("Spawn", "SE/magic-gravity1.mp3");
	SE.registerBufferPlayerNode("Crear", "SE/crear.mp3");
	SE.registerBufferPlayerNode("FireWorks1", "SE/firework1.mp3");
	SE.registerBufferPlayerNode("FireWorks2", "SE/firework1.mp3");
	SE.registerBufferPlayerNode("FireWorks3", "SE/firework1.mp3");
	
	
}



void GameMain::update(const float& delta_time)
{
	ui.update(delta_time);
	ANIMATION.update(delta_time);
	

	if (!pause) {


		ui.setHP(player->getHP());
		
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
	_m->update(delta_time);
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
	ci::gl::translate(ci::vec3(CAMERA.getPos().x - (camera_::WIDTH / 2), CAMERA.getPos().y - (camera_::HEIGHT / 2), CAMERA.getPos().z + 1500));
	ui.draw();
	ci::gl::popModelView();
}

void GameMain::setup()
{
	SE.registerFilePlayerNode("bgm", "Music/Decisive_Battle.mp3");
	map.setup(objects);
	player = std::make_shared<Player>(map.getPlayerPos(0), PLAYERDATA.getSelectedCharacter());
	ui.setup(dess::SceneName::GAMEMAIN);
	player->setup();
	ui.setMaxHP(player->getHP());
	CAMERA.followingCamera(&player->getPPos(), ci::vec2(0));


	ANIMATION.setup();
	
	
	_m->setup();
	for (auto it : objects) {
		it->setup();
	}
}

void GameMain::mouseDown(const ci::app::MouseEvent & event)
{
	player->mouseDown(event);
	if (event.isControlDown()) {
		CAMERA.setCameraZ(+200);
	}
	if (event.isRightDown()) {
		CAMERA.setCameraZ(-200);
	}
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

