#include "GasyaSpawn.h"

void GasyaSpawn::update(const float & delta_time)
{
	int index;
	animation_count++;
	index = (animation_count) % all_seets;


	float x = (index) % static_cast<int>(seets.x) * cut.x;
	float y = (index) / static_cast<int>(seets.y) * cut.y;


	texture->setCleanBounds(ci::Area(ci::Rectf(x, y, x + cut.x, y + cut.y)));

	if (animation_count >= 60) {
		is_active = false;

	}
}

void GasyaSpawn::draw()
{
	ci::gl::pushModelMatrix();
	texture->bind();
	ci::gl::translate(pos);
	ci::gl::translate(ci::vec2(-size.x / 2, -size.y / 2));
	ci::Rectf drawRect(ci::vec2(
		0,
		0),
		ci::vec2(
			size.x,
			size.y));

	ci::gl::draw(texture, drawRect);
	texture->unbind();
	ci::gl::popModelMatrix();
}





