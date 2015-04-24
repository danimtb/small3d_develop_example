#pragma once

#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include <dimitrikourk/small3d/MathFunctions.hpp>

class Movil
{
protected:
	shared_ptr<small3d::SceneObject> Object;
	float RotationSpeed;
	float Speed;
	~Movil();
public:
	Movil();
	void dontMove();
	void set_RotationSpeed(float rs);
	float get_RotationSpeed();
	void set_Speed(float s);
	float get_Speed();
	void set_Offset(shared_ptr<glm::vec3> off);
	shared_ptr<glm::vec3> get_Offset();
	void set_Rotation(shared_ptr<glm::vec3> rot);
	shared_ptr<glm::vec3> get_Rotation();
	bool collidesWithPoint(float _x, float _y, float _z);

	virtual void move();
	virtual void init();
	virtual void render(shared_ptr<small3d::Renderer> &r);

};

