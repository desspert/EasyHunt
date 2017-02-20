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
	virtual void update(const float& delta_time) {};
	virtual void draw() {};
	virtual void setup() {};
	virtual void shift(const SceneName& scene) {};
	virtual void mouseDown(const ci::app::MouseEvent& event) {};
	virtual void mouseDrag(const ci::app::MouseEvent& event) {};
	virtual void mouseUp(const ci::app::MouseEvent& event) {};
	virtual void touchesBegan(ci::app::TouchEvent event) {};
	virtual void touchesMoved(ci::app::TouchEvent event) {};
	virtual void touchesEnded(ci::app::TouchEvent event) {};
};