#pragma once
#include "cinder/app/App.h"
#include "dessUI/Easing/Easing.h"
#include "HPGauge/HPGauge.h"
#include "dessUI/Texture.h"
#include "Event/Coroutine.h"
class Player;
static bool CollisionCircleToCircle(const ci::vec2& center1, const float& r1, const ci::vec2& center2, const float& r2) {
	float x = (center1.x - center2.x)*(center1.x - center2.x);
	float y = (center1.y - center2.y)*(center1.y - center2.y);
	float r = (r1 + r2) * (r1 + r2);
	if (x + y <= r) {
		return true;
	}
	return false;
}

static float findDistance(float x1, float y1, float x2, float y2) {
	float a = std::abs(x1 - x2);
	float b = std::abs(y1 - y2);

	float c = std::sqrt((a * a) + (b * b));
	return c;
}
static bool RectToCircle(ci::vec2 pos1, ci::vec2 size1, float angle, ci::vec2 circle, float raduis) {
	ci::vec2 center1 = ci::vec2(pos1.x + size1.x / 2, pos1.y + size1.y / 2);
	// ãÈå`ÇOìxÇÃéûÇÃç¿ïWÇ…â~ÇÃäpìxÇíºÇ∑ÅB
	float cx = std::cos(angle) * (circle.x - center1.x) -
		std::sin(angle) * (circle.y - center1.y) + center1.x;
	float cy = std::sin(angle) * (circle.x - center1.x) +
		std::cos(angle) * (circle.y - center1.y) + center1.y;

	// è„ÇÃâ~ÇÃíÜêSì_Ç©ÇÁãÈå`ÇÃÇPî‘ãﬂÇ¢ç¿ïW
	float x, y;

	// ÇPî‘ãﬂÇ¢xç¿ïWÇãÅÇﬂÇÈ
	if (cx < pos1.x)
		x = pos1.x;
	else if (cx > pos1.x + size1.x)
		x = pos1.x + size1.x;
	else
		x = cx;

	// ÇPî‘ãﬂÇ¢yç¿ïWÇãÅÇﬂÇÈ
	if (cy < pos1.y)
		y = pos1.y;
	else if (cy > pos1.y + size1.y)
		y = pos1.y + size1.y;
	else
		y = cy;



	float distance = findDistance(cx, cy, x, y);
	if (distance < raduis)
		return true; // è’ìÀ
	else
		return false;
}

static ci::vec2 returnCircleToCircle(const ci::vec2& center1, const ci::vec2& center2) {
	ci::vec2 buf =  center2 - center1;
	
	return buf;
}
class ObjectBase;
using object_coroutine = boost::coroutines::coroutine<ObjectBase*>;
 
class ObjectBase {
protected:
	HPGauge gauge;
	ci::vec2 pos;
	ci::vec2 size;
	ci::vec4 color;
	ci::gl::TextureRef	texture;
	float radius;
	int hp;
	int hp_max;
	bool is_dead;
	float dead_count;
	bool is_spawn;
	bool is_active;

	std::vector<CoroutineInfo> c_info;
	object_coroutine::push_type startCoroutine;
	float time;
	
public:
	
	ObjectBase(const ci::vec2& pos, const ci::vec2& size)
		:
		startCoroutine(objectCoroutine),pos(pos), size(size), radius(size.x / 2),
		color(ci::vec4(1,1,1,1)), is_dead(false),is_active(true),dead_count(0), is_spawn(false){
	}
	~ObjectBase() {}


	const ci::vec2& getPos() {
		return pos;
	}
	ci::vec2& getPPos() {
		return pos;
	}
	const ci::vec2& getSize() {
		return size;
	}
	ci::vec2& getPSize() {
		return size;
	}
	const float& getRradius() {
		return radius;
	}
	const ci::vec2& getCenter() {
		return pos + ci::vec2(size.x / 2, size.y / 2);
	}
	const bool& isActive() {
		return is_active;
	}
	const int& getHP() {
		return hp;
	}
	virtual void damage(const int& damage) {

		if (c_Easing::isEnd(color.b)) {
			c_Easing::apply(color.g, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.b, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.g, 1, EasingFunction::Linear, 4);
			c_Easing::apply(color.b, 1, EasingFunction::Linear, 4);
			c_Easing::apply(pos.x, pos.x +5, EasingFunction::BounceInOut, 1);
			c_Easing::apply(pos.x, pos.x - 5, EasingFunction::BounceInOut, 1);
		}
		else {
			c_Easing::clear(color.g);
			c_Easing::clear(color.b);
			c_Easing::apply(color.g, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.b, 0, EasingFunction::Linear, 1);
			c_Easing::apply(color.g, 1, EasingFunction::Linear, 4);
			c_Easing::apply(color.b, 1, EasingFunction::Linear, 4);
			c_Easing::apply(pos.x, pos.x +5, EasingFunction::BounceInOut, 1);
			c_Easing::apply(pos.x, pos.x -5, EasingFunction::BounceInOut, 1);
		}
		
		hp -= damage;
	
	}
	virtual void changeHP(const float& delta_time) {
		gauge.update(delta_time);
		gauge.changeGauge(static_cast<float>(hp), static_cast<float>(hp_max));
		if (gauge.getMin()) {

			is_dead = true;
		}
	}
	
	void setPos(const ci::vec2& pos) {
		this->pos = pos;
	}

	void setSize(const ci::vec2& size) {
		this->size = size;
	}
	void setSpawn(const bool& spawn) {
		is_spawn = spawn;
	}
	virtual void attackPlayer(std::shared_ptr<Player>& player) {};
	virtual void update(const float& delta_time) {
		time -= delta_time;
		if (time < 0)
		{
			startCoroutine(this);
			time = time;
		}
	} 
	static  void objectCoroutine(object_coroutine::pull_type & yield) {
		{
			while (true)
			{
				while (yield().get()->is_spawn)
				{
					for (unsigned int i = 0; i < yield().get()->c_info.size(); i++)
					{
						yield().get()->time = yield().get()->c_info[i].time;
						yield().get()->c_info[i].callback();
						yield();
					}
					yield().get()->is_spawn = false;
					break;
				}
				while (!yield().get()->is_spawn)
				{
					yield();
				}
			}
		}
	}
	virtual void draw() = 0;
	virtual void setup() = 0;
};
