#include "Player.h"



void Player::attack(std::list<std::shared_ptr<ObjectBase>>& objects)
{
	for (auto& it : objects) {
		EnemyCollision(pos, size, radius, it->getPos(), it->getSize(), it->getRradius());
		if (CollisionCircleToCircle(pos, radius*status.range/100, it->getPPos(), it->getRradius())) {
			if (is_attack) {
				ANIMATION.animationAdd<Blade>(pos + returnCircleToCircle(pos, it->getPPos(), it->getRradius()),
				it,
				status.attack);
				break;
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
		attack_speed = status.attack_speed;
	}
}

void Player::move(const float& delta_time)
{

	if (pos_moved != ci::vec2(0)) {
		auto buf = ci::vec2((pos_begin.x - pos_moved.x) / 50, (pos_begin.y - pos_moved.y) / 50);
		if (buf.x >= 2) buf.x = 2;
		if (buf.x <= -2) buf.x = -2;
		if (buf.y >= 2) buf.y = 2;
		if (buf.y <= -2) buf.y = -2;
	
		pos -= ci::vec2(buf.x * delta_time * status.speed,buf.y * delta_time * status.speed);
	}
	CollisionWall(pos ,size, radius);
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

void Player::touchesBegan(ci::app::TouchEvent event)
{
	pos_begin = event.getTouches()[0].getPos();
}

void Player::touchesMoved(ci::app::TouchEvent event)
{
	pos_moved = event.getTouches()[0].getPos();
}

void Player::touchesEnded(ci::app::TouchEvent event)
{
	pos_end = event.getTouches()[0].getPos();
	pos_moved = ci::vec2(0);

}

void Player::setup()
{
	TEX.set("player", status.texture_path);
	auto img_range = ci::loadImage(ci::app::loadAsset("Player/Circle.png"));
	attack_range = ci::gl::Texture2d::create(img_range);
	
	img_range = ci::loadImage(ci::app::loadAsset("Player/Player.png"));
	ball = ci::gl::Texture2d::create(img_range);
}

void Player::update(const float& delta_time)
{
	attackSpeed(delta_time);
	move(delta_time);
}

void Player::draw()
{
	


	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::rotate(rotate);
	ci::gl::translate(ci::vec2(-size.x * (status.range / 100)/2, -size.y * (status.range / 100) / 2));
	attack_range->bind();
	ci::gl::color(1, 0, 0, 0.2f);
	ci::Rectf drawRange(ci::vec2(
		0,
		0),
		ci::vec2(
			size.x * status.range / 100,
			size.y * status.range / 100));
	ci::gl::draw(attack_range, drawRange);
	ci::gl::color(1, 1, 1, 1);
	attack_range->unbind();
	ci::gl::popModelMatrix();


	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::translate(ci::vec2((-size.x / 2)* 1.5f, (-size.y / 2)* 1.5f));
	ball->bind();
	ci::gl::color(1, 1, 1, 1);
	ci::Rectf drawBall(ci::vec2(
		0,
		0),
		ci::vec2(
			size.x * 1.5f,
			size.y * 1.5f));
	ci::gl::draw(ball, drawBall);
	ci::gl::color(1, 1, 1, 1);
	ball->unbind();
	ci::gl::popModelMatrix();


	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::rotate(rotate);
	ci::gl::translate(ci::vec2(-size.x / 2, -size.y / 2));
	TEX.get("player")->bind();
	ci::gl::color(color.r, color.g, color.b, color.a);
	ci::Rectf drawRect(ci::vec2(
		0,
		0),
		ci::vec2(
			size.x,
			size.y));
	ci::gl::draw(TEX.get("player"), drawRect);
	ci::gl::color(1, 1, 1, 1);
	TEX.get("player")->unbind();
	ci::gl::popModelMatrix();




	


}
