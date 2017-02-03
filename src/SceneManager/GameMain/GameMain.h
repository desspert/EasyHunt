#pragma once
#include "../SceneBase.h"
#include "../SceneManager.h"
#include "../../dessUI/UIPlate/GameMainUI/GameMainUI.h"
#include "../../Player/Player.h"
#include "../../Enemy/Enemy.h"
#include "../../Event/EventManager.h"
#include "../../Map/Map.h"
class GameMain : public SceneBase
{
private:
	GameMainUI ui;
	EventManager game_event;
	Map map;
	std::shared_ptr<Player> player;
	std::list<std::shared_ptr<ObjectBase>> objects;
	
public:
	GameMain(){
		TEX.set("Blade", "attack.png");
		TEX.set("player", "tokugawa.png");
		TEX.set("Dead", "Enemy/dead.png");
		SE.registerBufferPlayerNode("dead", "SE/sen_ge_iron_syoutotu04.mp3");
		player = std::make_shared<Player>(ci::vec2(0, 0), ci::vec2(100, 100), TEX.get("player"),Status(10,10,100,""),Weapon(10,0.2f, 300,""));

		/*objects.push_back(enemy2);
		objects.push_back(enemy3);
		objects.push_back(enemy4);
		objects.push_back(enemy5);*/
		CAMERA.followingCamera(&player->getPPos(), player->getSize());
	}
	
	void update(const float& delta_time) override;
	void draw() override;
	void setup() override ;
	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
	void touchesBegan(ci::app::TouchEvent event);
	void touchesMoved(ci::app::TouchEvent event);
	void touchesEnded(ci::app::TouchEvent event);
};