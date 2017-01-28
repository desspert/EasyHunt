#pragma once
#include <functional>
#include <memory>
#include "SceneBase.h"
#include "Title/Title.h"
#include "GameMain/GameMain.h"
#include "Select/Select.h"
#include "Result/Result.h"
class SceneManager {
public:

	SceneManager();
	~SceneManager() {

	}
	
	std::shared_ptr<SceneBase> scene;
	void setup();
	void update(const float& delta_time);
	void draw();
	void shift(const SceneName& scene);
	void touchesBegan(ci::app::TouchEvent event);
	void touchesMoved(ci::app::TouchEvent event);
	void touchesEnded(ci::app::TouchEvent event);
	void mouseDown(const ci::app::MouseEvent& event);
	void mouseDrag(const ci::app::MouseEvent& event);
	void mouseUp(const ci::app::MouseEvent& event);
};