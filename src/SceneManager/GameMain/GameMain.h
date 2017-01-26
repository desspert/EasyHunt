#pragma once
#include "../SceneBase.h"
#include "../SceneManager.h"
#include "../../dessUI/UIPlate/GameMainUI/GameMainUI.h"
#include "../../Player/Player.h"
#include "../../Enemy/Enemy.h"
class GameMain : public SceneBase
{
private:
	GameMainUI ui;
	std::shared_ptr<Player> player;
	std::shared_ptr<Enemy> enemy;
	std::list<std::shared_ptr<ObjectBase>> objects;
public:
	GameMain(){
		player = std::make_shared<Player>(ci::vec2(0, 0), ci::vec2(100, 100),Status(10,10,10,""),Weapon(10,10,""));
		enemy = std::make_shared<Enemy>(ci::vec2(300, 0), ci::vec2(100, 100),10,10);
		CAMERA.followingCamera(&player->getPos(), player->getSize());
	}
	
	void update(const int& delta_frame) override;
	void draw() override;
	void setup() override ;
	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
};