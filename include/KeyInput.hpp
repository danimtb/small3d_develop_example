#pragma once
#ifndef KEYINPUT_H_
#define KEYINPUT_H_

#include "miguel/sdl2/include/SDL.h"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include <dimitrikourk/small3d/MathFunctions.hpp>

   // Class holding the state of keys on the keyboard that are related to the game.

class KeyInput
{
public:
  bool up;
  bool down;
  bool left;
  bool right;
  bool enter;
  bool p;
  bool one;
  bool two;
  bool three;

  KeyInput();
  ~KeyInput();
  bool OnKeyboardDown();
};

#endif
