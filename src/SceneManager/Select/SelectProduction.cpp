#include "Select.h"
using select_coroutine = boost::coroutines::coroutine<Select*>;
struct Select::_coroutine
{
	std::vector<CoroutineInfo>& c_info;
	select_coroutine::push_type startCoroutine;
	Select& parent;


	_coroutine(Select& parent) :
		startCoroutine(selectCoroutine), parent(parent), c_info(parent.c_info) {
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
	static void selectCoroutine(select_coroutine::pull_type & yield) {
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

			while (true)
			{
				yield();
				if (yield().get()->ui.isGasya()) {
					yield().get()->c_info.clear();
					yield().get()->_m->gasyaMove();
					break;
				}
				if (yield().get()->ui.isEnd()) {
					yield().get()->c_info.clear();
					yield().get()->_m->end();
					break;
				}

			}
			//ガシャ中
			while (yield().get()->ui.isGasya())
			{
				for (int i = 0; i < yield().get()->c_info.size(); i++)
				{
					yield().get()->time = yield().get()->c_info[i].time;
					yield().get()->c_info[i].callback();
				}
				yield().get()->c_info.clear();
				if (yield().get()->gasya_production) {
					yield().get()->_m->gasyaProduction();
					yield().get()->ui.isGasya() = false;
					break;
				}
				
				
			}

			while (yield().get()->gasya_production)
			{
				for (int i = 0; i < yield().get()->c_info.size(); i++)
				{
					yield().get()->time = yield().get()->c_info[i].time;
					yield().get()->c_info[i].callback();
				}
				yield().get()->c_info.clear();

				break;
			}

			//ゲーム終了時
			while (yield().get()->ui.isEnd())
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
	void start()
	{
		
		c_info.push_back(CoroutineInfo(1, [&]() {
			SE.find("SelectBGM")->start();
			SE.find("SelectBGM")->setLoopEnabled(true);
			c_Easing::apply(CAMERA.fade_out.a, 0, EasingFunction::Linear, 90);
			return;
		}));
		
	}
	void gasyaMove() {
		c_info.push_back(CoroutineInfo(0, [&]() {
			c_Easing::apply(CAMERA.fade_out.a, 1, EasingFunction::Linear, 30);
			return;
		}));
		c_info.push_back(CoroutineInfo(1, [&]() {
			parent.camera_pos.x = 1000;
			SE.registerBufferPlayerNode("GasyaSE1", "SE/gasya_se1.mp3");
			SE.registerBufferPlayerNode("GasyaSE2", "SE/gasya_se2.mp3");
			SE.registerBufferPlayerNode("GasyaSE3", "SE/shine4.mp3");
			SE.registerBufferPlayerNode("GasyaNormal", "SE/normal.mp3");
			SE.registerBufferPlayerNode("GasyaRare", "SE/rare.wav");
			SE.registerBufferPlayerNode("RareJingle", "SE/jingle1.mp3");
			auto img_range = ci::loadImage(ci::app::loadAsset("Characters/Star3/Blaze/murayakimen02-mv.png"));
			parent.ui.textures["GasyaChara"] = ci::gl::Texture2d::create(img_range);
			return;
		}));
		
		c_info.push_back(CoroutineInfo(1, [&]() {
			c_Easing::apply(CAMERA.fade_out.a, 0, EasingFunction::Linear, 60);
			
			return;
		}));
		c_info.push_back(CoroutineInfo(1, [&]() {
			parent.ui.ui_data["GasyaBall"]->setActive(true);
			ANIMATION.animationAdd<GasyaSpawn>(ci::vec2(1300, 500), 1000);
			SE.find("GasyaNormal")->start();
			parent.pause = false;
			return;
		}));
		
		
	}
	void gasyaProduction() {

		c_info.push_back(CoroutineInfo(0, [&]() {
			parent.ui.ui_data["GasyaBall"]->setActive(false);
			SE.find("GasyaSE1")->start();
			return;
		}));
		c_info.push_back(CoroutineInfo(0.3f, [&]() {
			SE.find("GasyaSE2")->start();
			return;
		}));

		c_info.push_back(CoroutineInfo(0.5f, [&]() {
			ANIMATION.animationAdd<Gasya>(ci::vec2(680, 0), ci::vec2(1280, 960));
			SE.find("GasyaSE3")->start();
			return;
		}));

		c_info.push_back(CoroutineInfo(0.5f, [&]() {
			CAMERA.fade_out = ci::vec4(1,1,1,0);
			c_Easing::apply(CAMERA.fade_out.a, 1, EasingFunction::Linear, 30);
			return;
		}));
		c_info.push_back(CoroutineInfo(1.5f, [&]() {
			c_Easing::apply(CAMERA.fade_out.a, 0, EasingFunction::Linear, 70);
			SE.find("RareJingle")->start();
			ANIMATION.animationAdd<GasyaEnd>(ci::vec2(1300, 500), 1000);
			return;
		}));

		c_info.push_back(CoroutineInfo(1, [&]() {
			parent.ui.ui_data["GasyaChara"]->setActive(true);
			ANIMATION.animationAdd<GasyaEnd>(ci::vec2(1300, 500), 1000);
			return;
		}));
		for (int i = 0; i < 10; i++) {
			c_info.push_back(CoroutineInfo(1, [&]() {
				ANIMATION.animationAdd<GasyaEnd>(ci::vec2(1300, 500), 1000);
				return;
			}));
		}

	}
	void end()
	{
		c_info.push_back(CoroutineInfo(0, [&]() {
			c_Easing::apply(CAMERA.fade_out.a, 1, EasingFunction::Linear, 60);
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
		SCENE.shift(SceneName::GAMEMAIN);
	}
	
};


