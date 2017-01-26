#include "UIPlate.h"

//bool UIPlate::init()
//{
//	if (!Node::init()) {
//		return false;
//	}
//	scheduleUpdate();
//	for (auto it = ui_objects.begin(); it != ui_objects.end(); it++) {
//		if (ui_data[(*it)]->getUIType() == UITYPE::NormalUI ||
//			ui_data[(*it)]->getUIType() == UITYPE::CollisionUI ||
//			ui_data[(*it)]->getUIType() == UITYPE::GaugeUI) {
//			ui_sprite[(*it)] = cocos2d::Sprite::create(ui_data[(*it)]->getTexturePath());
//
//			ui_sprite[(*it)]->setPosition(cocos2d::Vec2(ui_data[(*it)]->getPosX(), ui_data[(*it)]->getPosY()));
//
//			float x = ui_data[(*it)]->getSizeX();
//			float y = ui_data[(*it)]->getSizeY();
//			float tx = ui_sprite[(*it)]->getContentSize().width;
//			float ty = ui_sprite[(*it)]->getContentSize().height;
//
//			ui_sprite[(*it)]->setScale(x / tx, y / ty);
//			ui_sprite[(*it)]->setVisible(ui_data[(*it)]->isActive());
//			this->addChild(ui_sprite[(*it)]);
//			
//		}
//		else if(!(ui_data[(*it)]->getUIType() == UITYPE::AnimationUI)){
//			ui_label[(*it)] = cocos2d::Label::createWithTTF(ui_data[(*it)]->timeGetMinutes() + ":" + ui_data[(*it)]->timeGetSeconds() + ":" + ui_data[(*it)]->timeGetFlame(), ui_data[(*it)]->fontGetPath(), ui_data[(*it)]->fontGetSize());
//			ui_label[(*it)]->setPosition(cocos2d::Vec2(ui_data[(*it)]->getPosX(),
//				ui_data[(*it)]->getPosY()));
//			ui_label[(*it)]->setVisible(ui_data[(*it)]->isActive());
//			this->addChild(ui_label[(*it)]);
//		}
//		if (ui_data[(*it)]->getUIType() == UITYPE::AnimationUI) {
//			std::vector<cocos2d::CCSpriteFrame*> ui_seats;
//			float WIDTH_SIZE = ui_data[(*it)]->animationGetCutSizeX();      
//			float HEIGHT_SIZE = ui_data[(*it)]->animationGetCutSizeY();    
//					  
//			
//			for (int y = 0; y<ui_data[(*it)]->animationGetSeatsY(); y++) {
//				for (int x = 0; x<ui_data[(*it)]->animationGetSeatsX(); x++) {
//					cocos2d::CCRect rect(float(x * WIDTH_SIZE),  
//						float(y * HEIGHT_SIZE), 
//						float(WIDTH_SIZE),      
//						float(HEIGHT_SIZE));    
//					ui_seats.push_back(cocos2d::CCSpriteFrame::create(ui_data[(*it)]->getTexturePath(), rect));
//				}
//			}
//			ui_animation_buf[(*it)] = cocos2d::CCAnimation::create();
//
//			for (int i = 0; i < (ui_data[(*it)]->animationGetSeatsX() * ui_data[(*it)]->animationGetSeatsY()); i++) {
//				ui_animation_buf[(*it)]->addSpriteFrame(ui_seats[i]);
//			}
//
//
//			ui_animation_buf[(*it)]->setDelayPerUnit(ui_data[(*it)]->animationGetBetween());
//
//			if (ui_data[(*it)]->animationGetIsLooping()) {
//				cocos2d::CCRepeatForever *pAction = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(ui_animation_buf[(*it)]));
//				ui_animation[(*it)] = cocos2d::CCSprite::create();
//
//				ui_animation[(*it)]->setPosition(cocos2d::ccp(ui_data[(*it)]->getPosX(), ui_data[(*it)]->getPosY()));
//				ui_animation[(*it)]->setVisible(ui_data[(*it)]->isActive());
//				this->addChild(ui_animation[(*it)]);
//
//				ui_animation[(*it)]->runAction(pAction);
//			}
//			else{
//				ui_static_animation[(*it)] = cocos2d::CCAnimate::create(ui_animation_buf[(*it)]);
//
//				ui_animation[(*it)] = cocos2d::CCSprite::create();
//
//				ui_animation[(*it)]->setPosition(cocos2d::ccp(ui_data[(*it)]->getPosX(), ui_data[(*it)]->getPosY()));
//				ui_animation[(*it)]->setVisible(ui_data[(*it)]->isActive());
//				this->addChild(ui_animation[(*it)]);
//
//				ui_animation[(*it)]->runAction(ui_static_animation[(*it)]);
//			}
//			
//			/*
//			float x = ui_data[(*it)]->getSizeX();
//			float y = ui_data[(*it)]->getSizeY();
//			float tx = pPlayer->getContentSize().width;
//			float ty = pPlayer->getContentSize().height;
//			pPlayer->setScale(x / tx, y / ty);*/
//		}
//	}
//
//	
//	
//	return true;
//}
//
//void UIPlate::update(float delta)
//{
//	for (auto it = ui_objects.begin(); it != ui_objects.end(); it++) {
//		if (ui_data[(*it)]->getUIType() == UITYPE::NormalUI ||
//			ui_data[(*it)]->getUIType() == UITYPE::CollisionUI ||
//			ui_data[(*it)]->getUIType() == UITYPE::GaugeUI) {
//			ui_sprite[(*it)]->setVisible(ui_data[(*it)]->isActive());
//		}
//		else if (!(ui_data[(*it)]->getUIType() == UITYPE::AnimationUI)) {
//			ui_label[(*it)]->setVisible(ui_data[(*it)]->isActive());
//		}
//		if (ui_data[(*it)]->getUIType() == UITYPE::AnimationUI) {
//			if (!(ui_data[(*it)]->animationGetIsLooping())) {
//				/*if (ui_static_animation[(*it)]->isDone()) {
//
//				}*/
//			}
//			ui_animation[(*it)]->setVisible(ui_data[(*it)]->isActive());
//		}
//		ui_data[(*it)]->update();
//	}
//	c_Easing::update();
//}

void setTexture(std::unordered_map<std::string, gl::TextureRef>& mTexture,const std::vector<std::string>& ui_objects,
	std::unordered_map<std::string, std::shared_ptr<UIBase>>& ui_data, std::unordered_map<std::string, Font>& font,
	std::unordered_map<std::string, gl::TextureRef>& gauge_texture) {
	
	for (auto it = ui_objects.begin(); it != ui_objects.end(); it++) {

		if (ui_data[(*it)]->getUIType() == UITYPE::NormalUI ||
			ui_data[(*it)]->getUIType() == UITYPE::CollisionUI ||
			ui_data[(*it)]->getUIType() == UITYPE::GaugeUI ||
			ui_data[(*it)]->getUIType() == UITYPE::AnimationUI) {
			//テクスチャのパスをセット

			auto img = loadImage(loadAsset(ui_data[(*it)]->getTexturePath()));
			mTexture[(*it)] = gl::Texture::create(img);
			
		}
		else {
			if (ui_data[(*it)]->getUIType() == UITYPE::FontUI ||
				ui_data[(*it)]->getUIType() == UITYPE::IncrementTimeUI ||
				ui_data[(*it)]->getUIType() == UITYPE::DecrementTimeUI) {
				font[(*it)] = Font(ui_data[(*it)]->fontGetPath(), ui_data[(*it)]->fontGetSize());
				continue;
			}
			if (ui_data[(*it)]->getUIType() == UITYPE::GaugeUI) {
				auto img = loadImage(loadAsset(ui_data[(*it)]->getTexturePath()));
				gauge_texture[(*it)] = gl::Texture::create(img);
				
			}
		}


		
	}
}

void UIPlate::setup(const dess::SceneName& name)
{
	JsonInit(name);
	setTexture(textures,ui_objects,ui_data,font,gauge_texture);
}

void UIPlate::update()
{
	for (auto it = ui_objects.begin(); it != ui_objects.end(); it++) {
		ui_data[*it]->update();
	}
	
	
	//for (auto it = ui_objects.begin(); it != ui_objects.end(); it++) {
	//	if (ui_data[(*it)]->isActive()) {
	//		if (ui_data[(*it)]->getUIType() == UITYPE::FontUI) {
	//			ci::gl::pushModelView();

	//			ci::gl::translate(0.0f, 0.0f, -3.0f);
	//			gl::drawString(ui_data[(*it)]->fontGetText(),
	//				vec2(ui_data[(*it)]->getPosX(), ui_data[(*it)]->getPosY()),
	//				Color(ui_data[(*it)]->getColorR(),
	//					ui_data[(*it)]->getColorG(),
	//					ui_data[(*it)]->getColorB()),
	//				font[(*it)]);

	//			ci::gl::popModelView();
	//			continue;
	//		}
	//		if (ui_data[(*it)]->getUIType() == UITYPE::IncrementTimeUI ||
	//			ui_data[(*it)]->getUIType() == UITYPE::DecrementTimeUI) {
	//			ci::gl::pushModelView();

	//			ci::gl::translate(0.0f, 0.0f, -3.0f);
	//			gl::drawString(ui_data[(*it)]->timeGetMinutes() + ":" + ui_data[(*it)]->timeGetSeconds() + ":" + ui_data[(*it)]->timeGetFlame(),
	//				vec2(ui_data[(*it)]->getPosX(), ui_data[(*it)]->getPosY()),
	//				Color(ui_data[(*it)]->getColorR(),
	//					ui_data[(*it)]->getColorG(),
	//					ui_data[(*it)]->getColorB()),
	//				font[(*it)]);

	//			ci::gl::popModelView();
	//			continue;
	//		}
	//		ci::gl::pushModelView();


	//		ci::gl::translate(0.0f, 0.0f, -3.0f);
	//		ci::gl::color(ui_data[(*it)]->getColorR(), ui_data[(*it)]->getColorG(), ui_data[(*it)]->getColorB(), ui_data[(*it)]->getColorA());

	//		//TEX.get((*it)).get()->bind(1);
	//		
	//		

	//		//TEX.get((*it)).get()->unbind(1);

	//		ci::gl::popModelView();

	//		ci::gl::pushModelView();

	//		ci::gl::color(ui_data[(*it)]->getColorR(), ui_data[(*it)]->getColorG(), ui_data[(*it)]->getColorB(), ui_data[(*it)]->getColorA());


	//		if (ui_data[(*it)]->getUIType() == UITYPE::GaugeUI) {
	//			ci::gl::translate(0.0f, 0.0f, -1.0f);
	//			//TEX.get(ui_data[(*it)]->gaugeGetTexturePath()).get()->bind(1);
	//			ci::gl::drawSolidRect(
	//				ci::Rectf(vec2(
	//					ui_data[(*it)]->gaugeGetPosX(),
	//					ui_data[(*it)]->gaugeGetPosY()),
	//					vec2(
	//						ui_data[(*it)]->gaugeGetPosX() + ui_data[(*it)]->gaugeGetSizeX(),
	//						ui_data[(*it)]->gaugeGetPosY() + ui_data[(*it)]->gaugeGetSizeY())));
	//			//TEX.get(ui_data[(*it)]->gaugeGetTexturePath()).get()->unbind(1);
	//		}
	//		ci::gl::popModelView();

	//	}
	//}
	
}

void UIPlate::draw()
{
	
	
	for (auto it = ui_objects.begin(); it != ui_objects.end(); it++) {
		if (!ui_data[(*it)]->getActive()) continue;
		if (ui_data[(*it)]->getUIType() == UITYPE::NormalUI ||
			ui_data[(*it)]->getUIType() == UITYPE::CollisionUI ||
			ui_data[(*it)]->getUIType() == UITYPE::GaugeUI ||
			ui_data[(*it)]->getUIType() == UITYPE::AnimationUI) {

			textures[(*it)]->bind();
			// draw the texture itself in the upper right corner	
			//gl::setMatricesWindow(getWindowSize());

			Rectf drawRect(vec2(
				ui_data[(*it)]->getPosX(),
				ui_data[(*it)]->getPosY()),
				ci::vec2(
					ui_data[(*it)]->getPosX() + ui_data[(*it)]->getSizeX(),
					ui_data[(*it)]->getPosY() + ui_data[(*it)]->getSizeY()));

			gl::draw(textures[(*it)], drawRect);
			textures[(*it)]->unbind();
		}
		else {
			if (ui_data[(*it)]->getUIType() == UITYPE::FontUI ||
				ui_data[(*it)]->getUIType() == UITYPE::IncrementTimeUI ||
				ui_data[(*it)]->getUIType() == UITYPE::DecrementTimeUI) {
				
			}
			if (ui_data[(*it)]->getUIType() == UITYPE::GaugeUI) {
				gauge_texture[(*it)]->bind();
				// draw the texture itself in the upper right corner	
				gl::setMatricesWindow(getWindowSize());

				Rectf drawRect(vec2(
					ui_data[(*it)]->getPosX(),
					ui_data[(*it)]->getPosY()),
					ci::vec2(
						ui_data[(*it)]->getPosX() + ui_data[(*it)]->getSizeX(),
						ui_data[(*it)]->getPosY() + ui_data[(*it)]->getSizeY()));

				gl::draw(textures[(*it)], drawRect);
				gauge_texture[(*it)]->unbind();
			}
		}
	}
	c_Easing::update();
}
