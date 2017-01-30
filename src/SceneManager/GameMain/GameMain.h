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
	//std::shared_ptr<Enemy> enemy2;
	//std::shared_ptr<Enemy> enemy3;
	//std::shared_ptr<Enemy> enemy4;
	//std::shared_ptr<Enemy> enemy5;
	std::list<std::shared_ptr<ObjectBase>> objects;
	
public:
	GameMain(){
		
		player = std::make_shared<Player>(ci::vec2(0, 0), ci::vec2(100, 100),Status(10,10,300,""),Weapon(10,0.17f,""));
		enemy = std::make_shared<Enemy>(ci::vec2(300, 0), ci::vec2(100, 100),10,10);
		/*enemy2 = std::make_shared<Enemy>(ci::vec2(300, 100), ci::vec2(100, 100), 10, 10);
		enemy3 = std::make_shared<Enemy>(ci::vec2(200, 100), ci::vec2(100, 100), 10, 10);
		enemy4 = std::make_shared<Enemy>(ci::vec2(200, 0), ci::vec2(100, 100), 10, 10);
		enemy5 = std::make_shared<Enemy>(ci::vec2(400, 0), ci::vec2(100, 100), 10, 10);*/

		objects.push_back(enemy);
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
};