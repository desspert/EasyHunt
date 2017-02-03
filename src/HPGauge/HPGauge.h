#pragma once
#include <cinder/app/App.h>
#include "../dessUI/Easing/Easing.h"
#include <cinder/gl/gl.h>
class HPGauge {
private:
	ci::vec2 hp_pos;
	ci::vec2 hp_size;
	ci::vec2 damage_pos;
	ci::vec2 damage_size;
	ci::vec2 back_pos;
	ci::vec2 back_size;
	ci::vec2 frame_pos;
	ci::vec2 frame_size;
	float gauge_min;
	float gauge_max;
	float update_gauge;
	bool is_min;
	bool is_max;
	
public :

	HPGauge() {
		hp_pos = ci::vec2(0, 0);
		hp_size = ci::vec2(100, 30);
		damage_pos = ci::vec2(0, 0);
		damage_size = ci::vec2(100, 30);
		back_pos = ci::vec2(0, 0);
		back_size = ci::vec2(100, 30);
		frame_pos = ci::vec2(-10, -10);
		frame_size = ci::vec2(110, 40);
		gauge_min = hp_pos.x;
		gauge_max = hp_size.x;
		update_gauge = 3.0f;
		is_min = false;
		is_max = false;
	}
	const bool& getMax() {
		return is_max;
	}

	const bool& getMin() {
		return is_min;
	}

	void changeGauge(const float & value, const float & max);

	
	void update(const float & delta_time);
	void draw(const ci::vec2& pos, const ci::vec2& scale);
};