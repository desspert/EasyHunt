#include "ProductionCamera.h"



void ProductionCamera::shakeCamera(const float & scatter, const float & seconds)
{
}

void ProductionCamera::setup(){
	auto img_range = ci::loadImage(ci::app::loadAsset("UI/UITexture/Select/GameChange.png"));
	fade_tex = ci::gl::Texture2d::create(img_range);
	camera_z = -1000.0f;
	camera.setAspectRatio(ci::app::getWindowAspectRatio());
	camera.lookAt(ci::vec3((*reference_pos)->x + camera_size.x / 2, (*reference_pos)->y + camera_size.y / 2, camera_z), ci::vec3(0), ci::vec3(0, -1, 0));
	camera_z = -3000.0f;
	camera.setFarClip(10000);

	camera_o.setAspectRatio(ci::app::getWindowAspectRatio());
	camera_o.lookAt(ci::vec3(0,0,-100), ci::vec3(0), ci::vec3(0, 1, 0));
	camera_o.setFarClip(10000);
}

void ProductionCamera::update(const float& delta_time) {
	buf_pos = ci::vec2((*reference_pos)->x, (*reference_pos)->y) - pos;
	buf_pos *= 0.1f;
	pos += buf_pos;
	camera.lookAt(ci::vec3(
		pos.x + camera_size.x / 2,
		pos.y + camera_size.y/2,camera_z),
		ci::vec3(pos.x + camera_size.x / 2,
			pos.y + camera_size.y / 2, 0));
}

void ProductionCamera::draw()
{
	ci::gl::pushModelMatrix();
	ci::gl::translate(ci::vec2(pos.x - camera_::TEXTURE_WIDTH /2, pos.x - camera_::TEXTURE_HEIGHT / 2));
	fade_tex->bind();
	ci::gl::color(fade_out.r, fade_out.g, fade_out.b, fade_out.a);
	ci::Rectf drawRect(ci::vec2(
		0,
		0),
		ci::vec2(
			camera_::TEXTURE_WIDTH,
			camera_::TEXTURE_HEIGHT));
	ci::gl::draw(fade_tex, drawRect);
	ci::gl::color(1, 1, 1, 1);
	fade_tex->unbind();
	ci::gl::popModelMatrix();

}
