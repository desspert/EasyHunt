#pragma once
#include <iostream>
#include <map>
#include "cinder/app/App.h"
#include <cinder/imageIo.h>
#include <cinder/gl/Texture.h> 
#include <cinder/gl/gl.h>
#include <jsoncpp/json.h>
#include "../dessUI/Texture.h"

#define PLAYERDATA PlayerData::get()

struct Character {
	int rare;
	int size;
	int hp;
	int attack;
	float speed;
	int range;
	float attack_speed;
	std::string type;
	std::string skill;
	std::string name;
	std::string texture_path;
};

class  PlayerData {
private:
	int selected_map;
	Character selected_character;
	int clear_stage;
	int have_coin;
public:
	std::map<std::string, Character> characters;
	PlayerData() {
		Json::Value root_type;
		Json::Reader reader;
		if (reader.parse(loadString("SaveData/PlayerData.json"), root_type)) {
			for (auto it = root_type["Characters"].begin(); it != root_type["Characters"].end(); it++) {
				characters[(*it)["Name"].asString()].rare = (*it)["Rare"].asInt();
				characters[(*it)["Name"].asString()].size = (*it)["Size"].asInt();
				characters[(*it)["Name"].asString()].hp = (*it)["Hp"].asInt();
				characters[(*it)["Name"].asString()].attack = (*it)["Attack"].asInt();
				characters[(*it)["Name"].asString()].speed = (*it)["Speed"].asFloat();
				characters[(*it)["Name"].asString()].range = (*it)["Range"].asInt();
				characters[(*it)["Name"].asString()].attack_speed = (*it)["AttackSpeed"].asFloat();
				characters[(*it)["Name"].asString()].type = (*it)["AttackType"].asString();
				characters[(*it)["Name"].asString()].name = (*it)["Name"].asString();
				characters[(*it)["Name"].asString()].texture_path = (*it)["TexturePath"].asString();
				selected_character = characters[(*it)["Name"].asString()];
			}
			have_coin = root_type["Coins"].asInt();
		}
	}
	void selectMap(const int& map) {
		selected_map = map;
	}
	void clearStage(const int& map) {
		clear_stage = map;
	}

	const int& getSelectedMap() {
		return selected_map;
	}
	const int& getHaveCoins() {
		return have_coin;
	}
	const int& getClearStage() {
		return clear_stage;
	}

	const Character& getSelectedCharacter() {
		return selected_character;
	}

	static PlayerData& get() {
		static PlayerData data;
		return data;
	}

};