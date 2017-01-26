#pragma once
#include "cinder/gl/Texture.h"      
#include "cinder/imageIo.h"         
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include <unordered_map>
using namespace ci;
using namespace ci::app;

#define TEX TextureManager::get()

class TextureManager : App
{
private:
	std::unordered_map<std::string, gl::Texture2dRef> texture;
	ImageSource::Options a;
public:
	TextureManager() {
		a.index(1);
	};
	~TextureManager() {};
	void set(std::string name, std::string path)
	{
		if (texture.find(name) == texture.end()) {
			texture[name] = gl::Texture2d::create(loadImage(loadAsset(path)));
		}
	}

	gl::Texture2dRef get(std::string name) {
		return texture[name];
	}

	static TextureManager& get() {
		static TextureManager tex;
		return tex;
	}
};