#include "Title.h"

void Title::update(const float& delta_time)
{
	
	ui.update(delta_time);
	
}

void Title::draw()
{
	ui.draw();
	
	
}

void Title::setup()
{
	
	ui.setup(dess::SceneName::TITLE);
	
}

void Title::touchesBegan(ci::app::TouchEvent event)
{
}

void Title::touchesMoved(ci::app::TouchEvent event)
{
}

void Title::touchesEnded(ci::app::TouchEvent event)
{
}

void Title::mouseDown(const ci::app::MouseEvent& event)
{
}

void Title::mouseDrag(const ci::app::MouseEvent& event)
{
}

void Title::mouseUp(const ci::app::MouseEvent& event)
{
}

