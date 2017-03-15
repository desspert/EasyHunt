#include "Scratch.h"


void Scratch::attackUpdate()
{


	int index;
	animation_count++;

	index = (animation_count / 2) % all_seets;
	if (animation_count == 2) {
		SE.find("Scratch")->start();
	}

	float x = (index) % static_cast<int>(seets.x) * cut.x;
	float y = (index) / static_cast<int>(seets.y) * cut.y;


	texture->setCleanBounds(ci::Area(ci::Rectf(x, y, x + cut.x, y + cut.y)));

	if (animation_count == 16) {
		is_animaion = false;

	}
	if (animation_count == 3) {
		is_draw_damage = true;
	}

}

bool Scratch::circleDraw()
{
	if (!c_Easing::isEnd(range_color.a)) {
		ci::gl::pushModelMatrix();
		range_tex->bind();
		ci::gl::translate(font_pos);
		ci::gl::translate(ci::vec2(-size.x / 2, -size.y / 2));
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

void Scratch::damageUpdate()
{
	if (is_draw_damage == false) return;
	font_count++;
	if (font_count == 1) {
		if (CollisionCircleToCircle(pos, range/2, obj->getPos(), 0)) {
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




void Scratch::update(const float& delta_time)
{
	if (circleDraw()) return;
	AttackAnimation::update(delta_time);
	attackUpdate();
	damageUpdate();

}

void Scratch::draw() {
	if (circleDraw()) return;
	AttackAnimation::draw();
	AttackAnimation::drawDamage();
}
