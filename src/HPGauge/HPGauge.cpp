#include "HPGauge.h"


void HPGauge::changeGauge(const float& value,const float& max)
{
	if (value > max) {
		is_max = true;
		is_min = false;
		hp_size.x =  gauge_max;
	}
	else if (value == max) {
		is_min = false;
		is_max = true;
		hp_size.x = (value / max) * gauge_max;
	}
	else {
		is_min = false;
		is_max = false;
		hp_size.x = (value / max) * gauge_max;
	}
	if (value <= 0) {
		is_min = true;
		hp_size.x = 0;
	}
}



void HPGauge::update(const float & delta_time)
{
	update_gauge -= delta_time;
	if (update_gauge < 0.0f) {
		c_Easing::apply(damage_size.x, hp_size.x, EasingFunction::CircOut, 20);
		update_gauge = 3.0f;
	}
}

void HPGauge::draw(const ci::vec2& pos, const ci::vec2& scale)
{
	

	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::scale(scale);
	ci::gl::color(1, 1, 0, 1);
	ci::gl::drawSolidRect(ci::Rectf(frame_pos, frame_size), ci::vec2(0, 1), ci::vec2(1, 0));
	ci::gl::color(1, 1, 1, 1);
	ci::gl::popModelMatrix();

	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::scale(scale);
	ci::gl::color(0.2f, 0.2f, 0.2f, 1);
	ci::gl::drawSolidRect(ci::Rectf(back_pos, back_size), ci::vec2(1, 1), ci::vec2(1, 1));
	ci::gl::color(1, 1, 1, 1);
	ci::gl::popModelMatrix();

	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::scale(scale);
	ci::gl::color(1, 0, 0, 1);
	ci::gl::drawSolidRect(ci::Rectf(damage_pos, damage_size), ci::vec2(1, 1), ci::vec2(1, 1));
	ci::gl::color(1, 1, 1, 1);
	ci::gl::popModelMatrix();

	ci::gl::pushModelMatrix();
	ci::gl::translate(pos);
	ci::gl::scale(scale);
	ci::gl::color(0, 0.7f, 0, 1);
	ci::gl::drawSolidRect(ci::Rectf(hp_pos, hp_size), ci::vec2(1, 1), ci::vec2(1, 1));
	ci::gl::color(1, 1, 1, 1);
	ci::gl::popModelMatrix();
}

