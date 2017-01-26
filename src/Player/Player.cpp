#include "Player.h"

void Player::attack()
{

}

void Player::mouseDown(const ci::app::MouseEvent& event)
{
	pos_begin = event.getPos();
}

void Player::mouseDrag(const ci::app::MouseEvent& event)
{
	pos_moved = event.getPos();
}

void Player::mouseUp(const ci::app::MouseEvent& event)
{
	pos_end = event.getPos();
	pos_moved = ci::vec2(0);
}

void Player::setup()
{
	auto img = ci::loadImage(ci::app::loadAsset("Player3.png"));
	texture = ci::gl::Texture::create(img);
}

void Player::update(const int& delta_frame)
{
	attack();
	if (pos_moved != ci::vec2(0)) {
		auto buf = ci::vec2((pos_begin.x - pos_moved.x) / 50, (pos_begin.y - pos_moved.y) / 50);
		pos -= buf;
	}
}

void Player::draw()
{
	
	texture->bind();

	ci::Rectf drawRect(ci::vec2(
		pos.x,
		pos.y),
		ci::vec2(
			pos.x + size.x,
			pos.y + size.y));

	ci::gl::draw(texture, drawRect);

	texture->unbind();
	ci::gl::drawSolidCircle(ci::vec2(pos.x + size.x / 2, pos.y + size.y / 2), radius, 30);
	
}
