#include "SelectUI.h"
#include"../../../SceneManager/SceneManager.h"
void SelectUI::setup(const dess::SceneName & name)
{
	UIPlate::setup(name);
	ui_data["BackBattle"]->setActive(true);
	ui_data["Battle"]->setActive(true);
	ui_data["Gasya"]->setActive(true);
	ui_data["Option"]->setActive(true);
	ui_data["Multi"]->setActive(true);
	ui_data["Solo"]->setActive(true);

}

void SelectUI::update(const float& delta_time)
{
	UIPlate::update(delta_time);
	for (auto it = ui_scrolls_key.begin(); it != ui_scrolls_key.end(); it++) {
		ui_scroll[(*it)]->update();
	}
	
}

void SelectUI::draw()
{
	
	UIPlate::draw();
	
	scroll_pos.y *= 0.95f;
	for (auto it = ui_scrolls_key.begin(); it != ui_scrolls_key.end(); it++) {

		if (!ui_scroll[(*it)]->getActive()) continue;
		ci::gl::pushModelView();
		ci::gl::color(ui_scroll[(*it)]->getColorR(), ui_scroll[(*it)]->getColorG(), ui_scroll[(*it)]->getColorB(), ui_scroll[(*it)]->getColorA());
		textures[(*it)]->bind();
		ui_scroll[(*it)]->setPos(ui_scroll[(*it)]->getPosX() + scroll_pos.x,
			ui_scroll[(*it)]->getPosY() + scroll_pos.y);
		ci::Rectf drawRect(ci::vec2(
			ui_scroll[(*it)]->getPosX(),
			ui_scroll[(*it)]->getPosY()),
			ci::vec2(
				ui_scroll[(*it)]->getPosX() + ui_scroll[(*it)]->getSizeX(),
				ui_scroll[(*it)]->getPosY() + ui_scroll[(*it)]->getSizeY()));

		ci::gl::draw(textures[(*it)], drawRect);
		ci::gl::color(1, 1, 1, 1);
		textures[(*it)]->unbind();
		ci::gl::popModelView();

	}
	
	
}

void SelectUI::mouseDown(ci::app::MouseEvent event)
{
	move_pos = event.getPos();
}

void SelectUI::mouseDrag(ci::app::MouseEvent event)
{
	scroll_pos.y += event.getPos().y - move_pos.y;
	scroll_pos.y *= 0.7f;
	move_pos = event.getPos();
}

void SelectUI::mouseUp(ci::app::MouseEvent event)
{
	if (**pause) return;
	for (auto it = ui_scrolls_key.begin(); it != ui_scrolls_key.end(); it++) {
		if (ui_scroll[(*it)]->collisionToUI(des::Vec2f(event.getPos().x, event.getPos().y))) {
			SE.find("Select")->start();
		}
	}
	if (ui_data["Option"]->collisionToUI(des::Vec2f(event.getPos().x, event.getPos().y))) {
		sceneOption();
	}

	if (!ui_data["BackGasya"]->getActive()) {
		if (ui_data["Gasya"]->collisionToUI(des::Vec2f(event.getPos().x, event.getPos().y))) {
			sceneGasya();
		}
		if (ui_data["Multi"]->collisionToUI(des::Vec2f(event.getPos().x, event.getPos().y))) {
			SE.find("Select")->start();
			ui_data["Solo"]->setActive(false);
			
			for (auto it = ui_scrolls_key.begin(); it != ui_scrolls_key.end(); it++) {
				ui_scroll[(*it)]->setActive(true);
			}
		}
		if (ui_data["Solo"]->collisionToUI(des::Vec2f(event.getPos().x, event.getPos().y))) {
			SE.find("Select")->start();
			is_end = true;
			return;
		}


	}


	if (!ui_data["BackBattle"]->getActive()) {
		if (ui_data["Battle"]->collisionToUI(des::Vec2f(event.getPos().x, event.getPos().y))) {
			sceneBattle();
		}
		if (ui_data["GasyaButton"]->collisionToUI(des::Vec2f(event.getPos().x, event.getPos().y))) {
			SE.find("Select")->start();
			is_gasya = true;
			**pause = true;
		}

	}


}

void SelectUI::touchesBegan(ci::app::TouchEvent event)
{
}

void SelectUI::touchesMoved(ci::app::TouchEvent event)
{
}

void SelectUI::touchesEnded(ci::app::TouchEvent event)
{
	//オプション中
	if (!ui_data["BackBattle"]->getActive()) {
		if (ui_data["Option"]->collisionToUI(des::Vec2f(event.getTouches()[0].getPos().x, event.getTouches()[0].getPos().y))) {
			sceneOption();
		}
	}

	//バトル中
	if (!ui_data["BackGasya"]->getActive()) {
		if (ui_data["Gasya"]->collisionToUI(des::Vec2f(event.getTouches()[0].getPos().x, event.getTouches()[0].getPos().y))) {
			sceneGasya();
		}
		if (ui_data["Multi"]->collisionToUI(des::Vec2f(event.getTouches()[0].getPos().x, event.getTouches()[0].getPos().y))) {
			SE.find("Select")->start();
			ui_data["Solo"]->setActive(false);
			for (auto it = ui_scrolls_key.begin(); it != ui_scrolls_key.end(); it++) {
				ui_scroll[(*it)]->setActive(true);
			}
			
		}
		if (ui_data["Solo"]->collisionToUI(des::Vec2f(event.getTouches()[0].getPos().x, event.getTouches()[0].getPos().y))) {
			SE.find("Select")->start();
			is_end = true;
		}


	}

	//ガシャ中
	if (!ui_data["BackBattle"]->getActive()) {
		if (ui_data["Battle"]->collisionToUI(des::Vec2f(event.getTouches()[0].getPos().x, event.getTouches()[0].getPos().y))) {
			sceneBattle();
		}
		if (ui_data["GasyaButton"]->collisionToUI(des::Vec2f(event.getTouches()[0].getPos().x, event.getTouches()[0].getPos().y))) {
			ANIMATION.animationAdd<Gasya>(ci::vec2(0,0), ci::vec2(640, 500));
		}

	}



}



void SelectUI::sceneBattle()
{
	ui_data["Solo"]->setActive(true);
	ui_data["Multi"]->setActive(true);
	ui_data["GasyaButton"]->setActive(false);
	ui_data["BackGasya"]->setActive(false);
	ui_data["BackBattle"]->setActive(true);
	SE.find("Select")->start();
}

void SelectUI::sceneGasya()
{
	ui_data["GasyaButton"]->setActive(true);
	ui_data["BackGasya"]->setActive(true);
	ui_data["BackBattle"]->setActive(false);
	ui_data["Solo"]->setActive(false);
	ui_data["Multi"]->setActive(false);
	for (auto it = ui_scrolls_key.begin(); it != ui_scrolls_key.end(); it++) {
		ui_scroll[(*it)]->setActive(false);
	}
	SE.find("Select")->start();
}

void SelectUI::sceneOption()
{
	ui_data["GasyaButton"]->setActive(false);
	ui_data["BackGasya"]->setActive(false);
	ui_data["BackBattle"]->setActive(false);
	ui_data["Solo"]->setActive(false);
	ui_data["Multi"]->setActive(false);
	for (auto it = ui_scrolls_key.begin(); it != ui_scrolls_key.end(); it++) {
		ui_scroll[(*it)]->setActive(false);
	}
	SE.find("Select")->start();
}

void SelectUI::multi()
{
}

void SelectUI::solo()
{
}

