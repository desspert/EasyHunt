#pragma once
#include <iostream>

class Weapon {
private:
	int attack;
	int radius;
	int attack_speed;
	std::string type;
public:

	Weapon(const int& attack, const float& attack_speed, const std::string& type)
		:attack(attack), attack_speed(attack_speed), type(type) {}

};