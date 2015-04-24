#include "KeyInput.hpp"

KeyInput::KeyInput()
{
  up = false;
  down = false;
  left = false;
  right = false;
  enter = false;
  p = false;
  one = false;
  two = false;
  three = false;
}

KeyInput::~KeyInput()
{}

bool KeyInput::OnKeyboardDown()
{
  SDL_Event event;
  bool skip = false;
  
  if (SDL_PollEvent(&event))
  {
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);

    up = keyState[SDL_SCANCODE_UP] == 1;
    down = keyState[SDL_SCANCODE_DOWN] == 1;
    left = keyState[SDL_SCANCODE_LEFT] == 1;
    right = keyState[SDL_SCANCODE_RIGHT] == 1;
    enter = keyState[SDL_SCANCODE_RETURN] == 1;
    p = keyState[SDL_SCANCODE_P] == 1;
    one = keyState[SDL_SCANCODE_1] == 1;
    two = keyState[SDL_SCANCODE_2] == 1;
    three = keyState[SDL_SCANCODE_3] == 1;

    switch (event.type)
    {
      case SDL_QUIT:
        skip = true;
        break;
    
      case SDL_KEYDOWN:
      {
        if (event.key.keysym.sym == SDLK_ESCAPE)
          skip = true;
        break;
      }
    }
  }
  return skip;
}