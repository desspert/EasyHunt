#pragma once

#include<cinder/app/App.h>
#include "../dessUI/Texture.h"
#include <cinder/gl/gl.h>
#include "../Player/Player.h"
#include "../Enemy/NormalEnemy/NormalEnemy.h"
#include <jsoncpp/json.h>
struct MapTip {
	MapTip(const ci::vec2& pos, const ci::vec2& size, const ci::gl::TextureRef& texture)
	: pos(pos),size(size),texture(texture){
	}
	ci::vec2 pos;
	ci::vec2 size;
	
	ci::gl::TextureRef texture;
};

class Map {
private:
	ci::vec2 pos;
	ci::vec2 size;
	ci::vec2 texture_size;

	std::vector<std::vector<MapTip>> map;
public:
	Map() {
		pos = ci::vec2(-2500, -2500);
		size = ci::vec2(4000, 4000);
		texture_size = ci::vec2(16);
		TEX.set("map", "img15_1.gif");
	}
	void setup(std::list<std::shared_ptr<ObjectBase>>& enemy);
	void update(const float& delta_time);
	void draw();

};