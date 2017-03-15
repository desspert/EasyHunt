#pragma once
#include "../../../AnimationBase.h"
#include "../../AttackAnimation.h"
#include "../../../../SoundManager.h"

class Magic : public AttackAnimation {
private:
	ci::gl::TextureRef range_tex;
	ci::vec4 range_color;
	int range;
public:

	Magic(const std::shared_ptr<ObjectBase>& obj)
		: AttackAnimation(obj) {

	}
	Magic(const ci::vec2& pos, const std::shared_ptr<ObjectBase>& obj,
		const int& attack, const int& range
	) : AttackAnimation(pos, obj, attack) {
		this->range = range;
		TEX.set("Circle", "Player/Circle.png");
		range_tex = TEX.get("Circle");
		TEX.set("Magic", "Attack/Enemy/Effects/pipo-mapeffect010.png");
		texture = TEX.get("Magic");
		size = ci::vec2(range, range);
		cut = ci::vec2(240, 240);
		seets = ci::vec2(13, 1);
		all_seets = 13;
		animation_count = 0;
		is_draw_damage = false;

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<float> random_x(-1.0f, 1.0f);
		std::uniform_real_distribution<float> random_y(-1.0f, 1.0f);
		float buf_x = random_x(mt);
		float buf_y = random_y(mt);
		font_pos = pos;

		radius = 0;
		SE.registerBufferPlayerNode("Magic", "SE/magic.mp3");
		range_color = ci::vec4(1, 1, 0, 1);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 1, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 1, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 1, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 30);

		active_time = 0.5f;
	}
	void attackUpdate();
	bool circleDraw();
	void damageUpdate();
	void update(const float& delta_time);
	void draw();
};