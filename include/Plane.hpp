#pragma once

#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include <dimitrikourk/small3d/MathFunctions.hpp>

class Plane
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	char *name;
	char *route;

	float max_z;
	float min_z;
	float max_y;
	float min_y;
	float max_x;
	float min_x;

public:
	Plane(void);
	virtual ~Plane(void);
	void load(shared_ptr<small3d::Renderer> &r, char *_route, char *_name);
	void render(shared_ptr<small3d::Renderer> &r, bool perspective);
	void setColor(int, int, int);
	void setPos(float maxX, float minX, float maxY, float minY, float maxZ, float minZ);
	float maxX();
	float minX();
	float maxY();
	float minY();
	float maxZ();
	float minZ();
	
	//float Distancia(Vector2D punto, Vector2D *direccion);

	friend class Interaction;
};