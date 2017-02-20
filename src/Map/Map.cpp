#include "Map.h"
std::shared_ptr<ObjectBase> returnEnemy(const int& type, const ci::vec2& pos,
	const ci::vec2& size,const int& hp,const int& attack,const int& range,const float& attack_speed,const std::string& path) {
	switch (type) {
		std::make_shared<NormalEnemy>(pos, size, hp, attack, range, attack_speed, path);
	case 0:
		break;
	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;

	case 6:
		break;
	}
	return std::make_shared<NormalEnemy>(pos, size, hp, attack, range, attack_speed, path);
}

bool Map::isClear(const std::list<std::shared_ptr<ObjectBase>>& enemy)
{
	if (enemy.size() <= 0) {
		return true;
	}
	return false;
}

void Map::setup(std::list<std::shared_ptr<ObjectBase>>& enemy)
{
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			pos.push_back(ci::vec2(size.x * k, size.y * i));
		}
	}
	Json::Value root_type;
	Json::Reader reader;
	if (reader.parse(loadString("MapData/MapData1.json"), root_type)) {
		for (auto it = root_type["Enemys"].begin(); it != root_type["Enemys"].end(); it++) {
			ci::vec2 pos = ci::vec2((*it)["Pos"][0].asFloat(), (*it)["Pos"][1].asFloat());
			ci::vec2 size = ci::vec2((*it)["Size"].asFloat(), (*it)["Size"].asFloat());
			int hp = (*it)["HP"].asInt();
			int attack = (*it)["Attack"].asInt();
			int range = (*it)["Range"].asInt();
			float attack_speed = (*it)["AttackSpeed"].asFloat();
			TEX.set((*it)["Texture"].asString(), (*it)["Texture"].asString());

			enemy.push_back(returnEnemy((*it)["EnemyType"].asInt(), pos, size, hp, attack, range, attack_speed, (*it)["Texture"].asString()));
			
		}
	}
	
}

void Map::update(const float & delta_time)
{
}

void Map::draw()
{
	for (auto& it : pos) {
		ci::gl::pushModelMatrix();
		ci::gl::translate(it);
		TEX.get("map")->bind();
		ci::Rectf drawRect(ci::vec2(
			0,
			0),
			ci::vec2(
				size.x,
				size.y));
		ci::gl::draw(TEX.get("map"), drawRect);
		ci::gl::color(1, 1, 1, 1);
		TEX.get("map")->unbind();
		ci::gl::popModelMatrix();
	}


}
