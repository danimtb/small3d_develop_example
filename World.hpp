#include "KeyInput.hpp"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include "Bug.hpp"
#include "Goat.hpp"
#include "Pared.h"

class World
{
private:

	//shared_ptr<SceneObject> goat;
    Bug bug;
    Goat goat;
    Pared suelo;
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
    //suelo.setPos()
}

World::~World()
{


}

void World::loadScene(shared_ptr<small3d::Renderer> &rend)
{
    //rendererWorld=rend;

    //unique_ptr<Image> groundTexture(new Image("Dani_MTB/small3d_develop_example/resources/images/grass.png"));
    //rend->generateTexture("ground", groundTexture->getData(), groundTexture->getWidth(), groundTexture->getHeight());
    suelo.load(rend, "Dani_MTB/small3d_develop_example/resources/images/grass.png", "ground");

    unique_ptr<Image> skyTexture(new Image("Dani_MTB/small3d_develop_example/resources/images/sky.png"));
    rend->generateTexture("sky", skyTexture->getData(), skyTexture->getWidth(), skyTexture->getHeight());
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
}

void World::render(shared_ptr<small3d::Renderer> &rend)
{
    float skyVerts[16] =
      {
        -1.0f, -1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, 1.0f
      };

    rend->renderImage(&skyVerts[0], "sky");


    // Draw the background
    suelo.render(rend);
    /*float groundVerts[16] =
      {
        -25.0f, GROUND_Y, MAX_Z, 1.0f,
        25.0f, GROUND_Y, MAX_Z, 1.0f,
        25.0f, GROUND_Y,  MIN_Z, 1.0f,
        -25.0f, GROUND_Y, MIN_Z, 1.0f
      };

    rend->renderImage(&groundVerts[0], "ground", true, glm::vec3(0.0f, 0.0f, 0.0f));
    */

    bug.render(rend);
    goat.render(rend);

    //CAMERA POSITION
    shared_ptr<glm::vec3> cameraPos = shared_ptr<glm::vec3>(new glm::vec3(0, 1, 2));
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