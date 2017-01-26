#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ProductionCamera/ProductionCamera.h"
#include "cinder/Arcball.h"        // 物体をマウスでグリグリ回す機能
#include "cinder/Ray.h"
#include "cinder/Timeline.h"
#include "cinder/Json.h"
#include "SceneManager/SceneManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;
enum {
	WINDOW_WIDTH = 640,
	WINDOW_HEIGHT = 960,
};
class CinderProjectApp : public App {
	
	SceneManager scene;
	int delta_frame;
	// 物体をマウスでグリグリする機能
	Arcball arcball;
	AxisAlignedBox aabb;
public:
	

	void resize();
	void setup();
	void touchesBegan(TouchEvent event) override;
	void touchesMoved(TouchEvent event) override;
	void touchesEnded(TouchEvent event) override;
	void mouseDown(MouseEvent event);
	void mouseDrag(MouseEvent event);
	void mouseUp(MouseEvent event) override;
	void update() override;
	void draw();
	
};

void prepareSettings(CinderProjectApp::Settings* settings)
{
	settings->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	
	settings->setMultiTouchEnabled(false);
}



void CinderProjectApp::resize()
{
	
}

void CinderProjectApp::setup() {
	delta_frame = 0;
	//camera = CameraPersp(WINDOW_WIDTH, WINDOW_HEIGHT,
	//	60.0f,
	//	1.0f, 500.0f);
	//
	scene.setup();
	CAMERA.setup();
	
	gl::enableDepthWrite();
	gl::enableDepthRead();
	gl::enableAlphaBlending();
	//camera.lookAt(vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 0.0f, -1000.0f));

	//aabb = AxisAlignedBox(vec3(-0.5f, -0.5f, -5.0f), vec3(0.5f, 0.5f, -5.0f));
	
	//
	//auto img = loadImage(loadAsset("push_enter.png"));
	//mTexture = gl::Texture::create(img);
	//mTexture->bind();

	//auto shader = gl::ShaderDef().texture().lambert();
	//mGlsl = gl::getStockShader(shader);

	//// Arcballを初期化
	////   初期化には画面サイズを与える
	//arcball = Arcball(&camera, Sphere(vec3(0, 0, 0), 150));


	//gl::enableDepthRead();
	//gl::enableDepthWrite();
	//gl::enable(GL_CULL_FACE);

	
}

void CinderProjectApp::touchesBegan(TouchEvent event)
{
	ci::app::console() << "b" << std::endl;
}

void CinderProjectApp::touchesMoved(TouchEvent event)
{
	ci::app::console() << "m" << std::endl;
}

void CinderProjectApp::touchesEnded(TouchEvent event)
{
	ci::app::console() << "e" << std::endl;
}


void CinderProjectApp::mouseDown(MouseEvent event) {
	// 左クリック以外はスルー
	if (!event.isLeft()) return;
	vec2 pos = event.getPos();
	scene.mouseDown(event);
	
	
	//scene.shift(SceneName::GAMEMAIN);
	// 回転開始時に、
	// Arcballへマウスカーソル位置を与える
	// ここでもY軸プラスの方向が逆なのを補正
	//arcball.mouseDown(vec2(pos.x, WINDOW_HEIGHT - pos.y), getWindowSize());
}

void CinderProjectApp::mouseDrag(MouseEvent event) {
	if (!event.isLeftDown()) return;

	
	vec2 pos = event.getPos();
	scene.mouseDrag(event);
	//// Arcballに移動中の位置を与えるだけ。簡単!!
	//vec2 pos = event.getPos();
	//float x = pos.x / float(WINDOW_WIDTH);
	//float y = 1.0f - pos.y / float(WINDOW_HEIGHT);
	//Ray ray = camera.generateRay(x, y, camera.getAspectRatio());


	//if (aabb.intersects(ray)) {
	//	arcball.mouseDrag(vec2(pos.x, WINDOW_HEIGHT - pos.y), getWindowSize());
	//}
}

void CinderProjectApp::mouseUp(MouseEvent event)
{
	vec2 pos = event.getPos();
	scene.mouseUp(event);
	
}

void CinderProjectApp::update()
{
	//デルタタイム
	//timeline().getCurrentTime()
	
	delta_frame =  std::abs(delta_frame - static_cast<int>(ci::app::getElapsedFrames()));

	scene.update(delta_frame);
	CAMERA.update(delta_frame);
	
	delta_frame = static_cast<int>(ci::app::getElapsedFrames());
}


void CinderProjectApp::draw() {
	gl::clear(Color(0.2f, 0.2f, 0.2f));
	gl::setMatrices(CAMERA.getCamera());
	scene.draw();
	
	
	

	/*gl::clear(Color(0, 0, 0));
	ui.update();
	gl::setMatrices(camera);*/
	//gl::pushModelView();
	//gl::drawStrokedCube(aabb);
	//gl::popModelView();
	//gl::pushModelView();

	//gl::translate(0.0f, 0.0f, -3.0f);
	//
	//// Arcballから回転情報を取り出して使う
	//// gl::rotate(arcball.getQuat());
	//// TIPS:QuaternionからOpenGLの回転を指定する実装に問題がある
	////      ので、Quaternionから行列を作ってOpenGLへ指定
	//quat rotate = arcball.getQuat();
	//
	//gl::setModelMatrix(glm::mat4_cast(rotate));

	//gl::drawColorCube(vec3(0.0f, 0.0f, -6.0f), vec3(1.0f, 1.0f, 1.0f));

	//
	//gl::popModelView();
	
}




CINDER_APP( CinderProjectApp, RendererGl , prepareSettings)
