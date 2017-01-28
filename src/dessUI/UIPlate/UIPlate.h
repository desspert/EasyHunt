#pragma once
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/svg/Svg.h>
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include "../UIManager/UIManager.h"
#include <cinder/Camera.h>

class UIPlate : public UIManager
{
private:
	std::unordered_map<std::string, ci::Font> font;
	std::unordered_map<std::string,ci::gl::TextureRef>		textures;
	std::unordered_map<std::string, ci::gl::TextureRef>		gauge_texture;
	
public:
	UIPlate() {
		
	};
	virtual void setup(const dess::SceneName& name);
	virtual void update(const float& delta_time);
	virtual void draw();
};