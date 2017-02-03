#pragma once
#include<cinder/app/App.h>
#include <cinder/TriMesh.h>
#include <cinder/ObjLoader.h>
#include "../dessUI/Texture.h"
#include <cinder/gl/gl.h>
#include <cinder/GeomIo.h>
class EventManager {
private:
	ci::TriMesh mesh;
	std::shared_ptr<ci::TriMeshGeomTarget> a;
public:
	void setup();
	void update(const float& delta_time);
	void draw();

};