#include "Animation.h"



void Animation::draw()
{
	for (auto& it : anim) {
		it->draw();
	}
}

void Animation::update()
{
	for (auto& it : anim) {
		it->update();
	}
	for (auto& it = anim.begin(); it != anim.end(); it++ ) {
		if (!it->get()->isActive()) {
			anim.erase(it);
			break;
		}
	}

	while (anim.size() > 15) {
		anim.erase(anim.begin());
	}
	
	ci::app::console() << anim.size() << std::endl;
}

void Animation::destroy()
{
	anim.clear();
}


void Animation::setup()
{
	font = ci::Font("Hiragino Maru Gothic ProN W4", 100);
	textures[AnimationType::Blade] = ci::gl::Texture2d::create(ci::loadImage(ci::app::loadAsset(data.texture_data[AnimationType::Blade])));
	attack_texture.push_back(ci::gl::Texture2d::create(ci::loadImage(ci::app::loadAsset("Attack/attack.png"))));
}
