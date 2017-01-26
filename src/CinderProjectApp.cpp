#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ProductionCamera/ProductionCamera.h"
#include "cinder/Arcball.h"        // ���̂��}�E�X�ŃO���O���񂷋@�\
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
	// ���̂��}�E�X�ŃO���O������@�\
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

	//// Arcball��������
	////   �������ɂ͉�ʃT�C�Y��^����
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
	// ���N���b�N�ȊO�̓X���[
	if (!event.isLeft()) return;
	vec2 pos = event.getPos();
	scene.mouseDown(event);
	
	
	//scene.shift(SceneName::GAMEMAIN);
	// ��]�J�n���ɁA
	// Arcball�փ}�E�X�J�[�\���ʒu��^����
	// �����ł�Y���v���X�̕������t�Ȃ̂�␳
	//arcball.mouseDown(vec2(pos.x, WINDOW_HEIGHT - pos.y), getWindowSize());
}

void CinderProjectApp::mouseDrag(MouseEvent event) {
	if (!event.isLeftDown()) return;

	
	vec2 pos = event.getPos();
	scene.mouseDrag(event);
	//// Arcball�Ɉړ����̈ʒu��^���邾���B�ȒP!!
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
	//�f���^�^�C��
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
	//// Arcball�����]�������o���Ďg��
	//// gl::rotate(arcball.getQuat());
	//// TIPS:Quaternion����OpenGL�̉�]���w�肷������ɖ�肪����
	////      �̂ŁAQuaternion����s��������OpenGL�֎w��
	//quat rotate = arcball.getQuat();
	//
	//gl::setModelMatrix(glm::mat4_cast(rotate));

	//gl::drawColorCube(vec3(0.0f, 0.0f, -6.0f), vec3(1.0f, 1.0f, 1.0f));

	//
	//gl::popModelView();
	
}




CINDER_APP( CinderProjectApp, RendererGl , prepareSettings)
