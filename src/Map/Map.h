#pragma once

#include<cinder/app/App.h>
#include "../dessUI/Texture.h"
#include <cinder/gl/gl.h>
#include "../Player/Player.h"
#include "../Enemy/NormalEnemy/NormalEnemy.h"
#include "../Enemy/FarRangeEnemy/FarRangeEnemy.h"
#include "../Enemy/MagicEnemy/MagicEnemy.h"
#include "../Enemy/Boss/Boss.h"
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
	std::list<std::shared_ptr<Boss>> boss;
	bool tutorial;
public:
	Map() {
		size = ci::vec2(1500, 1000);
		TEX.set("map", "MapData/MapTextures/img15_1.gif");

	}
	bool getTutorial() {
		return tutorial;
	}
	const ci::vec2& getPlayerPos(const int& player_number) {
		return players_pos[player_number];
	}
	
	bool isBoss(const std::list<std::shared_ptr<ObjectBase>>& enemy, const std::list<std::shared_ptr<Boss>>& boss);
	bool setup(std::list<std::shared_ptr<ObjectBase>>& enemy);
	void update(const float& delta_time);
	void draw();
	void bossSpawn(std::list<std::shared_ptr<Boss>>& boss);
};