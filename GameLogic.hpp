/*
 *  GameLogic.hpp
 *
 *  Created on: 2014/11/09
 *      Author: Dimitri Kourkoulis
 *              http://dimitros.be
 *     License: BSD 3-Clause License (see LICENSE file)
 */

#pragma once

#include <memory>
#include <vector>
#include <algorithm>
#include "dimitrikourk/small3d/Logger.hpp"
#include "dimitrikourk/small3d/SceneObject.hpp"
#include "dimitrikourk/small3d/Renderer.hpp"
#include "dimitrikourk/small3d/Text.hpp"
#include "dimitrikourk/small3d/Sound.hpp"
#include "KeyInput.hpp"

using namespace small3d;

namespace AvoidTheBug3D {

  /**
   * @class	GameLogic
   *
   * @brief	The main body of the sample game.
   *
   */

  class GameLogic {

  private:

    shared_ptr<SceneObject> goat;

    shared_ptr<SceneObject> bug;
    shared_ptr<SceneObject> bug2;
    shared_ptr<SceneObject> bug3;

    shared_ptr<SceneObject> tree;
    shared_ptr<SceneObject> tree2;

    shared_ptr<Renderer> renderer;

    shared_ptr<Text> crusoeText48;

    shared_ptr<Sound> sound;

    enum GameState {START_SCREEN, PLAYING};
    GameState gameState;

    enum BugState {FLYING_STRAIGHT, TURNING, DIVING_DOWN, DIVING_UP};
    BugState bugState, bugPreviousState, bug2State, bug2PreviousState,bug3State, bug3PreviousState;
    int bugFramesInCurrentState, bug2FramesInCurrentState, bug3FramesInCurrentState;
    float bugVerticalSpeed, bug2VerticalSpeed, bug3VerticalSpeed;

    unsigned int startTicks;
    int seconds;

    void initGame(int level);
    void processGame( const KeyInput &keyInput , const int level);
    void processStartScreen( const KeyInput &keyInput, int &lvl );

    void moveGoat(const KeyInput &keyInput);
    void moveBug();
    void moveBug2();
    void moveBug3();
		
  public:

    GameLogic();
    ~GameLogic();
    void process(const KeyInput &keyInput, int &level);
    void render();
    float lightModifier; 
  };

}

