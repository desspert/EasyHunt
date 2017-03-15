#include "Data.h"

PlayerData::PlayerData()
{
	
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

void PlayerData::Save()
{
	Json::StyledWriter writer;
	auto data = writer.write(root_type);
	auto dataRef = ci::writeFile(ci::app::getAssetPath("SaveData/PlayerData.json"));
	dataRef->getStream()->writeData(data.c_str(), data.size());
}

void PlayerData::Load()
{
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
