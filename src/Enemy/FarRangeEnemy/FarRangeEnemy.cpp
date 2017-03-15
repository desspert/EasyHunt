#include "FarRangeEnemy.h"
#include "../../Player/Player.h"
void FarEnemy::setup()
{
	Enemy::setup();
}

void FarEnemy::update(const float & delta_time)
{
	Enemy::update(delta_time);
	attack_speed -= delta_time;
	if (attack_speed < 0) {
		is_attack = true;
	}
}

void FarEnemy::draw()
{
	Enemy::draw();
}

void FarEnemy::attackPlayer(std::shared_ptr<Player>& player)
{
	if (RectToCircle(pos - ci::vec2(300, 300), size + ci::vec2(600, 600),0, player->getPos(), player->getRradius())) {
		
		pos.y +=  (player->getPos().y - pos.y) * 0.01f;
	}
	if (CollisionCircleToCircle(pos, range, player->getPos(), player->getRradius())) {
		if (is_attack) {
			ci::vec2 buf = returnCircleToCircle(pos, player->getPos());
			ANIMATION.animationAdd<Shelling>(pos - ci::vec2(size.x*2, size.y / 2),
				player,
				attack_point,
				ci::vec2(size.x * 4,size.y),
				std::atan2f(buf.y, buf.x));
			is_attack = false;
			attack_speed = attack_default;
		}

	}

}
