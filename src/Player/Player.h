#pragma once
#include "../ObjectBase.h"
#include <cinder/app/App.h>
#include "../ProductionCamera/ProductionCamera.h"
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include <cinder/gl/gl.h>
#include "../Weapon/Weapon.h"
#include "../HPGauge/HPGauge.h"
#include "../Animation/Animation.h"
namespace wall {
	enum WINDOW_SIZE {
		WIDTH = 3000,
	    HEIGHT = 2000
	};
}

static void EnemyCollision(ci::vec2& pos1, ci::vec2 size1, const float& r1,
	ci::vec2 pos2, ci::vec2 size2, const float& r2) {
	ci::vec2 center1 = ci::vec2(pos1.x + size1.x/2, pos1.y + size1.y/2);
	ci::vec2 center2 = ci::vec2(pos2.x + size2.x/2, pos2.y + size2.y/2);


	if (CollisionCircleToCircle(pos1, r1, pos2, r2)) {

		ci::vec2 buf = ci::vec2(pos1 - pos2);
		float rad = std::sqrtf(buf.x * buf.x + buf.y * buf.y);
		pos1 = pos2 + (ci::vec2((1/ rad) * buf.x, (1/ rad) *  buf.y) * (r1 + r2));
	}
}

static void CollisionWall(ci::vec2& pos, ci::vec2 size,float radius) {
	if (((pos.x + size.x / 2) + radius) > wall::WIDTH) {
		pos.x = (wall::WIDTH - size.x / 2) - radius;
	}
	if (((pos.x - size.x / 2) + radius) < 0) {
		pos.x = (-size.x / 2) + radius;
	}
	if (((pos.y + size.y / 2) + radius) > wall::HEIGHT) {
		pos.y = (wall::HEIGHT - size.y / 2) - radius;
	}
	if (((pos.y - size.y / 2) + radius) < 0) {
		pos.y = (-size.y / 2) + radius;
	}
}
struct Status {
	Status(const int& hp,const int& attack,const float& speed,const std::string& skill)
	:hp(hp),attack(attack),speed(speed),skill(skill){}
	int hp;
	int attack;
	float speed;
	std::string skill;
};


class Player : public ObjectBase
{
private:
	ci::vec2 pos_begin;
	ci::vec2 pos_moved;
	ci::vec2 pos_end;
	ci::gl::TextureRef attack_range;
	ci::gl::TextureRef ball;
	Status status;
	Weapon weapon;
	HPGauge gauge;
	bool is_attack;
	float attack_speed;
	float rotate;
public:
	Player(const ci::vec2& pos, const ci::vec2& size, const ci::gl::TextureRef& texture, const Status& status,const Weapon& weapon)
		: ObjectBase(pos,size) ,status(status),weapon(weapon){
		this->texture = texture;
		pos_begin = ci::vec2(0);
		pos_moved = ci::vec2(0);
		pos_end = ci::vec2(0);
		is_attack = false;
		rotate = 0;
		attack_speed = weapon.attack_speed;
		hp = status.hp;
	}


	void attack(std::list<std::shared_ptr<ObjectBase>>& objects);
	void attackSpeed(const float& delta_time);
	void move(const float& delta_time);


	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
	void touchesBegan(ci::app::TouchEvent event);
	void touchesMoved(ci::app::TouchEvent event);
	void touchesEnded(ci::app::TouchEvent event);
	void setup();
	void update(const float& delta_time);
	void draw();
};