#include "Shelling.h"

void Shelling::attackUpdate()
{
	
	animation_count++;
	if (animation_count == 1) {
		ANIMATION.animationAdd<Exprode>(ci::vec2(pos.x + size.y / 2, pos.y + size.y / 2), size.y);
	}
	if (animation_count == 10) {
		ANIMATION.animationAdd<Exprode>(ci::vec2((pos.x + size.y / 2) + size.y, pos.y + size.y / 2), size.y);
	}
	if (animation_count == 20) {
		ANIMATION.animationAdd<Exprode>(ci::vec2((pos.x + size.y / 2) + size.y*2, pos.y + size.y / 2), size.y);
	}
	if (animation_count == 30) {
		ANIMATION.animationAdd<Exprode>(ci::vec2((pos.x + size.y / 2) + size.y*3, pos.y + size.y / 2), size.y);
	}
	
	if (animation_count == 32) {
		is_animaion = false;

	}
	if (animation_count == 3) {
		is_draw_damage = true;
	}

}

bool Shelling::circleDraw()
{
	if (!c_Easing::isEnd(range_color.a)) {
		ci::gl::pushModelMatrix();
		range_tex->bind();
		ci::gl::translate(pos);
		ci::gl::color(range_color.r, range_color.g, range_color.b, range_color.a);
		ci::Rectf drawRect(ci::vec2(
			0,
			0),
			ci::vec2(
				size.x,
				size.y));

		ci::gl::draw(range_tex, drawRect);
		range_tex->unbind();
		ci::gl::color(1, 1, 1, 1);
		ci::gl::popModelMatrix();
		return true;
	}
	return false;
}

void Shelling::damageUpdate()
{
	if (is_draw_damage == false) return;
	font_count++;
	if (font_count == 1) {
		if (RectToCircle(pos, size,0, obj->getPos(), obj->getRradius())) {
			obj->damage(attack);
			font_pos = obj->getPos();
			font_color = ci::vec4(1, 0, 0, 1);
			c_Easing::apply(attack_color.a, 0.0f, EasingFunction::BounceIn, 10);
			c_Easing::apply(font_scale.x, 0.5f, EasingFunction::BounceIn, 10);
			c_Easing::apply(font_scale.y, 0.5f, EasingFunction::BounceIn, 10);
			c_Easing::apply(font_color.a, 0.0f, EasingFunction::BounceIn, 40);
		}
		else {
			font_color = ci::vec4(0, 0, 0, 0);
			attack_color = ci::vec4(0, 0, 0, 0);
		}
	}
}




void Shelling::update(const float& delta_time)
{
	if (circleDraw()) return;
	attackUpdate();
	damageUpdate();

}

void Shelling::draw() {
	if (circleDraw()) return;
	if (!is_animaion) return;
	
	AttackAnimation::drawDamage();
}
