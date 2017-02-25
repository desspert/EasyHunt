#include "GasyaEnd.h"

void GasyaEnd::update(const float & delta_time)
{
	int index;
	animation_count++;
	index = (animation_count) % all_seets;


	float x = (index) % static_cast<int>(seets.x) * cut.x;
	float y = (index) / static_cast<int>(seets.x) * cut.y;


	texture->setCleanBounds(ci::Area(ci::Rectf(x, y, x + cut.x, y + cut.y)));

	if (animation_count >= 120) {
		is_active = false;

	}
}

void GasyaEnd::draw()
{
	if (animation_count == 0) return;
	ci::gl::pushModelMatrix();
	texture->bind();
	ci::gl::color(ci::ColorA(1, 1, 1, 0.5f));
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
	ci::gl::color(ci::ColorA::white());
	ci::gl::popModelMatrix();
}





