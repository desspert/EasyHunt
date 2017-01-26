#include "Title.h"

void Title::update(const int& delta_frame)
{
	
	ui.update(delta_frame);
	
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

