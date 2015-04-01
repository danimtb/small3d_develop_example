#include <vector>
#include "dimitrikourk/small3d/SceneObject.hpp"
#include "dimitrikourk/small3d/MathFunctions.hpp"
#include <cmath>

#define MAX_Z -1.0f
#define MIN_Z -24.0f
#define FULL_ROTATION 6.28f // More or less 360 degrees in radians
#define GROUND_Y -1.0f

class Goat
{
private:
	shared_ptr<small3d::SceneObject> GoatObject;
	float RotationSpeed;
	float Speed;

public:
	void move();
	shared_ptr<small3d::SceneObject> Object();
	//void set_RotationSpeed(float rs);
	//float get_RotationSpeed();
	void set_Speed(float s);
	float get_Speed();
	void render(shared_ptr<small3d::Renderer> &r);
	void startAnimating();
	void set_Offset();
	void init();
	void dontMove();
	void rotation_PosY();
	void run();

	Goat();
	~Goat();

};

using namespace small3d;

Goat::Goat()
{
	GoatObject = shared_ptr<SceneObject>(new SceneObject("goat", "Dani_MTB/small3d_develop_example/resources/models/Goat/goatAnim",19, "Dani_MTB/small3d_develop_example/resources/models/Goat/Goat.png","Dani_MTB/small3d_develop_example/resources/models/GoatBB/GoatBB.obj"));
	
	RotationSpeed = 0.1f;
	Speed = 0.05f;
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
	GoatObject->startAnimating();
}

void Goat::run()
{
	shared_ptr<glm::vec3> goatRotation = GoatObject->getRotation();
	shared_ptr<glm::vec3> goatOffset = GoatObject->getOffset();
	goatOffset->x -= cos(goatRotation->y) * Speed;
	goatOffset->z -= sin(goatRotation->y) * Speed;
	GoatObject->startAnimating();
}

void Goat::move()
{
	shared_ptr<glm::vec3> goatRotation = GoatObject->getRotation();
	shared_ptr<glm::vec3> goatOffset = GoatObject->getOffset();

	GoatObject->stopAnimating();
/*
	if(keyInput.left)
	{
		goatRotation->y -= GOAT_ROTATION_SPEED;


	  if (goatRotation->y < - FULL_ROTATION)
		  goatRotation->y = 0.0f;
	  		
	  goat->startAnimating();

	}
	else if (keyInput.right)
	{
		goatRotation->y += GOAT_ROTATION_SPEED;
			
		if (goatRotation->y > FULL_ROTATION)
			goatRotation->y = 0.0f;
			
		goat->startAnimating();
	}

	if(keyInput.up)
	{
		goatOffset->x -= cos(goatRotation->y) * GOAT_SPEED;
		goatOffset->z -= sin(goatRotation->y) * GOAT_SPEED;

		goat->startAnimating();
	}
	else if (keyInput.down)
	{
		goatOffset->x += cos(goatRotation->y) * GOAT_SPEED;
		goatOffset->z += sin(goatRotation->y) * GOAT_SPEED;

		goat->startAnimating();
	}
	*/

	if(goatOffset->z < MIN_Z +1.0f)
		goatOffset->z = MIN_Z +1.0f;
		
	if(goatOffset->z > MAX_Z -1.0f) 
		goatOffset->z = MAX_Z -1.0f;

	if(goatOffset->x < goatOffset-> z)
		goatOffset->x = goatOffset-> z;
		
	if(goatOffset->x > -(goatOffset->z)) 
		goatOffset->x = -(goatOffset->z);

	GoatObject->animate();
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

void Goat::startAnimating()
{
	GoatObject->startAnimating();
}

void Goat::set_Offset()
{
}

void Goat::init()
{
	GoatObject->setOffset(-1.2f, GROUND_Y, -4.0f);
}