#pragma once
#include "../../AnimationBase.h"
#include "../AttackAnimation.h"
#include "../../../SoundManager.h"
class Blade : public AttackAnimation {
public:

	Blade(const std::shared_ptr<ObjectBase>& obj, ci::gl::TextureRef copy_tex,
		std::vector<ci::gl::TextureRef>	attack_texture)
		: AttackAnimation(obj,copy_tex, attack_texture) {

		pos = obj->getCenter();

		attack_type = AttackType::Slashing;
		size = ci::vec2(300, 300);
		cut = ci::vec2(256, 256);
		seets = ci::vec2(6, 0);
		all_seets = 6;
		animation_count = 0;
		is_draw_damage = false;

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<float> random_x(-1.0f, 1.0f);
		std::uniform_real_distribution<float> random_y(-1.0f, 1.0f);
		float buf_x = random_x(mt);
		float buf_y = random_y(mt);
		font_pos = pos + ci::vec2(buf_x, buf_y);

		std::uniform_real_distribution<float> random_rotate(-20.0f, 100.0f);
		float rotate_buf = random_rotate(mt);
		radius = rotate_buf;

	}
	Blade(const ci::vec2& pos,const std::shared_ptr<ObjectBase>& obj,
		const int& attack,
		ci::gl::TextureRef copy_tex,
		std::vector<ci::gl::TextureRef>	attack_texture,
		ci::Font font) : AttackAnimation(pos,obj,attack, copy_tex, attack_texture,font){
		attack_type = AttackType::Slashing;
		size = ci::vec2(300, 300);
		cut = ci::vec2(256, 256);
		seets = ci::vec2(6, 0);
		all_seets = 6;
		animation_count = 0;
		is_draw_damage = false;

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<float> random_x(-30.0f, 30.0f);
		std::uniform_real_distribution<float> random_y(-30.0f, 30.0f);
		float buf_x = random_x(mt);
		float buf_y = random_y(mt);
		std::uniform_real_distribution<float> random_rotate(-20.0f, 100.0f);
		float rotate_buf = random_rotate(mt);
		radius = rotate_buf;
		font_pos = pos + ci::vec2(buf_x, buf_y);
		SE.registerBufferPlayerNode("blade", "kiru2.wav");
		
	}
	void attackUpdate();

	void update();
	void draw();
	
};