#include "GameMain.h"
#include "GameMainProductions.cpp"
GameMain::GameMain() : _m(std::make_shared<GameMainProduction>(*this))
{
	is_lose = false;
	is_clear = false;
	is_start = true;
	pause = false;
	touch = false;
	boss_end = false;
	tutorial = false;
	pause = true;
	down_pos = ci::vec2(0);
	move_pos = ci::vec2(0);
	TEX.set("Touch", "Player/Touch.png");
	TEX.set("TouchMove", "Player/pipo-btleffect040.png");
	TEX.set("Blade", "attack.png");
	TEX.set("Slashing", "Attack/attack.png");
	TEX.set("Dead", "Enemy/dead.png");
	TEX.set("Spawn", "Enemy/spawn.png");
	TEX.set("PlayerSpawn", "Player/7076601c360c4680bab5ac0a04887263.png");
	TEX.set("FireWorks", "MapData/MapTextures/firework.png");
	TEX.set("FireWorks", "MapData/MapTextures/firework.png");
	SE.registerFilePlayerNode("BossBgm", "Music/The_War.mp3");
	SE.registerBufferPlayerNode("BossAppear", "SE/boss.wav");
	SE.registerBufferPlayerNode("dead", "SE/sen_ge_iron_syoutotu04.mp3");
	SE.registerBufferPlayerNode("Spawn", "SE/magic-gravity1.mp3");
	SE.registerBufferPlayerNode("PlayerSpawn", "SE/player_spawn.mp3");
	SE.registerBufferPlayerNode("Crear", "SE/crear.mp3");
	SE.registerBufferPlayerNode("Lose", "SE/lose.mp3");
	SE.registerBufferPlayerNode("FireWorks1", "SE/firework1.mp3");
	SE.registerBufferPlayerNode("FireWorks2", "SE/firework1.mp3");
	SE.registerBufferPlayerNode("FireWorks3", "SE/firework1.mp3");
	touch_anim = std::make_shared<Touch>(ci::vec2(-500, 0), 300);
	touch_move_anim = std::make_shared<TouchMove>(ci::vec2(-500, 0), 100);

}



void GameMain::update(const float& delta_time)
{
	ui.update(delta_time);
	ANIMATION.update(delta_time);
	touch_move_anim->update(delta_time);
	touch_anim->update(delta_time);
	
	
	for (auto& it : boss) {
		it->update(delta_time);
	}
	for (auto it : objects) {
		it->update(delta_time);
	}
	if (!touch) {
		touch_move_anim->setAnimationCount(0);
		touch_anim->setAnimationCount(0);
	}
	player->update(delta_time);
	if (!pause) {
		if (!touch) {
			if (tutorial) {
				ui.ui_data["Tuto"]->setActive(true);
			}
		}
		if (touch) {
			if (tutorial) {
				ui.ui_data["Tuto"]->setActive(false);
			}
		}
		for (auto& it : boss) {
			it->attackPlayer(player);
		}

		ui.setHP(player->getHP());

		
		for (auto it : objects) {
			it->attackPlayer(player);
		}

		player->attack(objects,boss);

		for (auto it = objects.begin(); it != objects.end(); it++) {
			if (!(*it)->isActive()) {
				objects.erase(it);
				break;
			}
		}
		for (auto it = boss.begin(); it != boss.end(); it++) {
			if (!(*it)->isActive()) {
				boss.erase(it);
				if (objects.size() <= 0 &&
					boss.size() <= 0) {
					boss_end = true;
				}
				break;
			}
		}
		is_boss = map.isBoss(objects, boss);
		is_lose = !player->isActive();
		if (boss_end == true) {
			if((objects.size() <= 0)){
				is_clear = true;
			}
		}
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
	for (auto& it : boss) {
		it->draw();
	}
	ANIMATION.draw();

	ci::gl::pushModelView();
	ci::gl::translate(ci::vec3(CAMERA.getPos().x - (camera_::WIDTH / 2), CAMERA.getPos().y - (camera_::HEIGHT / 2), CAMERA.getPos().z + 1500));
	ui.draw();
	touch_anim->draw();
	touch_move_anim->draw();
	ci::gl::popModelView();
}

void GameMain::setup()
{
	SE.registerFilePlayerNode("bgm", "Music/Decisive_Battle.mp3");
	boss_end = map.setup(objects);
	player = std::make_shared<Player>(map.getPlayerPos(0), PLAYERDATA.getSelectedCharacter());
	ui.setup(dess::SceneName::GAMEMAIN);
	player->setup();
	ui.setMaxHP(player->getHP());
	CAMERA.followingCamera(&player->getPPos(), ci::vec2(0));

	tutorial =  map.getTutorial();
	
	ANIMATION.setup();

	
	_m->setup();
	for (auto it : objects) {
		it->setup();
	}
}

void GameMain::mouseDown(const ci::app::MouseEvent & event)
{
	down_pos = event.getPos();
	player->mouseDown(event);
	if (event.isControlDown()) {
		CAMERA.setCameraZ(+200);
	}
	if (event.isRightDown()) {
		CAMERA.setCameraZ(-200);
	}
	touch_anim->setPos(event.getPos());
	touch_move_anim->setPos(event.getPos());
	ui.ui_data["TouchPos"]->setActive(true);
	ui.ui_data["TouchPos"]->setPos(event.getPos().x - 100, event.getPos().y - 100);
	touch = true;
}

void GameMain::mouseDrag(const ci::app::MouseEvent & event)
{
	move_pos = event.getPos();
	ci::vec2 buf = ci::vec2(move_pos - down_pos);
	float rad = std::sqrtf(buf.x * buf.x + buf.y * buf.y);
	player->mouseDrag(event);
	touch_move_anim->setAngle(std::atan2f(buf.y, buf.x));
	touch_move_anim->setSize(rad);
	ui.ui_data["TouchPos"]->setPos(event.getPos().x - 100, event.getPos().y - 100);
}

void GameMain::mouseUp(const ci::app::MouseEvent & event)
{
	player->mouseUp(event);
	ui.ui_data["TouchPos"]->setActive(false);
	touch = false;
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




