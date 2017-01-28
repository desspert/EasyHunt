#pragma once
#include "AnimationBase.h"
#include "AnimationType.h"
#include <memory>
#include <functional>

#define ANIMATION Animation::get()

class Animation {
private:
	std::list<std::shared_ptr<AnimationBase>> anim;
	//std::unordered_map<AnimationType,std::function<void()>> function;
	//std::unordered_map<AnimationType, ci::gl::TextureRef> textures;
	AnimationData data;
public:
	Animation(){}
	void setup();
	template<class AnimationClass, class... Args>
	void animationAdd(Args... args);
	void draw();
	void updae();
	void destroy();

//	std::unordered_map<AnimationType, ci::gl::TextureRef> getTexture() {
//		return textures;
//	}

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
