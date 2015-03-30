#pragma once
#ifndef KEYINPUT_H_
#define KEYINPUT_H_

   // Structure holding the state of keys on the keyboard that are related to the game.

typedef struct KeyInput
{
	bool up, down, left, right, enter, one, two, three;

    KeyInput()
    {
      up = false;
      down = false;
      left = false;
      right = false;
      enter = false;
      one = false;
      two = false;
      three = false;
    }

  } KeyInput;
}

#endif
