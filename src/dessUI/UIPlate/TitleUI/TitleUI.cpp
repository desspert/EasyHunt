#include "TitleUI.h"

//bool TitleUI::init()
//{
//	UIManager::Setup(SceneName::TITLE);
//	if (!UIPlate::init()) {
//		return false;
//	}
//	
//	ui_data["����ӂ���"]->Active();
//	ui_data["�w�i"]->Active();
//	ui_data["��ʉ�"]->Active();
//	ui_data["�A�j���[�V����"]->Active();
//	ui_data["�t�H���g"]->timeStart();
//	return true;
//}
//
//void TitleUI::update(float delta)
//{
//	UIPlate::update(delta);
//	ui_data["�t�H���g"]->deltaTimeUpdate(delta);
//	ui_label["�t�H���g"]->setString(ui_data["�t�H���g"]->timeGetMinutes() + ":" + ui_data["�t�H���g"]->timeGetSeconds() + ":" + ui_data["�t�H���g"]->timeGetFlame());
//	ui_sprite["����ӂ���"]->setPosition(cocos2d::Vec2(ui_data["����ӂ���"]->getPosX(), ui_data["����ӂ���"]->getPosY()));
//	ui_sprite["�w�i"]->setPosition(cocos2d::Vec2(ui_data["�w�i"]->getPosX(), ui_data["�w�i"]->getPosY()));
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
	ui_data[u8"�w�i"]->Active();
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
