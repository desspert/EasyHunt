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
	void update(const float& delta_time) override;
	void draw() override;
	void setup() override;
	void touchesBegan(ci::app::TouchEvent event);
	void touchesMoved(ci::app::TouchEvent event);
	void touchesEnded(ci::app::TouchEvent event);
	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
};