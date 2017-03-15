#include "MagicEnemy.h"
#include "../../Player/Player.h"
void MagicEnemy::setup()
{
	Enemy::setup();

}

void MagicEnemy::update(const float & delta_time)
{
	Enemy::update(delta_time);
	attack_speed -= delta_time;
	if (attack_speed < 0) {
		is_attack = true;
	}
}

void MagicEnemy::draw()
{
	Enemy::draw();
}

void MagicEnemy::attackPlayer(std::shared_ptr<Player>& player)
{
	if (CollisionCircleToCircle(pos, range * 2, player->getPos(), player->getRradius())) {
		if (CollisionCircleToCircle(pos, range, player->getPos(), player->getRradius())) {
			if (is_attack) {
				ANIMATION.animationAdd<Magic>(pos,
					player,
					attack_point,
					range);
				is_attack = false;
				attack_speed = attack_default;
			}

		}
		else {
			pos.x += (player->getPos().x - pos.x)*0.02f;
			pos.y += (player->getPos().y - pos.y)*0.02f;
		}
	}
	

}
