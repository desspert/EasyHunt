#include "SceneManager.h"
SceneManager::SceneManager() {
	scene = new Select();
}

void SceneManager::setup()
{
	scene->setup();
}


void SceneManager::update(const float& delta_time)
{
	scene->update(delta_time);
}

void SceneManager::draw()
{
	scene->draw();
}

void SceneManager::shift(const SceneName& scene_name)
{
    delete scene;
	switch (scene_name) {
	case SceneName::TITLE:
		scene = new Title();
		scene->setup();
		break;
	case SceneName::GAMEMAIN:
		scene = new GameMain();
		scene->setup();
		break;
	case SceneName::SELECT:
            scene = new Select();
            scene->setup();
		break;
	case SceneName::RESULT:
            scene = new Result();
            scene->setup();
		break;
	}
}

void SceneManager::touchesBegan(ci::app::TouchEvent event)
{
	scene->touchesBegan(event);
}

void SceneManager::touchesMoved(ci::app::TouchEvent event)
{
	scene->touchesMoved(event);
}

void SceneManager::touchesEnded(ci::app::TouchEvent event)
{
	scene->touchesEnded(event);
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

