#pragma once
#include <iostream>
#include<cinder/app/App.h>
#include "../ObjectBase.h"
class AnimationBase {
private:
	bool is_active;
	ci::vec2 pos;
	ci::vec2 size;
	int attack;
	int damage_frame;
public:
	AnimationBase() {

	}
	virtual void animation(int delta_frame);

};