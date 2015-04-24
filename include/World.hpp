#pragma once

#include "KeyInput.hpp"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include "Bug.hpp"
#include "Goat.hpp"
#include "Plane.hpp"
#include "Interaction.hpp"

class World
{
private:

	//shared_ptr<SceneObject> goat;
    Bug bug;
    Goat goat;
    Plane ground;
    Plane sky;
    Plane virtual1;
    Plane virtual2;
    Plane virtual3;
    Plane virtual4; 
	//shared_ptr<SceneObject> bug;
    //shared_ptr<SceneObject> tree;

    shared_ptr<small3d::Renderer> *rendererWorld;
	shared_ptr<small3d::Text> crusoeText48;
	shared_ptr<small3d::Sound> sound;

    unsigned int startTicks;
    int seconds;

	float lightModifier;

public:
    bool end;
    void keyboard(KeyInput k);
    void loadScene(shared_ptr<small3d::Renderer> &rend);
	World();
    ~World();
    void move();
    void init();
    void render(shared_ptr<small3d::Renderer> &rend);
    void dontMove();
};