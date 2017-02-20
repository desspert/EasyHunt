#include "UIPlate.h"


void setTexture(std::unordered_map<std::string, ci::gl::TextureRef>& mTexture,const std::vector<std::string>& ui_objects,
	std::unordered_map<std::string, std::shared_ptr<UIBase>>& ui_data, std::unordered_map<std::string, ci::Font>& font,
	std::unordered_map<std::string, ci::gl::TextureRef>& gauge_texture) {
	
	for (auto it = ui_objects.begin(); it != ui_objects.end(); it++) {

		if (ui_data[(*it)]->getUIType() == UITYPE::NormalUI ||
			ui_data[(*it)]->getUIType() == UITYPE::CollisionUI ||
			ui_data[(*it)]->getUIType() == UITYPE::GaugeUI ||
			ui_data[(*it)]->getUIType() == UITYPE::AnimationUI ||
			ui_data[(*it)]->getUIType() == UITYPE::ScrollUI) {
			//テクスチャのパスをセット

			auto img = ci::loadImage(ci::app::loadAsset(ui_data[(*it)]->getTexturePath()));
			mTexture[(*it)] = ci::gl::Texture::create(img);
			if (ui_data[(*it)]->getUIType() == UITYPE::GaugeUI) {
				auto img = ci::loadImage(ci::app::loadAsset(ui_data[(*it)]->gaugeGetTexturePath()));
				gauge_texture[(*it)] = ci::gl::Texture::create(img);

			}
			
		}
		else {
			if (ui_data[(*it)]->getUIType() == UITYPE::FontUI ||
				ui_data[(*it)]->getUIType() == UITYPE::IncrementTimeUI ||
				ui_data[(*it)]->getUIType() == UITYPE::DecrementTimeUI) {
				//font[(*it)] = ci::Font(ui_data[(*it)]->fontGetPath(), ui_data[(*it)]->fontGetSize());
				continue;
			}
			
		}


		
	}
}

void UIPlate::setup(const dess::SceneName& name)
{
	
	JsonInit(name);
	setTexture(textures,ui_objects,ui_data,font,gauge_texture);
}

void UIPlate::update(const float& delta_time)
{
	for (auto it = ui_objects.begin(); it != ui_objects.end(); it++) {
		ui_data[*it]->update();
	}
	
}

void UIPlate::draw()
{
	
	
	for (auto it = ui_objects.begin(); it != ui_objects.end(); it++) {
		if (!ui_data[(*it)]->getActive()) continue;
		
		if (ui_data[(*it)]->getUIType() == UITYPE::NormalUI ||
			ui_data[(*it)]->getUIType() == UITYPE::CollisionUI ||
			ui_data[(*it)]->getUIType() == UITYPE::GaugeUI ||
			ui_data[(*it)]->getUIType() == UITYPE::AnimationUI 
			) {
			ci::gl::color(ui_data[(*it)]->getColorR(), ui_data[(*it)]->getColorG(), ui_data[(*it)]->getColorB(), ui_data[(*it)]->getColorA());
			textures[(*it)]->bind();

			ci::Rectf drawRect(ci::vec2(
				ui_data[(*it)]->getPosX(),
				ui_data[(*it)]->getPosY()),
				ci::vec2(
					ui_data[(*it)]->getPosX() + ui_data[(*it)]->getSizeX(),
					ui_data[(*it)]->getPosY() + ui_data[(*it)]->getSizeY()));

			ci::gl::draw(textures[(*it)], drawRect);
			ci::gl::color(1, 1, 1, 1);
			textures[(*it)]->unbind();

			if (ui_data[(*it)]->getUIType() == UITYPE::GaugeUI) {
				ci::gl::color(ui_data[(*it)]->getColorR(), ui_data[(*it)]->getColorG(), ui_data[(*it)]->getColorB(), ui_data[(*it)]->getColorA());
				gauge_texture[(*it)]->bind();
				
				ci::Rectf drawGauge(ci::vec2(
					ui_data[(*it)]->gaugeGetPosX(),
					ui_data[(*it)]->gaugeGetPosY()),
					ci::vec2(
						ui_data[(*it)]->gaugeGetPosX() + ui_data[(*it)]->gaugeGetSizeX(),
						ui_data[(*it)]->gaugeGetPosY() + ui_data[(*it)]->gaugeGetSizeY()));

				ci::gl::draw(gauge_texture[(*it)], drawGauge);
				gauge_texture[(*it)]->unbind();
				ci::gl::color(1, 1, 1, 1);
			}
		}
		else {
			if (ui_data[(*it)]->getUIType() == UITYPE::FontUI ||
				ui_data[(*it)]->getUIType() == UITYPE::IncrementTimeUI ||
				ui_data[(*it)]->getUIType() == UITYPE::DecrementTimeUI) {
				
			}
			
		}
	}
	
}
