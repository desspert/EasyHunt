#include "Blade.h"


void Blade::update()
{

	int index;
	animation_count ++;

	index = (animation_count/2) % all_seets;
	if (animation_count == 2) {
		//‰¹–Â‚ç‚·
	}
	
	float x =(index) % static_cast<int>(seets.x) * cut.x;
	//float y = (index) / static_cast<int>(seets.y) * cut.y;

	
	texture->setCleanBounds(ci::Area(ci::Rectf(x, 0, x + cut.x,0 + cut.y )));
	if (animation_count == 30) {
		is_active = false;
	}
}

void Blade::draw()
{
	texture->bind();
	
	ci::Rectf drawRect(ci::vec2(
		pos.x - size.x / 2,
		pos.y - size.y / 2),
		ci::vec2(
			pos.x + size.x,
			pos.y + size.y));

	ci::gl::draw(texture, drawRect);

	texture->unbind();
	
}
