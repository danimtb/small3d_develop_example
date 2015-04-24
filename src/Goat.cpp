#include "Goat.hpp"

using namespace small3d;

Goat::Goat()
{
	Object = shared_ptr<SceneObject>(new SceneObject("goat", "Dani_MTB/small3d_develop_example/resources/models/Goat/goatAnim",19, "Dani_MTB/small3d_develop_example/resources/models/Goat/Goat.png","Dani_MTB/small3d_develop_example/resources/models/GoatBB/GoatBB.obj"));
	Object->setColour(1.0f, 0.0f, 0.0f, 1.0f);
	
	RotationSpeed = 0.000004f;
	Speed = 0.000001f;
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
