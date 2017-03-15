#include "AttackAnimation.h"

void AttackAnimation::damageUpdate()
{

	if (is_draw_damage == false) return;
	font_count++;
	if (font_count == 1) {
		obj->damage(attack);
		c_Easing::apply(attack_color.a, 0.0f, EasingFunction::BounceIn, 10);
		c_Easing::apply(font_scale.x, 0.5f, EasingFunction::BounceIn, 10);
		c_Easing::apply(font_scale.y, 0.5f, EasingFunction::BounceIn, 10);
		c_Easing::apply(font_color.a, 0.0f, EasingFunction::BounceIn, 40);
	}

}

void AttackAnimation::update(const float& delta_time)
{
	active_time -= delta_time;
	if (active_time < 0) {
		is_active = false;
	}
}

void AttackAnimation::draw()
{
	if (!is_animaion) return;
	ci::gl::pushModelMatrix();
	
	texture->bind();
	ci::gl::translate(pos);
	ci::gl::rotate(radius);
	ci::gl::translate(ci::vec2(-size.x / 2, -size.y / 2));
	ci::Rectf drawRect(ci::vec2(
		0,
		0),
		ci::vec2(
			size.x,
			size.y));

	ci::gl::draw(texture, drawRect);
	texture->unbind();
	ci::gl::popModelMatrix();

}

void AttackAnimation::drawDamage()
{
	if (!is_draw_damage) return;


	ci::gl::pushModelMatrix();
	TEX.get("Slashing")->bind();
	ci::gl::translate(font_pos);
	ci::gl::translate(ci::vec2(-size.x / 2, -size.y / 2));
	ci::gl::color(attack_color.r, attack_color.g, attack_color.b, attack_color.a);
	ci::Rectf drawRect(ci::vec2(
		0,
		0),
		ci::vec2(
			size.x,
			size.y));

	ci::gl::draw(TEX.get("Slashing"),drawRect);
	TEX.get("Slashing")->unbind();
	ci::gl::color(1, 1, 1, 1);
	ci::gl::popModelMatrix();

	ci::gl::pushModelMatrix();
	ci::gl::translate(font_pos);
	ci::gl::scale(font_scale);
	ci::gl::translate(ci::vec2(-50, -50));
	
	ci::gl::color(font_color.r, font_color.g, font_color.b, font_color.a);
	ci::gl::draw(ci::gl::Texture2d::create(font.render(true)));
	
	ci::gl::color(ci::Color::white()); 
	ci::gl::popModelMatrix();

	
	

}
