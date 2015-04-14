#include <vector>
#include "dimitrikourk/small3d/SceneObject.hpp"
#include "dimitrikourk/small3d/MathFunctions.hpp"
#include <cmath>
#include "Movil.h"

#define MAX_Z -1.0f
#define MIN_Z -24.0f
#define FULL_ROTATION 6.28f // More or less 360 degrees in radians
#define GROUND_Y 0.0f



class Bug: public Movil
{
private:
	float DiveTilt;
	float DiveDuration;
	float DiveDistance;
	float FlightHeight;
	float VerticalSpeed;

	enum BugState {FLYING_STRAIGHT, TURNING, DIVING_DOWN, DIVING_UP};
    BugState bugState, bugPreviousState;
    int bugFramesInCurrentState;

public:
	void move();
	void init();
	
	void turn();
	void flightStraight();
	void diveUp();
	void diveDown();

	void set_DiveTilt(float dt);
	float get_DiveTilt();
	void set_DiveDuration(float dd);
	float get_DiveDuration();
	void set_DiveDistance(float dd);
	float get_DiveDistance();
	void set_FlightHeight(float fh);
	float get_FlightHeight();

	Bug();
	~Bug();

};

Bug::Bug()
{
	Object = shared_ptr<small3d::SceneObject>(new small3d::SceneObject("bug", "Dani_MTB/small3d_develop_example/resources/models/Bug/bugAnim",9));
	Object->setColour(1.0f, 0.0f, 0.0f, 1.0f);
	Object->setFrameDelay(2);

	RotationSpeed = 0.12f;
	DiveTilt = 0.8f;
	Speed = .08f;
	DiveDuration = 30.0f;
	DiveDistance = 0.6f;
	FlightHeight = 1.4f;
	VerticalSpeed = ROUND_2_DECIMAL(FlightHeight / DiveDuration);
}

Bug::~Bug()
{}

void Bug::move()
{
	shared_ptr<glm::vec3> bugRotation = Object->getRotation();
	shared_ptr<glm::vec3> bugOffset = Object->getOffset();

	float xDistance = Object->getOffset()->x;
	float zDistance = Object->getOffset()->z;
	float distance = ROUND_2_DECIMAL(sqrt(xDistance * xDistance + zDistance*zDistance));

	float objRelX = ROUND_2_DECIMAL(xDistance / distance);
	float objRelZ = ROUND_2_DECIMAL(zDistance / distance);

	float bugDirectionX = cos(Object->getRotation()->y);
	float bugDirectionZ = sin(Object->getRotation()->y);

	float dotPosDir = objRelX * bugDirectionX + objRelZ * bugDirectionZ; // dot product

	// Bug state: represent
    bugRotation->z = 0;

    if (bugState == TURNING)
    {
    	bugRotation->y -= RotationSpeed;
    }
    else if (bugState == DIVING_DOWN)
    {
    	bugRotation->z = -DiveTilt;
    	bugOffset->y -= VerticalSpeed;
    }
    else if (bugState == DIVING_UP)
    {
    	bugRotation->z = DiveTilt;
    	bugOffset->y += VerticalSpeed;
    }

	if(bugRotation->y < -FULL_ROTATION)
		bugRotation->y = 0.0f;

	bugOffset->x -= cos(bugRotation->y) * Speed;
	bugOffset->z -= sin(bugRotation->y) * Speed;

	Object->animate();
	Object->startAnimating();
}

void Bug::set_DiveTilt(float dt)
{
	DiveTilt = dt;
}

float Bug::get_DiveTilt()
{
	return DiveTilt;
}

void Bug::set_DiveDuration(float dd)
{
	DiveDuration =dd;
	VerticalSpeed = ROUND_2_DECIMAL(FlightHeight / DiveDuration);
}

float Bug::get_DiveDuration()
{
	return DiveDuration;
}

void Bug::set_DiveDistance(float dd)
{
	DiveDistance = dd;
}

float Bug::get_DiveDistance()
{
	return DiveDistance;
}

void Bug::set_FlightHeight(float fh)
{
	FlightHeight = fh;
	VerticalSpeed = ROUND_2_DECIMAL(FlightHeight / DiveDuration);
}

float Bug::get_FlightHeight()
{
	return FlightHeight;
}

void Bug::init()
{
	Object->setOffset(10.5f, GROUND_Y + FlightHeight, -4.0f);

    bugState = FLYING_STRAIGHT;
    bugPreviousState = FLYING_STRAIGHT;
    bugFramesInCurrentState = 1;
}

void Bug::turn()
{

}

void Bug::flightStraight()
{

}

void Bug::diveUp()
{
	bugState = DIVING_UP;
}

void Bug::diveDown()
{

}
