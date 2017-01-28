#include "Player.h"



void Player::attack(std::list<std::shared_ptr<ObjectBase>>& objects)
{
	for (auto& it : objects) {
		if (CollisionCircleToCircle(pos, radius, it->getPPos(), it->getRradius())) {
			if (is_attack) {
				ci::app::console() << returnCircleToCircle(pos, it->getPPos(), it->getRradius()) << std::endl;
//			ANIMATION.animationAdd<Blade>(pos + returnCircleToCircle(pos, it->getPPos(), it->getRradius()), it, ANIMATION.getTexture()[AnimationType::Blade]);
			}
		}
	}
}

void Player::attackSpeed(const float& delta_time)
{
	is_attack = false;
	attack_speed -= delta_time;
	if (attack_speed < 0) {
		is_attack = true;
		attack_speed = weapon.attack_speed;
	}
}

void Player::move(const float& delta_time)
{

	if (pos_moved != ci::vec2(0)) {
		rotate += 0.1f;
		auto buf = ci::vec2((pos_begin.x - pos_moved.x) / 100, (pos_begin.y - pos_moved.y) / 100);
		if (buf.x >= 2) buf.x = 2;
		if (buf.x <= -2) buf.x = -2;
		if (buf.y >= 2) buf.y = 2;
		if (buf.y <= -2) buf.y = -2;
	
		pos -= ci::vec2(buf.x * delta_time * status.speed,buf.y * delta_time * status.speed);
	}

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
	auto img = ci::loadImage(ci::app::loadAsset("clock.png"));
	texture = ci::gl::Texture2d::create(img);
}

void Player::update(const float& delta_time)
{
	attackSpeed(delta_time);
	move(delta_time);
}

void Player::draw(std::shared_ptr<Enemy>& enemy)
{

	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::rotate(rotate);
	ci::gl::translate(ci::vec2(-size.x / 2, -size.y / 2));
	texture->bind();
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
