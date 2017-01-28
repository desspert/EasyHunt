#pragma once
#include "../ObjectBase.h"
#include <cinder/app/App.h>
#include "../ProductionCamera/ProductionCamera.h"
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include <cinder/gl/gl.h>
#include "../Weapon/Weapon.h"
#include "../Animation/Animation.h"
#include "../Enemy/Enemy.h"
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
	ci::gl::TextureRef	texture;
	Status status;
	Weapon weapon;
	bool is_attack;
	float attack_speed;
	float rotate;
public:
	Player(const ci::vec2& pos, const ci::vec2& size, const Status& status,const Weapon& weapon)
		: ObjectBase(pos,size) ,status(status),weapon(weapon){
		pos_begin = ci::vec2(0);
		pos_moved = ci::vec2(0);
		pos_end = ci::vec2(0);
		is_attack = false;
		rotate = 0;
		attack_speed = weapon.attack_speed;
	}
	void attack(std::list<std::shared_ptr<ObjectBase>>& objects);
	void attackSpeed(const float& delta_time);
	void move(const float& delta_time);


	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
	void setup();
	void update(const float& delta_time);
	void draw(std::shared_ptr<Enemy>& enemy);
};