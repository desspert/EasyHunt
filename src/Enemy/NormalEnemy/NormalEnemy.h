#pragma once
#include "../Enemy.h"
#include "../../Animation/AttackAnimation/EnemyAttack/Scratch/Scratch.h"
class NormalEnemy : public Enemy {
protected:
	ci::vec2 move_vec;
	ci::vec2 attack_pos;
	bool is_attack;
public:
	NormalEnemy(const ci::vec2& pos, const ci::vec2& size,
		const int& hp, const int& attack, const int& range, const float& attack_speed,
		const std::string& path) : Enemy(pos, size,hp,attack, range, attack_speed, path) {
		texture =  TEX.get(path);
		this->hp = hp;
		hp_max = hp;
	}
	void setup();
	void update(const float& delta_time);
	void draw();
	void attackPlayer(std::shared_ptr<ObjectBase>& player);
};