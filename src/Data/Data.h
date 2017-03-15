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
	Json::Value root_type;
	std::map<std::string, Character> characters;
	PlayerData();
	void Save();
	void Load();
	void selectMap(const int& map) {
		selected_map = map;
	}
	void clearStage(const int& map) {
		clear_stage = map;
	}
	void addCoin(const int& coin) {
		have_coin += coin;
		root_type["Coins"] = have_coin;
		Save();
	}
	void useCoin(const int& coin) {
		have_coin -= coin;
		root_type["Coins"] = have_coin;
		Save();
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