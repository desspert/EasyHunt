#include "Enemy.h"

void Enemy::setup()
{
}

void Enemy::update(const float& delta_time)
{
	ObjectBase::changeHP(delta_time);
	isDead();
}

void Enemy::draw()
{
	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::rotate(0);
	ci::gl::translate(ci::vec2(-size.x / 2, -size.y / 2));
	texture->bind();
	ci::gl::color(color.r, color.g, color.b, color.a);
	ci::Rectf drawRect(ci::vec2(
		0,
		0),
		ci::vec2(
			size.x,
			size.y));
	ci::gl::draw(texture, drawRect);
	ci::gl::color(1, 1, 1, 1);
	texture->unbind();
	
	ci::gl::popModelMatrix();
	if (!is_dead) {
		gauge.draw(pos + ci::vec2(-size.x / 2, size.y / 2), ci::vec2(2, 0.5f));
	}
}

void Enemy::isDead()
{
	if (!is_dead) return;
	dead_count++;
	if (dead_count == 1) {
		c_Easing::apply(size.x, 0, EasingFunction::BounceIn, 30);
		c_Easing::apply(size.y, 0, EasingFunction::BounceIn, 30);
	}
	if (dead_count == 30) {
		ANIMATION.animationAdd<Dead>(this->getCenter(),radius);
		is_active = false;
	}
}
