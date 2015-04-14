#pragma once

#include <vector>
#include "dimitrikourk/small3d/SceneObject.hpp"
#include "dimitrikourk/small3d/MathFunctions.hpp"
#include <cmath>
#include "Movil.h"

#define MAX_Z -1.0f
#define MIN_Z -24.0f
#define FULL_ROTATION 6.28f // More or less 360 degrees in radians
#define GROUND_Y 0.0f

class Goat: public Movil
{
	
public:
	void move();
	void init();
	
	void rotation_PosY();
	void rotation_NegY();
	void run();

	Goat();
	~Goat();

};

using namespace small3d;

Goat::Goat()
{
	Object = shared_ptr<SceneObject>(new SceneObject("goat", "Dani_MTB/small3d_develop_example/resources/models/Goat/goatAnim",19, "Dani_MTB/small3d_develop_example/resources/models/Goat/Goat.png","Dani_MTB/small3d_develop_example/resources/models/GoatBB/GoatBB.obj"));
	
	RotationSpeed = 0.000004f;
	Speed = 0.000002f;
}

Goat::~Goat()
{}

void Goat::rotation_PosY()
{
	shared_ptr<glm::vec3> goatRotation = Object->getRotation();
	goatRotation->y -= RotationSpeed;

	if (goatRotation->y < - FULL_ROTATION)
		goatRotation->y = 0.0f;

	Object->setRotation(0.0f, goatRotation->y, 0.0f);
	Object->animate();
	Object->startAnimating();
}

void Goat::rotation_NegY()
{
	shared_ptr<glm::vec3> goatRotation = Object->getRotation();
	goatRotation->y += RotationSpeed;

	if (goatRotation->y > FULL_ROTATION)
		goatRotation->y = 0.0f;

	Object->setRotation(0.0f, goatRotation->y, 0.0f);
	Object->animate();
	Object->startAnimating();
}

void Goat::run()
{
	shared_ptr<glm::vec3> goatRotation = Object->getRotation();
	shared_ptr<glm::vec3> goatOffset = Object->getOffset();
	goatOffset->x -= cos(goatRotation->y) * Speed;
	goatOffset->z -= sin(goatRotation->y) * Speed;
	Object->animate();
	Object->startAnimating();

}

void Goat::move()
{
	shared_ptr<glm::vec3> goatRotation = Object->getRotation();
	shared_ptr<glm::vec3> goatOffset = Object->getOffset();

	Object->stopAnimating();
}

void Goat::init()
{
	Object->setOffset(10.0f, 0.0f, -4.0f);
}
