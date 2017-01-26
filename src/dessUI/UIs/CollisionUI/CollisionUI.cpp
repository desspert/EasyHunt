#include "CollisionUI.h"



void CollisionUI::animation()
{
}

void CollisionUI::update()
{
	if (is_active) {
		EaseInUpdate();

		EaseOutUpdate();

		EaseUpdate();

		EaseCollisionUpdate();
	}
}

bool CollisionUI::collisionToUI(des::Vec2f _pos)
{

	if (des::collisionPlateToPoint(pos, size, _pos)) {
		for (int i = 0; i != ease_collision_buf.size(); i++) {
			if ("Pos" == ease_collision_buf[i].start) {
				c_Easing::apply(pos.x,
					ease_collision_buf[i].end[0], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(pos.y,
					ease_collision_buf[i].end[1], ease_collision_buf[i].ease, ease_collision_buf[i].time);
			}

			if ("Size" == ease_collision_buf[i].start) {
				c_Easing::apply(size.x,
					ease_collision_buf[i].end[0], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(size.y,
					ease_collision_buf[i].end[1], ease_collision_buf[i].ease, ease_collision_buf[i].time);
			}

			if ("Color" == ease_collision_buf[i].start) {
				c_Easing::apply(color.x,
					ease_collision_buf[i].end[0], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(color.y,
					ease_collision_buf[i].end[1], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(color.z,
					ease_collision_buf[i].end[2], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(color.w,
					ease_collision_buf[i].end[3], ease_collision_buf[i].ease, ease_collision_buf[i].time);
			}
		}
		return true;
	}
	return false;
}

bool CollisionUI::collisionToUI(des::Vec2f _pos, des::Vec2f _size)
{
	if (des::collisionPlateToPlate(pos, size, _pos, _size)) {
		for (int i = 0; i != ease_collision_buf.size(); i++) {
			if ("Pos" == ease_collision_buf[i].start) {
				c_Easing::apply(pos.x,
					ease_collision_buf[i].end[0], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(pos.y,
					ease_collision_buf[i].end[1], ease_collision_buf[i].ease, ease_collision_buf[i].time);
			}

			if ("Size" == ease_collision_buf[i].start) {
				c_Easing::apply(size.x,
					ease_collision_buf[i].end[0], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(size.y,
					ease_collision_buf[i].end[1], ease_collision_buf[i].ease, ease_collision_buf[i].time);
			}

			if ("Color" == ease_collision_buf[i].start) {
				c_Easing::apply(color.x,
					ease_collision_buf[i].end[0], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(color.y,
					ease_collision_buf[i].end[1], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(color.z,
					ease_collision_buf[i].end[2], ease_collision_buf[i].ease, ease_collision_buf[i].time);
				c_Easing::apply(color.w,
					ease_collision_buf[i].end[3], ease_collision_buf[i].ease, ease_collision_buf[i].time);
			}
		}
		return true;
	}
	return false;
}

void CollisionUI::EaseCollisionApply(std::string start, float end[4], std::function<float(float, float, float)> ease, float time)
{
	ease_collision_buf.push_back(EasingBuf(start, end, ease, time));
}

void CollisionUI::EaseCollisionUpdate()
{


}