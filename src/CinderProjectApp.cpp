#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ProductionCamera/ProductionCamera.h"
#include "cinder/Timeline.h"
#include "cinder/Json.h"
#include "SceneManager/SceneManager.h"
#include "SoundManager.h"




enum {
	WINDOW_WIDTH = 640,
	WINDOW_HEIGHT = 960,
};

class CinderProjectApp : public ci::app::App {
	
	float delta_time;
    
    
public:

	void resize();
	void setup();
	void touchesBegan(ci::app::TouchEvent event) override;
	void touchesMoved(ci::app::TouchEvent event) override;
	void touchesEnded(ci::app::TouchEvent event) override;
	void mouseDown(ci::app::MouseEvent event);
	void mouseDrag(ci::app::MouseEvent event);
	void mouseUp(ci::app::MouseEvent event) override;
	void update() override;
	void draw();
	
};

void prepareSettings(CinderProjectApp::Settings* settings)
{
	settings->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	
	//settings->setMultiTouchEnabled(false);
}



void CinderProjectApp::resize()
{
	
}

void CinderProjectApp::setup() {
    SE.setup();
	TEX.setup();

    delta_time = 0;
    //camera = CameraPersp(WINDOW_WIDTH, WINDOW_HEIGHT,
    //	60.0f,
    //	1.0f, 500.0f);
    //
	SCENE.setup();
    CAMERA.setup();
    
    
    ci::gl::enableAlphaBlending();
    
    
    
}

void CinderProjectApp::touchesBegan(ci::app::TouchEvent event)
{
	SCENE.touchesBegan(event);
}

void CinderProjectApp::touchesMoved(ci::app::TouchEvent event)
{
	SCENE.touchesMoved(event);
}

void CinderProjectApp::touchesEnded(ci::app::TouchEvent event)
{
	SCENE.touchesEnded(event);
}


void CinderProjectApp::mouseDown(ci::app::MouseEvent event) {
    
    if (!event.isLeft()) return;
    ci::vec2 pos = event.getPos();
	SCENE.mouseDown(event);
    
}

void CinderProjectApp::mouseDrag(ci::app::MouseEvent event) {
    if (!event.isLeftDown()) return;
    ci::vec2 pos = event.getPos();
	SCENE.mouseDrag(event);
	
}

void CinderProjectApp::mouseUp(ci::app::MouseEvent event)
{
	ci::vec2 pos = event.getPos();
	SCENE.mouseUp(event);
	
}

void CinderProjectApp::update()
{
	
	delta_time = std::abs(delta_time - timeline().getCurrentTime());
	SCENE.update(delta_time);
	CAMERA.update(delta_time);
	delta_time = timeline().getCurrentTime();
}


void CinderProjectApp::draw() {
	ci::gl::clear(ci::Color(0, 0, 0));
	ci::gl::setMatrices(CAMERA.getCamera());
	SCENE.draw();
	CAMERA.draw();
	c_Easing::update();
   
	
}




CINDER_APP( CinderProjectApp, ci::app::RendererGl , prepareSettings)
