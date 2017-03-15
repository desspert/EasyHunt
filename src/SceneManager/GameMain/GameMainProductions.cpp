#include "GameMain.h"
using gamemain_coroutine = boost::coroutines::coroutine<GameMain*>;
struct GameMain::GameMainProduction
{
	std::vector<CoroutineInfo>& c_info;
	gamemain_coroutine::push_type startCoroutine;
	GameMain& parent;


	GameMainProduction(GameMain& parent) :
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
		while (true)
		{
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
				if (yield().get()->is_lose) {
					yield().get()->c_info.clear();
					yield().get()->_m.get()->lose();
					break;
				}
				if (!yield().get()->boss_end) {
					if (yield().get()->is_boss) {
						yield().get()->c_info.clear();
						yield().get()->_m.get()->boss();
						yield().get()->is_boss = false;
						break;
					}
				}
			}
			//ゲームクリア時
			while (yield().get()->is_clear)
			{
				for (int i = 0; i < yield().get()->c_info.size(); i++)
				{
					yield().get()->time = yield().get()->c_info[i].time;
					yield().get()->c_info[i].callback();
				}
				break;
			}

			while (yield().get()->is_boss)
			{
				for (int i = 0; i < yield().get()->c_info.size(); i++)
				{
					yield().get()->time = yield().get()->c_info[i].time;
					yield().get()->c_info[i].callback();
				}
				break;
			}
			//ゲームオーバー時
			while (yield().get()->is_lose)
			{
				for (int i = 0; i < yield().get()->c_info.size(); i++)
				{
					yield().get()->time = yield().get()->c_info[i].time;
					yield().get()->c_info[i].callback();
				}
				break;
			}

		}

	}
	void setup()
	{
		start();
	}
	void boss()
	{
		c_info.push_back(CoroutineInfo(1, [this]() {
			SE.find("bgm")->stop();
			SE.find("BossBgm")->start();
			SE.find("BossBgm")->setLoopEnabled(true);
			SE.find("BossAppear")->start();
			CAMERA.fade_out = ci::vec4(1, 0, 0, 0);
			c_Easing::apply(CAMERA.fade_out.a, 0.5, EasingFunction::Linear, 30);
			c_Easing::apply(CAMERA.fade_out.a, 0, EasingFunction::Linear, 30);
			c_Easing::apply(CAMERA.fade_out.a, 0.5, EasingFunction::Linear, 30);
			c_Easing::apply(CAMERA.fade_out.a, 0, EasingFunction::Linear, 30);
			c_Easing::apply(CAMERA.fade_out.a, 0.5, EasingFunction::Linear, 30);
			c_Easing::apply(CAMERA.fade_out.a, 0, EasingFunction::Linear, 30);
			c_Easing::apply(CAMERA.fade_out.a, 0.5, EasingFunction::Linear, 30);
			c_Easing::apply(CAMERA.fade_out.a, 0, EasingFunction::Linear, 30);
			return;
		}));
		c_info.push_back(CoroutineInfo(5, [this]() {
			parent.pause = true;
			

			return;
		}));
		c_info.push_back(CoroutineInfo(1, [this]() {
			parent.map.bossSpawn(parent.boss);
			for (auto& it : parent.boss) {
				it->setup();
				it->setSpawn(true);
				CAMERA.followingCamera(&it->getPPos(), ci::vec2(0, 0));
			}
			return;
		}));
		c_info.push_back(CoroutineInfo(2, [&]() {
			SE.find("BossScream1")->start();
			SE.find("BossScream2")->start();
			CAMERA.shakeCamera(50, 3);
			parent.ui.ui_data["Scream"]->setActive(true);
			return;
		}));
		c_info.push_back(CoroutineInfo(3, [this]() {
			parent.ui.ui_data["Scream"]->setActive(false);
			return;
		}));
		c_info.push_back(CoroutineInfo(2, [this]() {
			CAMERA.fade_out = ci::vec4(0, 0, 0, 0);
			parent.pause = false;
			parent.ui.ui_data["Scream"]->setActive(false);
			parent.is_clear = false;
			follow();
			return;
		}));

	}

	void start()
	{
		c_info.push_back(CoroutineInfo(1, [this]() {
			c_Easing::apply(CAMERA.fade_out.a, 0, EasingFunction::Linear, 60);
			
			return;
		}));
		c_info.push_back(CoroutineInfo(1, [&]() {
			parent.player->setSpawn(true);
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
			parent.pause = false;
			return;
		}));

	}

	void lose()
	{
		c_info.push_back(CoroutineInfo(0, [this]() {
			SE.find("bgm")->stop();
			SE.find("BossBgm")->stop();
			parent.pause = true;
			return;
		}));
		c_info.push_back(CoroutineInfo(2, [&]() {
			SE.find("Lose")->start();
			c_Easing::apply(CAMERA.fade_out.a, 1, EasingFunction::Linear, 180);
			parent.ui.ui_data["Lose"]->setActive(true);
			return;
		}));

		c_info.push_back(CoroutineInfo(3, [this]() {
			shift();
			return;
		}));
	}
	void clear()
	{
		c_info.push_back(CoroutineInfo(0, [this]() {
			SE.find("bgm")->stop();
			SE.find("BossBgm")->stop();
			parent.pause = true;
			return;
		}));
		c_info.push_back(CoroutineInfo(0.5f, [&]() {
			SE.find("Crear")->start();
			return;
		}));

		c_info.push_back(CoroutineInfo(1, [&]() {
			parent.ui.ui_data["Fade"]->setActive(true);
			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_real_distribution<float> random_x(-200, 200);
			std::uniform_real_distribution<float> random_y(-400, 400);
			float buf_x = random_x(mt);
			float buf_y = random_y(mt);
			ANIMATION.animationAdd<FireWorks>(ci::vec2(buf_x, buf_y), 400);
			parent.ui.ui_data["Win"]->setActive(true);
		}));
		for (int i = 0; i < 15; i++) {

			c_info.push_back(CoroutineInfo(0.5f, [&]() {
				std::random_device rd;
				std::mt19937 mt(rd());
				std::uniform_real_distribution<float> random_x(-200, 200);
				std::uniform_real_distribution<float> random_y(-400, 400);
				float buf_x = random_x(mt);
				float buf_y = random_y(mt);
				ANIMATION.animationAdd<FireWorks>(ci::vec2(buf_x, buf_y), 400);
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


