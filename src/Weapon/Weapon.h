#pragma once
#include <iostream>

class Weapon {
private:
	
public:
	int attack;
	int range;
	float attack_speed;
	std::string type;
	Weapon(const int& attack, const float& attack_speed, const int& range, const std::string& type)
		:attack(attack), range(range), attack_speed(attack_speed), type(type) {}

};