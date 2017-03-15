#pragma once
#include "../Enemy.h"
#include "../../Animation/AttackAnimation/EnemyAttack/Scratch/Scratch.h"
#include "../../Animation/AttackAnimation/EnemyAttack/Shelling/Shelling.h"
#include "../../Animation/AttackAnimation/EnemyAttack/Magic/Magic.h"
class Boss;
using boss_coroutine = boost::coroutines::coroutine<Boss*>;
enum BossState {
	SCRATCH = 0,
	EXPRODE = 1,
	MAGIC = 2,
	SHOOTINGSTAR = 3,
	ANGER = 4,
	SCREAM = 5
};
 
class Boss : public Enemy {
protected:
	ci::vec2 move_vec;
	ci::vec2 attack_pos;
	std::vector<CoroutineInfo> boss_info;
	boss_coroutine::push_type boss_startCoroutine;
	bool is_attack;
	bool is_move;
	float bosss_time;
	BossState state;
public:
	Boss(const ci::vec2& pos, const ci::vec2& size,
		const int& hp, const int& attack, const int& range, const float& attack_speed,
		const std::string& path) : Enemy(pos, size, hp, attack, range, attack_speed, path)
		, boss_startCoroutine(bossCoroutine)
	{
		texture = TEX.get(path);
		SE.registerBufferPlayerNode("BossScream1", "SE/boss_scream.mp3");
		SE.registerBufferPlayerNode("BossScream2", "SE/scream.mp3");
		this->hp = hp;
		hp_max = hp;
		state = SCRATCH;
		is_move = true;
		bosss_time = 0;
	}

	static void bossCoroutine(boss_coroutine::pull_type & yield) {
		{

			while (true)
			{
				while (true)
				{

					for (unsigned int i = 0; i < yield().get()->boss_info.size(); i++)
					{
						yield().get()->bosss_time = yield().get()->boss_info[i].time;
						yield().get()->boss_info[i].callback();
						yield();
					}
					std::random_device rd;
					std::mt19937 mt(rd());
					std::uniform_real_distribution<float> random_x(1, 3);
					std::uniform_real_distribution<float> random_y(1, 3);
					float buf_x = random_x(mt);
					yield().get()->state = (BossState)((int)buf_x);
					yield().get()->is_move = false;
					yield().get()->stateChange();
					break;
				}
			}


		}
	}
	void scatch(std::shared_ptr<Player>& player);
	void exprode(std::shared_ptr<Player>& player);
	void magic(std::shared_ptr<Player>& player);
	void shootingStar(std::shared_ptr<Player>& player);
	void anger(std::shared_ptr<Player>& player);
	void scream(std::shared_ptr<Player>& player);
	void stateChange();
	void setup();
	void update(const float& delta_time);
	void draw();
	void attackPlayer(std::shared_ptr<Player>& player);


};
