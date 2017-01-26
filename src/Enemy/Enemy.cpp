#include "Enemy.h"

void Enemy::setup()
{
	auto img = ci::loadImage(ci::app::loadAsset("Player3.png"));
	texture = ci::gl::Texture::create(img);
}

void Enemy::update(const int& delta_frame)
{
}

void Enemy::draw()
{
	ci::gl::drawSolidCircle(ci::vec2(pos.x + size.x / 2, pos.y + size.y / 2), radius, 30);
	texture->bind();

	ci::Rectf drawRect(ci::vec2(
		pos.x,
		pos.y),
		ci::vec2(
			pos.x + size.x,
			pos.y + size.y));

	ci::gl::draw(texture, drawRect);

	texture->unbind();
	
}
