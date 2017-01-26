#pragma once
#include "../ObjectBase.h"
#include <cinder/app/App.h>
#include "../ProductionCamera/ProductionCamera.h"
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include <cinder/gl/gl.h>
#include "../Weapon/Weapon.h"
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
public:
	Player(const ci::vec2& pos, const ci::vec2& size, const Status& status,const Weapon& weapon)
		: ObjectBase(pos,size) ,status(status),weapon(weapon){
		pos_begin = ci::vec2(0);
		pos_moved = ci::vec2(0);
		pos_end = ci::vec2(0);
	}
	void attack();

	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
	void setup();
	void update(const int& delta_frame);
	void draw();
};