#pragma once
#include "AttackAnimation/Blade/Blade.h"
#include <unordered_map>
enum class AnimationType {
	Blade
};

class AnimationData {
public:
	std::map<AnimationType, std::string> texture_data;
	AnimationData() {
		texture_data[AnimationType::Blade] = "attack.png";
	}
	
};
