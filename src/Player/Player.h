#pragma once
#include "../ObjectBase.h"
#include <cinder/app/App.h>
#include "../ProductionCamera/ProductionCamera.h"
class Player : public ObjectBase
{
private:
	ci::vec2 pos_begin;
	ci::vec2 pos_moved;
	ci::vec2 pos_end;
	
public:
	Player(const ci::vec2& pos, const ci::vec2& size) : ObjectBase(pos,size){
		pos_begin = ci::vec2(0);
		pos_moved = ci::vec2(0);
		pos_end = ci::vec2(0);
		
	}
	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
	void update();
	void draw();
};