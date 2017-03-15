#include "TouchMove.h"

void TouchMove::update(const float & delta_time)
{
	int index;
	animation_count++;
	index = (animation_count) % all_seets;


	float x = (index) % static_cast<int>(seets.x) * cut.x;
	float y = (index) / static_cast<int>(seets.x) * cut.y;


	texture->setCleanBounds(ci::Area(ci::Rectf(x, y, x + cut.x, y + cut.y)));


}

void TouchMove::draw()
{
	if (animation_count == 0) return;
	ci::gl::pushModelMatrix();
	texture->bind();
	ci::gl::color(1, 1, 1, 0.5f);
	ci::gl::translate(pos);
	ci::gl::rotate(angle - 90* M_PI/180);
	ci::gl::translate(ci::vec2(-size.x / 2, 0));
	ci::Rectf drawRect(ci::vec2(
		0,
		0),
		ci::vec2(
			size.x,
			size.y));

	ci::gl::draw(texture, drawRect);
	texture->unbind();
	ci::gl::color(1, 1, 1, 1);
	ci::gl::popModelMatrix();
}





