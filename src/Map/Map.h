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
	std::vector<ci::vec2> pos;
	ci::vec2 size;
	std::vector<ci::vec2> players_pos;
public:
	Map() {
		size = ci::vec2(1500, 1000);
		TEX.set("map", "MapData/MapTextures/img15_1.gif");

	}
	const ci::vec2& getPlayerPos(const int& player_number) {
		return players_pos[player_number];
	}
	bool isClear(const std::list<std::shared_ptr<ObjectBase>>& enemy);
	void setup(std::list<std::shared_ptr<ObjectBase>>& enemy);
	void update(const float& delta_time);
	void draw();

};