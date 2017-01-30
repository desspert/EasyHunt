#include "Enemy.h"

void Enemy::setup()
{
	auto img = ci::loadImage(ci::app::loadAsset("2VTTfjcCT.png"));
	texture = ci::gl::Texture::create(img);
}

void Enemy::update(const float& delta_time)
{
}

void Enemy::draw()
{
	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::rotate(0);
	ci::gl::translate(ci::vec2(-size.x / 2, -size.y / 2));
	ci::gl::drawSolidCircle(ci::vec2(size.x / 2, size.y / 2), radius, 30);
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
	
}
