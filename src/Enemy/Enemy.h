#pragma once
#include "../ObjectBase.h"
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include <cinder/gl/gl.h>
#include "../Animation/Animation.h"
#include "../Animation/Production/Dead/Dead.h"
class Enemy : public ObjectBase {
protected:
	int attack_point;
	int range;
	float attack_speed;
	float attack_default;
public:
	Enemy(const ci::vec2& pos, const ci::vec2& size,
		const int& hp, const int& attack, const int& range, const float& attack_speed,
		const std::string& path)
		: ObjectBase(pos, size) , attack_point(attack),range(range),
		attack_speed(attack_speed), attack_default(attack_speed){
	}
	virtual void setup();
	virtual void update(const float& delta_time);
	virtual void draw();
	void attackPlayer(std::shared_ptr<ObjectBase>& player) {};
	void isDead();
};