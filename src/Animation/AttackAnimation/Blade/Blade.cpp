#include "Blade.h"


void Blade::attackUpdate()
{
	

	int index;
	animation_count++;

	index = (animation_count / 2) % all_seets;
	if (animation_count == 2) {
		SE.find("blade")->start();
	}

	float x = (index) % static_cast<int>(seets.x) * cut.x;
	//float y = (index) / static_cast<int>(seets.y) * cut.y;


	texture->setCleanBounds(ci::Area(ci::Rectf(x, 0, x + cut.x, 0 + cut.y)));

	if (animation_count == 15) {
		is_animaion = false;

	}
	if (animation_count == 3) {
		is_draw_damage = true;
		
	}

}




void Blade::update()
{
	attackUpdate();
	AttackAnimation::damageUpdate();
}

void Blade::draw() {
	AttackAnimation::draw();
	AttackAnimation::drawDamage();
}


