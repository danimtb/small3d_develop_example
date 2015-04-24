#pragma once
#include <vector>
#include "dimitrikourk/small3d/SceneObject.hpp"
#include "dimitrikourk/small3d/MathFunctions.hpp"
#include <cmath>
#include "Movil.hpp"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include <dimitrikourk/small3d/MathFunctions.hpp>

#define MAX_Z -1.0f
#define MIN_Z -24.0f
#define FULL_ROTATION 6.28f // More or less 360 degrees in radians
#define GROUND_Y 0.0f

enum BugState {FLYING_STRAIGHT, TURNING, DIVING_DOWN, DIVING_UP};

class Bug: public Movil
{
private:
	float DiveTilt;
	float DiveDuration;
	float DiveDistance;
	float FlightHeight;
	float VerticalSpeed;
	int bugFramesInCurrentState;
	BugState bugState, bugPreviousState;

public:
	void move();
	void init();
	
	void turn();
	void turnRight();
	void turnLeft();
	void flightStraight();
	void diveUp();
	void diveDown();
	BugState get_State();

	void set_DiveTilt(float dt);
	float get_DiveTilt();
	void set_DiveDuration(float dd);
	float get_DiveDuration();
	void set_DiveDistance(float dd);
	float get_DiveDistance();
	void set_FlightHeight(float fh);
	float get_FlightHeight();

	int get_FramesInCurrentState();

	Bug();
	~Bug();

};
