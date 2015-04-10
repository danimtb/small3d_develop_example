#include "KeyInput.hpp"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include "Bug.hpp"
#include "Goat.hpp"
#include "Plane.h"
#include "Interaction.h"

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
    void keyboard(KeyInput k);
    void loadScene(shared_ptr<small3d::Renderer> &rend);
	World();
    ~World();
    void move();
    void init();
    void render(shared_ptr<small3d::Renderer> &rend);
    void dontMove();
};

using namespace small3d;

World::World()
{
    ground.setPos(10.0f, -10.0f, 0.0f, 0.0f, -1.0f, -16.0f);
    sky.setPos(1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f);

    virtual1.setPos(5.0f, -5.0f, 1.0f, 0.0f, -8.0f, -8.0f);
    virtual2.setPos(5.0f, 5.0f, 1.0f, 0.0f, -8.0f, -1.0f);
}

World::~World()
{}

void World::loadScene(shared_ptr<small3d::Renderer> &rend)
{
    ground.load(rend, "Dani_MTB/small3d_develop_example/resources/images/grass.png", "ground");

    sky.load(rend, "Dani_MTB/small3d_develop_example/resources/images/sky.png", "sky");
    virtual1.load(rend, "Dani_MTB/small3d_develop_example/resources/images/sky.png", "virtual1");
    virtual2.load(rend, "Dani_MTB/small3d_develop_example/resources/images/sky.png", "virtual2");
}

void World::init()
{
    bug.init();
    goat.init();

    startTicks = SDL_GetTicks();
}

void World::move()
{
    bug.move();
    goat.move();

    Interaction::field(goat, ground);
    Interaction::field(goat, virtual1);
}

void World::render(shared_ptr<small3d::Renderer> &rend)
{
    // Draw the background
    ground.render(rend, true);
    sky.render(rend, false);
    virtual1.render(rend, true);
    virtual2.render(rend, true);

    bug.render(rend);
    goat.render(rend);

    //CAMERA POSITION
    shared_ptr<glm::vec3> cameraPos = shared_ptr<glm::vec3>(new glm::vec3(0, 2, 5)); //0, 2, 2
    rend->cameraPosition = *cameraPos;
}

void World::keyboard(KeyInput k)
{
    if(k.up)
    {
        goat.run();
    }
    if(k.down)
    {

    }
    if(k.right)
    {
        goat.rotation_NegY();
    }
    if(k.left)
    {
        goat.rotation_PosY();
    }
}

void World::dontMove()
{
    bug.dontMove();
    goat.dontMove();
}