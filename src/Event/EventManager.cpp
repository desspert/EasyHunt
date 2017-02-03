#include "EventManager.h"

void EventManager::setup()
{
	TEX.set("map", "map.png");
	TEX.set("Slashing", "Attack/attack.png");
}

void EventManager::update(const float & delta_time)
{
}

void EventManager::draw()
{
	//ci::gl::pushModelView();
	//
	//ci::gl::translate(ci::vec3(0, 0, 0));
	//ci::gl::scale(ci::vec3(1));
	//ci::gl::drawCube(ci::vec3(0, -300, -300), ci::vec3(3000, 3000, 1));
	//ci::gl::popModelView();
}
