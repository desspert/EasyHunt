#pragma once
#include "AnimationBase.h"
#include "AnimationType.h"
#include <memory>
#include <functional>

#define ANIMATION Animation::get()

class Animation {
private:
	std::list<std::shared_ptr<AnimationBase>> anim;
	std::map<AnimationType,std::function<void()>> function;
	std::map<AnimationType, ci::gl::TextureRef> textures;
	std::vector<ci::gl::TextureRef> attack_texture;
	AnimationData data;
	ci::Font font;
	
public:
	Animation(){}
	void setup();
	template<class AnimationClass, class... Args>
	void animationAdd(Args... args);
	void draw();
	void update(const float& delta_time);
	void destroy();

	ci::Font getFont() {
		return font;
	}
	std::vector<ci::gl::TextureRef> getAttackTexture() {
		return attack_texture;
	}
	std::map<AnimationType, ci::gl::TextureRef> getTexture() {
		return textures;
	}

	static Animation& get() {
		static Animation anim;
		return anim;
	}
};

template<class AnimationClass, class ...Args>
inline void Animation::animationAdd(Args ...args)
{
	anim.push_back(std::make_shared<AnimationClass>(args...));
}
