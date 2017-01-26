#pragma once
#include "../SceneBase.h"
#include "../../dessUI/UIPlate/TitleUI/TitleUI.h"

#include "../SceneManager.h"
class Title : public SceneBase
{
private:
	TitleUI ui;

public:
	Title(){}
	void update() override;
	void draw() override;
	void setup() override;
	void touchesBegan(TouchEvent event);
	void touchesMoved(TouchEvent event);
	void touchesEnded(TouchEvent event);
	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
};