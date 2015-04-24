#include "Bug.hpp"


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
	bugState=FLYING_STRAIGHT;
	bugFramesInCurrentState = 1;
}

Bug::~Bug()
{}

void Bug::move()
{
	shared_ptr<glm::vec3> bugRotation = Object->getRotation();
    shared_ptr<glm::vec3> bugOffset = Object->getOffset();

	if (bugState == bugPreviousState)
    {
    	++bugFramesInCurrentState;
    }
    else
    {
    	bugFramesInCurrentState = 1;
    }

    bugPreviousState = bugState;

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
	Object->setOffset(13.5f, GROUND_Y + FlightHeight, -6.0f);

    bugState = FLYING_STRAIGHT;
    bugPreviousState = FLYING_STRAIGHT;
    bugFramesInCurrentState = 1;
}

void Bug::turnLeft()
{
	//bugState = TURNING;
	shared_ptr<glm::vec3> bugRotation = Object->getRotation();
	bugRotation->y += RotationSpeed;
}

void Bug::turnRight()
{
	//bugState = TURNING;
	shared_ptr<glm::vec3> bugRotation = Object->getRotation();
	bugRotation->y -= RotationSpeed;
}

void Bug::flightStraight()
{
	bugState = FLYING_STRAIGHT;
}

void Bug::diveUp()
{
	bugState = DIVING_UP;
}

void Bug::diveDown()
{
	bugState = DIVING_DOWN;	
}

void Bug::turn()
{
	bugState = TURNING;	
}

BugState Bug::get_State()
{
	return bugState;
}

int Bug::get_FramesInCurrentState()
{
	return bugFramesInCurrentState;
}