#pragma once
#include "../SceneBase.h"
#include "../SceneManager.h"
#include "../../dessUI/UIPlate/GameMainUI/GameMainUI.h"
#include "../../Player/Player.h"
#include "../../Enemy/Enemy.h"
#include "../../Map/Map.h"
#include "../../Event/Coroutine.h"
 
class GameMain : public SceneBase
{
private:
	GameMainUI ui;
	Map map;
	std::shared_ptr<Player> player;
	std::list<std::shared_ptr<ObjectBase>> objects;
	std::vector<CoroutineInfo> c_info;
	float time;
	bool is_start;
	bool is_clear;

	bool pause;
	
public:
	GameMain();
	

	struct _coroutine;
	std::shared_ptr<_coroutine> _m;

	
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
