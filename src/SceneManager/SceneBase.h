#pragma once
#include <cinder/app/App.h>


enum class SceneName {
	TITLE,
	SELECT,
	GAMEMAIN,
	RESULT
};

class SceneBase {
public:
	SceneBase() {}
	~SceneBase(){};
	virtual void update() {};
	virtual void draw() {};
	virtual void setup() {};
	virtual void mouseDown(const ci::app::MouseEvent& event) {};
	virtual void mouseDrag(const ci::app::MouseEvent& event) {};
	virtual void mouseUp(const ci::app::MouseEvent& event) {};
};