#pragma once

#include <vector>
#include "dimitrikourk/small3d/SceneObject.hpp"
#include "dimitrikourk/small3d/MathFunctions.hpp"
#include <cmath>

#define MAX_Z -1.0f
#define MIN_Z -24.0f
#define FULL_ROTATION 6.28f // More or less 360 degrees in radians
#define GROUND_Y 0.0f

class Goat
{
private:
	shared_ptr<small3d::SceneObject> GoatObject;
	float RotationSpeed;
	float Speed;
	
public:
	shared_ptr<small3d::SceneObject> Object();
	void move();
	void init();
	void dontMove();
	void set_RotationSpeed(float rs);
	float get_RotationSpeed();
	void set_Speed(float s);
	float get_Speed();
	void render(shared_ptr<small3d::Renderer> &r);
	void set_Offset(shared_ptr<glm::vec3> off);
	shared_ptr<glm::vec3> get_Offset();
	
	void rotation_PosY();
	void rotation_NegY();
	void run();

	Goat();
	~Goat();

};

using namespace small3d;

Goat::Goat()
{
	GoatObject = shared_ptr<SceneObject>(new SceneObject("goat", "Dani_MTB/small3d_develop_example/resources/models/Goat/goatAnim",19, "Dani_MTB/small3d_develop_example/resources/models/Goat/Goat.png","Dani_MTB/small3d_develop_example/resources/models/GoatBB/GoatBB.obj"));
	
	RotationSpeed = 0.000004f;
	Speed = 0.000002f;
}

Goat::~Goat()
{}

shared_ptr<small3d::SceneObject> Goat::Object()
{
	return GoatObject;
}

void Goat::render(shared_ptr<small3d::Renderer> &r)
{
	r->renderSceneObject(GoatObject);
}

void Goat::rotation_PosY()
{
	shared_ptr<glm::vec3> goatRotation = GoatObject->getRotation();
	goatRotation->y -= RotationSpeed;

	if (goatRotation->y < - FULL_ROTATION)
		goatRotation->y = 0.0f;

	GoatObject->setRotation(0.0f, goatRotation->y, 0.0f);
	GoatObject->animate();
	GoatObject->startAnimating();
}

void Goat::rotation_NegY()
{
	shared_ptr<glm::vec3> goatRotation = GoatObject->getRotation();
	goatRotation->y += RotationSpeed;

	if (goatRotation->y > FULL_ROTATION)
		goatRotation->y = 0.0f;

	GoatObject->setRotation(0.0f, goatRotation->y, 0.0f);
	GoatObject->animate();
	GoatObject->startAnimating();
}

void Goat::run()
{
	shared_ptr<glm::vec3> goatRotation = GoatObject->getRotation();
	shared_ptr<glm::vec3> goatOffset = GoatObject->getOffset();
	goatOffset->x -= cos(goatRotation->y) * Speed;
	goatOffset->z -= sin(goatRotation->y) * Speed;
	GoatObject->animate();
	GoatObject->startAnimating();

}

void Goat::move()
{
	shared_ptr<glm::vec3> goatRotation = GoatObject->getRotation();
	shared_ptr<glm::vec3> goatOffset = GoatObject->getOffset();

	GoatObject->stopAnimating();
}

void Goat::dontMove()
{
	GoatObject->stopAnimating();
}

void Goat::set_Speed(float s)
{
	Speed = s;
}

float Goat::get_Speed()
{
	return Speed;
}

void Goat::init()
{
	GoatObject->setOffset(-1.2f, 0.0f, -4.0f);
}

void Goat::set_RotationSpeed(float rs)
{
	RotationSpeed=rs;
}

float Goat::get_RotationSpeed()
{
	return RotationSpeed;
}

void Goat::set_Offset(shared_ptr<glm::vec3> off)
{
	GoatObject->setOffset(off->x, off->y, off->z);
}

shared_ptr<glm::vec3> Goat::get_Offset()
{
	return GoatObject->getOffset();
}