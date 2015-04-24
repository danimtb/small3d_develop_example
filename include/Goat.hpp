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