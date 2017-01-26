#include "Title.h"

void Title::update()
{
	
	ui.update();
	
}

void Title::draw()
{
	ui.draw();
	
	
}

void Title::setup()
{
	
	ui.setup(dess::SceneName::TITLE);
	
}

void Title::touchesBegan(TouchEvent event)
{
}

void Title::touchesMoved(TouchEvent event)
{
}

void Title::touchesEnded(TouchEvent event)
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

