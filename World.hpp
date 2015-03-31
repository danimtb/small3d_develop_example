#include "KeyInput.hpp"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include "bug.hpp"

class World
{
private:

	//shared_ptr<SceneObject> goat;
    Bug bug;
	//shared_ptr<SceneObject> bug;
    //shared_ptr<SceneObject> tree;

    shared_ptr<small3d::Renderer> renderer;
	shared_ptr<small3d::Text> crusoeText48;
	shared_ptr<small3d::Sound> sound;

    unsigned int startTicks;
    int seconds;

    void initGame();

	float lightModifier;

public:
    void keyboard(KeyInput k);
	World();
    ~World();
    void move();
    void render(); 
};

World::World()
{

}

World::~World()
{

}

void World::initGame()
{

}

void World::move()
{
}
void World::render()
{

}

void World::keyboard(KeyInput k)
{
}