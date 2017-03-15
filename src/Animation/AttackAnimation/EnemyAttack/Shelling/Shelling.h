#pragma once
#include "../../../AnimationBase.h"
#include "../../AttackAnimation.h"
#include "../../../../SoundManager.h"
#include "../../../Production/Exprode/Exprode.h"
#include "../../../Animation.h"
class Shelling : public AttackAnimation {
private:
	ci::gl::TextureRef range_tex;
	ci::vec4 range_color;
	int range;
public:

	Shelling(const std::shared_ptr<ObjectBase>& obj)
		: AttackAnimation(obj) {

	}
	Shelling(const ci::vec2& pos, const std::shared_ptr<ObjectBase>& obj,
		const int& attack, const ci::vec2& size, const float& angle
	) : AttackAnimation(pos, obj, attack) {
		
		this->range = range;
		TEX.set("Box", "UI/UITexture/Select/GameChange.png");
		range_tex = TEX.get("Box");
		
		this->size = size;
		cut = ci::vec2(640, 213);
		seets = ci::vec2(1, 8);
		all_seets = 8;
		animation_count = 0;
		is_draw_damage = false;

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<float> random_x(-1.0f, 1.0f);
		std::uniform_real_distribution<float> random_y(-1.0f, 1.0f);
		float buf_x = random_x(mt);
		float buf_y = random_y(mt);
		font_pos = pos + ci::vec2(buf_x, buf_y);

		radius = 0;
		font_pos = obj->getPos();
		SE.registerBufferPlayerNode("Scratch", "Attack/Enemy/kiru3.wav");
		range_color = ci::vec4(1, 1, 0, 1);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 1, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 1, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 1, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 5);
		c_Easing::apply(range_color.a, 0, EasingFunction::Linear, 20);

		active_time = 0.5f;
	}
	void attackUpdate();
	bool circleDraw();
	void damageUpdate();
	void update(const float& delta_time);
	void draw();
};