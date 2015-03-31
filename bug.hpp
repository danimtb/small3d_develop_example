#include <vector>
#include "dimitrikourk/small3d/SceneObject.hpp"
#include "dimitrikourk/small3d/MathFunctions.hpp"
#include <cmath>

#define MAX_Z -1.0f
#define MIN_Z -24.0f
#define FULL_ROTATION 6.28f // More or less 360 degrees in radians
#define GROUND_Y -1.0f



class Bug
{
private:
	shared_ptr<small3d::SceneObject> BugObject;
	float RotationSpeed;
	float DiveTilt;
	float Speed;
	float DiveDuration;
	float DiveDistance;
	float FlightHeight;
	float VerticalSpeed;

	enum BugState {FLYING_STRAIGHT, TURNING, DIVING_DOWN, DIVING_UP};
    BugState bugState, bugPreviousState;
    int bugFramesInCurrentState;


public:
	shared_ptr<small3d::SceneObject> Object();
	void move();
	void set_RotationSpeed(float rs);
	float get_RotationSpeed();
	void set_DiveTilt(float dt);
	float get_DiveTilt();
	void set_Speed(float s);
	float get_Speed();
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
	BugObject = shared_ptr<small3d::SceneObject>(new small3d::SceneObject("bug", "Dani_MTB/small3d_develop_example/resources/models/Bug/bugAnim",9));
	BugObject->setColour(0.8f, 0.7f, 0.04f, 1.0f);
	BugObject->setFrameDelay(2);

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

shared_ptr<small3d::SceneObject> Bug::Object()
{
	return BugObject;
}

void Bug::move()
{
	shared_ptr<glm::vec3> bugRotation = BugObject->getRotation();
	shared_ptr<glm::vec3> bugOffset = BugObject->getOffset();

	float xDistance = BugObject->getOffset()->x;
	float zDistance = BugObject->getOffset()->z;
	float distance = ROUND_2_DECIMAL(sqrt(xDistance * xDistance + zDistance*zDistance));

	float objRelX = ROUND_2_DECIMAL(xDistance / distance);
	float objRelZ = ROUND_2_DECIMAL(zDistance / distance);

	float bugDirectionX = cos(BugObject->getRotation()->y);
	float bugDirectionZ = sin(BugObject->getRotation()->y);

	float dotPosDir = objRelX * bugDirectionX + objRelZ * bugDirectionZ; // dot product

	// Bug state: decide
	if(bugState == bugPreviousState)
	{
		++bugFramesInCurrentState;
	}
	else
	{
		bugFramesInCurrentState = 1;
	}

	bugPreviousState = bugState;

	if(bugState == DIVING_DOWN)
	{
		if (true)//(BugObject->getOffset()->x, BugObject->getOffset()->y, BugObject->getOffset()->z)
		{
			//COLISION#####################################################################
			//sound->play("bah");
			//seconds = (SDL_GetTicks() - startTicks) / 1000;
		}
			
		if(bugFramesInCurrentState > DiveDuration / 2)
		{
			bugState = DIVING_UP;
		}
	}
	else if (bugState == DIVING_UP)
	{
		if (true)//(BugObject->getOffset()->x, BugObject->getOffset()->y, BugObject->getOffset()->z)
		{
			//gameState = START_SCREEN;
		}
			
		if (bugFramesInCurrentState > DiveDuration / 2)
		{
			bugState = FLYING_STRAIGHT;
			bugOffset->y = GROUND_Y + FlightHeight; // Correction of possible rounding errors
		}
	}
	else
	{
		if (distance > DiveDistance)
		{
			if (dotPosDir < 0.98f)
			{
				bugState = TURNING;
			}
			else
			{
				bugState = FLYING_STRAIGHT;
			}
		}
		else
		{
			bugState = DIVING_DOWN;
		}
	}

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

		if(bugOffset->z < MIN_Z)
			bugOffset->z = MIN_Z;
		
		if (bugOffset->z > MAX_Z) 
			bugOffset->z = MAX_Z;

		if(bugOffset->x < bugOffset-> z)
			bugOffset->x = bugOffset-> z;
		
		if (bugOffset->x > -(bugOffset->z)) 
			bugOffset->x = -(bugOffset->z);

		BugObject->animate();

}

void Bug::set_RotationSpeed(float rs)
{
	RotationSpeed=rs;
}

float Bug::get_RotationSpeed()
{
	return RotationSpeed;
}

void Bug::set_DiveTilt(float dt)
{
	DiveTilt = dt;
}

float Bug::get_DiveTilt()
{
	return DiveTilt;
}

void Bug::set_Speed(float s)
{
	Speed = s;
}

float Bug::get_Speed()
{
	return Speed;
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