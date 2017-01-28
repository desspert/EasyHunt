#pragma once
#include "../../AnimationBase.h"

class Blade : public AnimationBase {
private:
	std::shared_ptr<ObjectBase> obj;
	int attack;
	int damage_frame;
public:

	Blade(const std::shared_ptr<ObjectBase>& obj, ci::gl::TextureRef copy_tex) :obj(obj),AnimationBase(copy_tex){
		size = ci::vec2(100, 100);
		pos = obj->getCenter();
		cut = ci::vec2(256, 0);
		seets = ci::vec2(6, 0);
		all_seets = 6;
		animation_count = 0;
	}
	Blade(const ci::vec2& pos,const std::shared_ptr<ObjectBase>& obj, ci::gl::TextureRef copy_tex) :obj(obj), AnimationBase(copy_tex,pos) {
		size = ci::vec2(100, 100);
		cut = ci::vec2(256, 256);
		seets = ci::vec2(6, 0);
		all_seets = 6;
		animation_count = 0;
	}
	void update();
	void draw();
};