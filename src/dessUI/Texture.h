#pragma once
#include "cinder/gl/Texture.h"            
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include <unordered_map>
static std::string loadString(std::string const& relative_path) {
	return std::string(static_cast<char*>(ci::app::loadAsset(relative_path)->getBuffer()->getData()));
}

#define TEX TextureManager::get()

class TextureManager
{
private:
	std::unordered_map<std::string, ci::gl::TextureRef> texture;
public:
	TextureManager() {
		
	};
	~TextureManager() {};
	void set(const std::string& name, const std::string& path)
	{
		if (texture.find(name) == texture.end()) {
			auto img = ci::loadImage(ci::app::loadAsset(path));
			texture[name] = ci::gl::Texture::create(img);
		}
	}

	ci::gl::TextureRef get(std::string name) {
		return texture[name];
	}

	static TextureManager& get() {
		static TextureManager tex;
		return tex;
	}
};