#pragma once
#include "../SceneBase.h"
#include "../SceneManager.h"
#include "../../dessUI/UIPlate/UIPlate.h"
#include "../../Player/Player.h"
class GameMain : public SceneBase
{
private:
	UIPlate ui;
	std::shared_ptr<Player> player;
	
public:
	GameMain(){
		player = std::make_shared<Player>(ci::vec2(0, 0), ci::vec2(100, 100));
		CAMERA.setPos(&player->getPos());
	}
	
	void update() override;
	void draw() override;
	void setup() override ;
	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
};