#include "Animation.h"



void Animation::draw()
{
	for (auto& it : anim) {
		it->draw();
	}
}

void Animation::updae()
{
	for (auto& it : anim) {
		it->update();
	}
}

void Animation::destroy()
{
	anim.clear();
}


void Animation::setup()
{
//	textures[AnimationType::Blade] = ci::gl::Texture2d::create(ci::loadImage(ci::app::loadAsset(data.texture_data[AnimationType::Blade])));
}
