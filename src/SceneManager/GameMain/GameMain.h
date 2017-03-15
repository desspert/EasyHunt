#pragma once
#include "../SceneBase.h"
#include "../SceneManager.h"
#include "../../dessUI/UIPlate/GameMainUI/GameMainUI.h"
#include "../../Player/Player.h"
#include "../../Enemy/Enemy.h"
#include "../../Map/Map.h"
#include "../../Event/Coroutine.h"
#include "../../Data/Data.h"
#include "../../Animation/Production/Touch/Touch.h"
#include "../../Animation/Production/Touch/TouchMove.h"
#include "../../Enemy/Boss/Boss.h"
 
class GameMain : public SceneBase
{
private:
	GameMainUI ui;
	Map map;
	std::shared_ptr<Player> player;
	std::list<std::shared_ptr<ObjectBase>> objects;
	std::list<std::shared_ptr<Boss>> boss;
	std::vector<CoroutineInfo> c_info;
	std::shared_ptr<Touch> touch_anim;
	std::shared_ptr<TouchMove> touch_move_anim;
	ci::vec2 down_pos;
	ci::vec2 move_pos;
	bool touch;
	bool tutorial;
	float time;
	bool boss_end;
	bool is_start;
	bool is_boss;
	bool is_clear;
	bool is_lose;
	bool pause;
public:
	GameMain();
	

	struct GameMainProduction;
	std::shared_ptr<GameMainProduction> _m;

	
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
