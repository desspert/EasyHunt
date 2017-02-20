#include "GameMain.h"
using gamemain_coroutine = boost::coroutines::coroutine<GameMain*>;
struct GameMain::_coroutine
{
	std::vector<CoroutineInfo>& c_info;
	gamemain_coroutine::push_type startCoroutine;
	GameMain& parent;


	_coroutine(GameMain& parent) :
		startCoroutine(gameMainCoroutine), parent(parent), c_info(parent.c_info) {
		parent.time = 0;
	}


	void update(const float& delta_time)
	{
		parent.time -= delta_time;
		if (parent.time < 0)
		{
			startCoroutine(&parent);
			parent.time = parent.time;
		}

	}
	static void gameMainCoroutine(gamemain_coroutine::pull_type & yield) {

		//開始時
		while (yield().get()->is_start)
		{
			for (int i = 0; i < yield().get()->c_info.size(); i++)
			{
				yield().get()->time = yield().get()->c_info[i].time;
				yield().get()->c_info[i].callback();
				yield();
			}
			yield().get()->is_start = false;
			break;
		}
		//ゲーム中
		while (true)
		{
			yield();
			if (yield().get()->is_clear) {
				yield().get()->c_info.clear();
				yield().get()->_m.get()->clear();
				break;
			}
		}
		//ゲーム終了時
		while (yield().get()->is_clear)
		{
			for (int i = 0; i < yield().get()->c_info.size(); i++)
			{
				yield().get()->time = yield().get()->c_info[i].time;
				yield().get()->c_info[i].callback();
			}
			break;
		}


	}
	void setup()
	{
		start();
	}
	void start()
	{
		c_info.push_back(CoroutineInfo(1, [&]() {
			c_Easing::apply(CAMERA.fade_out.a, 0, EasingFunction::Linear, 60);
			return;
		}));
		for (auto& it : parent.objects) {
			c_info.push_back(CoroutineInfo(1, [this, it]() {
				CAMERA.followingCamera(&it->getPPos(), ci::vec2(0, 0));
				it->setSpawn(true);
				return;
			}));
		}

		c_info.push_back(CoroutineInfo(1.5f, [this]() {
			follow();
			SE.find("bgm")->setGain(0.3f);
			SE.find("bgm")->start();
			return;
		}));

	}

	void clear()
	{
		c_info.push_back(CoroutineInfo(0, [&]() {
			SE.find("bgm")->stop();
			parent.pause = true;
			return;
		}));
		c_info.push_back(CoroutineInfo(0.5f, [&]() {
			SE.find("Crear")->start();
			return;
		}));
		
		for (int i = 0; i < 16; i++) {
			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_real_distribution<float> random(0.3f,1);
			float buf = random(mt);
			c_info.push_back(CoroutineInfo(buf, [&]() {
				std::random_device rd;
				std::mt19937 mt(rd());
				std::uniform_real_distribution<float> random_x(-200,200);
				std::uniform_real_distribution<float> random_y(-400,400);
				float buf_x = random_x(mt);
				float buf_y = random_y(mt);
				ANIMATION.animationAdd<FireWorks>(ci::vec2(buf_x, buf_y), 200);
			}));
		}
		c_info.push_back(CoroutineInfo(1, [&]() {
			c_Easing::apply(CAMERA.fade_out.a, 1, EasingFunction::Linear, 30);
			return;
		}));
		
		c_info.push_back(CoroutineInfo(1, [this]() {
			shift();
			return;
		}));

	}
	void shift() {
		SE.allStop();
		SE.allCrear();
		SCENE.shift(SceneName::SELECT);
	}
	void follow() {
		CAMERA.followingCamera(&parent.player->getPPos(), ci::vec2(0, 0));
	}
};


