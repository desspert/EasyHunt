#include "SceneManager.h"
SceneManager::SceneManager() {
	scene = std::make_shared<GameMain>();
}

void SceneManager::setup()
{
	scene->setup();
}


void SceneManager::update(const int& delta_frame)
{
	scene->update(delta_frame);
}

void SceneManager::draw()
{
	scene->draw();
}

void SceneManager::shift(const SceneName& scene_name)
{
	//cinderはコンストラクタでsetupを呼ぶと死ぬ
	switch (scene_name) {
	case SceneName::TITLE:
		scene = std::make_shared<Title>();
		scene->setup();
		break;
	case SceneName::GAMEMAIN:
		scene = std::make_shared<GameMain>();
		scene->setup();
		break;
	case SceneName::SELECT:
		scene = std::make_shared<Select>();
		scene->setup();
		break;
	case SceneName::RESULT:
		scene = std::make_shared<Result>();
		scene->setup();
		break;
	}
}

void SceneManager::mouseDown(const ci::app::MouseEvent& event)
{
	scene->mouseDown(event);
}

void SceneManager::mouseDrag(const ci::app::MouseEvent& event)
{
	scene->mouseDrag(event);
}

void SceneManager::mouseUp(const ci::app::MouseEvent& event)
{
	scene->mouseUp(event);
}

