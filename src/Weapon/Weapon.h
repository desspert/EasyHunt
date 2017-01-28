#pragma once
#include <iostream>

class Weapon {
private:
	
public:
	int attack;
	int radius;
	float attack_speed;
	std::string type;
	Weapon(const int& attack, const float& attack_speed, const std::string& type)
		:attack(attack), attack_speed(attack_speed), type(type) {}

};