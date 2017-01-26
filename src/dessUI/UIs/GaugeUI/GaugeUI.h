
#pragma once
#include"../../UIBase.h"

class GaugeUI : public UIBase
{
private:
	des::Vec2f gauge_pos;
	des::Vec2f gauge_size;
	std::string gauge_texture_path;
	bool gauge_max;
	float gauge_max_x;
	float gauge_max_y;
public:
	GaugeUI(des::Vec2f _pos, des::Vec2f _size, des::Vec4d _color) :UIBase(_pos, _size, _color)
	{
		gauge_max = false;
		own_ui = UITYPE::GaugeUI;
	};

	float gaugeGetPosX() {
		return gauge_pos.x;
	}
	float gaugeGetPosY() {
		return gauge_pos.y;
	}
	float gaugeGetSizeX() {
		return gauge_size.x;
	}
	float gaugeGetSizeY() {
		return gauge_size.y;
	}
	bool gaugeGetIsMax() {
		return gauge_max;
	}
	std::string gaugeGetTexturePath() {
		return gauge_texture_path;
	}

	void gaugeSetPos(const float& gauge_pos_x, const float& gauge_pos_y) {
		gauge_pos.x = gauge_pos_x;
		gauge_pos.y = gauge_pos_y;
	}
	void gaugeSetSize(const float& gauge_size_x, const float& gauge_size_y) {
		gauge_size.x = gauge_size_x;
		gauge_size.y = gauge_size_y;
		gauge_max_x = gauge_size_x;
		gauge_max_y = gauge_size_y;
	}
	void gaugeSetTexturePath(const std::string& path) {
		gauge_texture_path = path;
	}
	//���̃Q�[�W�̏ꍇ
	//�ϓ�����l
	//�ő�l
	void gaugeChangeX(float value, float max);

	//�c�̃Q�[�W�̏ꍇ
	//�ϓ�����l
	//�ő�l
	void gaugeChangeY(float value, float max);
};