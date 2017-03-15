#include "NormalEnemy.h"
#include "../../Player/Player.h"
void NormalEnemy::setup()
{
	Enemy::setup();
	
}

void NormalEnemy::update(const float & delta_time)
{
	Enemy::update(delta_time);
	attack_speed -= delta_time;
	if (attack_speed < 0) {
		is_attack = true;
	}
}

void NormalEnemy::draw()
{
	Enemy::draw();
}

void NormalEnemy::attackPlayer(std::shared_ptr<Player>& player)
{
	if (CollisionCircleToCircle(pos, range * 2, player->getPos(), player->getRradius())) {
		pos.x += (player->getPos().x - pos.x)*0.01f;
		pos.y += (player->getPos().y - pos.y)*0.01f;
	}
	if (CollisionCircleToCircle(pos, range, player->getPos(), player->getRradius())) {
		if (is_attack) {
			ANIMATION.animationAdd<Scratch>(pos + returnCircleToCircle(pos, player->getPPos()),
				player,
				attack_point,
				range);
			is_attack = false;
			attack_speed = attack_default;
		}

	}

}
