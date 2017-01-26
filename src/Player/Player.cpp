#include "Player.h"

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

void Player::update()
{
	if (pos_moved != ci::vec2(0)) {
		auto buf = ci::vec2((pos_begin.x - pos_moved.x) / 50, (pos_begin.y - pos_moved.y) / 50);
		pos -= buf;
	}
}

void Player::draw()
{
}
