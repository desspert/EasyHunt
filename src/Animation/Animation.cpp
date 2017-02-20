#include "Animation.h"



void Animation::draw()
{
	for (auto& it : anim) {
		it->draw();
	}
}

void Animation::update(const float& delta_time)
{
	for (auto& it : anim) {
		it->update(delta_time);
	}
	for (auto it = anim.begin(); it != anim.end(); it++ ) {
		if (!it->get()->isActive()) {
			anim.erase(it);
			break;
		}
	}
}

void Animation::destroy()
{
	anim.clear();
}


void Animation::setup()
{
	
	
}
