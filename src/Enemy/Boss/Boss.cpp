#include "Boss.h"
#include "../../Player/Player.h"
void Boss::scatch(std::shared_ptr<Player>& player)
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
void Boss::exprode(std::shared_ptr<Player>& player)
{
	if (RectToCircle(pos - ci::vec2(300, 300), size + ci::vec2(600, 600), 0, player->getPos(), player->getRradius())) {

		pos.y += (player->getPos().y - pos.y) * 0.1f;
	}
	if (CollisionCircleToCircle(pos, range, player->getPos(), player->getRradius())) {
		if (is_attack) {
			ci::vec2 buf = returnCircleToCircle(pos, player->getPos());
			ANIMATION.animationAdd<Shelling>(pos - ci::vec2(size.x * 2, size.y / 2),
				player,
				attack_point,
				ci::vec2(size.x * 4, size.y),
				std::atan2f(buf.y, buf.x));
			is_attack = false;
			attack_speed = attack_default;
		}

	}

}
void Boss::magic(std::shared_ptr<Player>& player)
{
	if (CollisionCircleToCircle(pos, range * 2, player->getPos(), player->getRradius())) {
		if (CollisionCircleToCircle(pos, range*3, player->getPos(), player->getRradius())) {
			if (is_attack) {
				ANIMATION.animationAdd<Magic>(pos,
					player,
					attack_point,
					range*3);
				is_attack = false;
				attack_speed = attack_default;
			}

		}
	}
}
void Boss::shootingStar(std::shared_ptr<Player>& player)
{
}
void Boss::anger(std::shared_ptr<Player>& player)
{
}
void Boss::scream(std::shared_ptr<Player>& player)
{
}
void Boss::stateChange()
{
	boss_info.clear();
	c_info.clear();
	boss_info.push_back(CoroutineInfo(0, [this]() {
		SE.find("BossScream1")->start();
		SE.find("BossScream2")->start();
		CAMERA.shakeCamera(5, 3);
		return;
	}));
	boss_info.push_back(CoroutineInfo(4, [this]() {
		is_move = true;
		return;
	}));
	boss_info.push_back(CoroutineInfo(8, [this]() {
		return;
	}));
}
void Boss::setup()
{
	Enemy::setup();
	boss_info.push_back(CoroutineInfo(15, [this]() {
		return;
	}));
}

void Boss::update(const float & delta_time)
{
	Enemy::update(delta_time);
	attack_speed -= delta_time;
	if (attack_speed < 0) {
		is_attack = true;
	}
	bosss_time -= delta_time;
	if (bosss_time < 0)
	{
		boss_startCoroutine(this);
		bosss_time = bosss_time;
	}
}

void Boss::draw()
{
	Enemy::draw();
}

void Boss::attackPlayer(std::shared_ptr<Player>& player)
{
	if (!is_move) return;
	switch (state) {
	case SCRATCH:
		scatch(player);
		break;
	case EXPRODE:
		exprode(player);
		break;
	case MAGIC:
		magic(player);
		break;
	case SHOOTINGSTAR:
		shootingStar(player);
		break;
	case ANGER:
		anger(player);
		break;
	case SCREAM:
		scream(player);
		break;
	}


}
