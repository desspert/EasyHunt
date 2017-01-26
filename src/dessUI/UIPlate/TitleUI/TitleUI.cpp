#include "TitleUI.h"

//bool TitleUI::init()
//{
//	UIManager::Setup(SceneName::TITLE);
//	if (!UIPlate::init()) {
//		return false;
//	}
//	
//	ui_data["わっふぉい"]->Active();
//	ui_data["背景"]->Active();
//	ui_data["画面下"]->Active();
//	ui_data["アニメーション"]->Active();
//	ui_data["フォント"]->timeStart();
//	return true;
//}
//
//void TitleUI::update(float delta)
//{
//	UIPlate::update(delta);
//	ui_data["フォント"]->deltaTimeUpdate(delta);
//	ui_label["フォント"]->setString(ui_data["フォント"]->timeGetMinutes() + ":" + ui_data["フォント"]->timeGetSeconds() + ":" + ui_data["フォント"]->timeGetFlame());
//	ui_sprite["わっふぉい"]->setPosition(cocos2d::Vec2(ui_data["わっふぉい"]->getPosX(), ui_data["わっふぉい"]->getPosY()));
//	ui_sprite["背景"]->setPosition(cocos2d::Vec2(ui_data["背景"]->getPosX(), ui_data["背景"]->getPosY()));
//}
//
//bool TitleUI::onTouchBgan(cocos2d::Touch * touch, cocos2d::Event *)
//{
//	
//
//	return false;
//}

void TitleUI::setup(const dess::SceneName & name)
{
	UIPlate::setup(name);
	ui_data[u8"背景"]->Active();
}

void TitleUI::update(const int& delta_frame)
{
	UIPlate::update(delta_frame);
}

void TitleUI::draw()
{
	UIPlate::draw();
}

void TitleUI::mouseDown(ci::app::MouseEvent event)
{
}

void TitleUI::mouseDrag(ci::app::MouseEvent event)
{
}

void TitleUI::mouseUp(ci::app::MouseEvent event)
{
}
