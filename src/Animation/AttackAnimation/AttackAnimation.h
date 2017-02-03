#pragma once
#include "../AnimationBase.h"
#include "../../dessUI/Easing/Easing.h"
#include <random>


class AttackAnimation : public AnimationBase {
protected:
	//std::map<std::string, SignalType>& signals;
	std::shared_ptr<ObjectBase> obj;
	std::vector<ci::gl::TextureRef>	attack_texture;
	int attack;
	ci::vec4 attack_color;
	ci::Font font;
	ci::vec2 font_pos;
	ci::vec2 font_scale;
	ci::vec4 font_color;
	int font_count;
	bool is_draw_damage;
	bool is_animaion;
public:

	AttackAnimation(const std::shared_ptr<ObjectBase>& obj)
		: obj(obj){
		
		pos = obj->getCenter();
		
		animation_count = 0;
		font_count = 0;
		is_draw_damage = false;
		is_animaion = true;
		radius = 0;
		font_scale = ci::vec2(0.7f, 0.7f);
		font_color = ci::vec4(0, 1,0,1);
		attack_color = ci::vec4(1, 1, 1, 0.7f);
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<float> random_x(-1.0f, 1.0f);
		std::uniform_real_distribution<float> random_y(-1.0f, 1.0f);
		float buf_x = random_x(mt);
		float buf_y = random_y(mt);
		
		font_pos = pos + ci::vec2(buf_x, buf_y);
	}
	AttackAnimation(const ci::vec2& pos, 
		const std::shared_ptr<ObjectBase>& obj,
		const int& attack,
		ci::Font font) :obj(obj), AnimationBase(pos),
		attack(attack), font(font) {
		
		animation_count = 0;
		is_draw_damage = false;
		is_animaion = true;
		radius = 0;
		font_scale = ci::vec2(0.7f, 0.7f);
		font_color = ci::vec4(0.3f, 1, 0.3f, 1);
		attack_color = ci::vec4(1, 1, 1, 0.7f);
		font_count = 0;
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<float> random_x(-30.0f, 30.0f);
		std::uniform_real_distribution<float> random_y(-30.0f, 30.0f);
		
		float buf_x = random_x(mt);
		float buf_y = random_y(mt);
		
		font_pos = pos + ci::vec2(buf_x, buf_y);
	}
	virtual void damageUpdate();
	void update(const float& delta_time)override;
	void draw()override;
	virtual void drawDamage();
	
};