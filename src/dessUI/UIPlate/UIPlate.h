#pragma once
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/svg/Svg.h>
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include "../UIManager/UIManager.h"
#include "../Texture.h"
#include <cinder/Camera.h>

class UIPlate : public UIManager
{
private:
	std::unordered_map<std::string, Font> font;
	gl::BatchRef		mSphere;
	std::unordered_map<std::string,gl::TextureRef>		textures;
	std::unordered_map<std::string, gl::TextureRef>		gauge_texture;
	gl::GlslProgRef		mGlsl;
	
public:
	UIPlate() {
		
	};
	virtual void setup(const dess::SceneName& name);
	virtual void update();
	virtual void draw();
};