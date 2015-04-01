/*
 *  main.cpp
 *
 *  Created on: 2014/11/09
 *      Author: Dimitri Kourkoulis
 *              http://dimitros.be
 *     License: BSD 3-Clause License (see LICENSE file)
 */

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <cstdlib>
#include <iostream>
#include <dimitrikourk/small3d/Exception.hpp>
#include <memory>

#include "KeyInput.hpp"
#include "Coordinator.hpp"

using namespace std;
using namespace small3d;

const GLuint frameRate = 60;
KeyInput input;

int main(int argc, char** argv)
{
	  // Set up a console, if using MinGW
	  // This is because the mwindows linker flag,
	  // used by blocks referenced by small3d,
	  // eliminates the default one.
	#ifdef __MINGW32__
	  AllocConsole();
	  freopen("CONOUT$", "w", stdout);
	#endif

	  //Coordinator coordinatorBii;

	  try
	  {
		  shared_ptr<Coordinator> coordinatorBii(new Coordinator());
		  
		  // program main loop
		  bool quit = false;
		  
		  // ticks for setting the frame rate
		  GLuint ticks = SDL_GetTicks();
		  GLuint prevTicks = ticks;
		  GLuint ticksInterval = 1000 / frameRate;
		  
		  while (!quit)
		  {
		  	quit=input.OnKeyboardDown();

		  	coordinatorBii->keyboard(input);
			  
			  ticks = SDL_GetTicks();
	  
			  if (ticks - prevTicks > ticksInterval)
			  {
				  coordinatorBii->process();
				  coordinatorBii->render();
				  prevTicks = ticks;
			  }
		  }
	  }
	  
	  catch (Exception &e)
	  {
		  LOGERROR(e.what());
		  return 1;
	  }
	  
	  return 0;
	}
