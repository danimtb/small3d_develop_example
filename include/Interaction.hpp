#pragma once

#include "Plane.hpp"
#include "Goat.hpp"
#include "Movil.hpp"
#include "Bug.hpp"
#include "miguel/sdl2/include/SDL.h"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include <dimitrikourk/small3d/MathFunctions.hpp>

class Interaction
{
public:
	Interaction();
	virtual ~Interaction();

	static void field(Movil &m, Plane p);
	static bool chase(Bug &b, Goat g);
	int bugFramesInCurrentState;
};