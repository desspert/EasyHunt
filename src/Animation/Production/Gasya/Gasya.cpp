#include "Gasya.h"

void Gasya::update(const float & delta_time)
{
	int index;
	animation_count++;

	index = (animation_count/4) % all_seets;


	float x = (index % 2) * cut.x;
	float y = (index / 2) * cut.y;


	texture->setCleanBounds(ci::Area(ci::Rectf(x, y, x + cut.x, y + cut.y)));

	if (animation_count >= 80) {
		is_active = false;

	}
}

void Gasya::draw()
{
	ci::gl::pushModelMatrix();
	texture->bind();
	ci::gl::translate(pos);
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
