#include "KeyInput.hpp"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>

class World
{
private:

	//shared_ptr<SceneObject> goat;
	//shared_ptr<SceneObject> bug;
    //shared_ptr<SceneObject> tree;

    shared_ptr<small3d::Renderer> renderer;
	shared_ptr<small3d::Text> crusoeText48;
	shared_ptr<small3d::Sound> sound;

    //enum GameState {START_SCREEN, PLAYING};
    //GameState gameState;

    unsigned int startTicks;
    int seconds;

    void initGame();
    void processGame();
    void processStartScreen();

    void move();
	float lightModifier;

public:
    void keyboard(KeyInput k);
	World();
    ~World();
    void process();
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

void World::processGame()
{

}

void World::processStartScreen()
{

}


void World::process()
{
}
void World::render()
{

}

void World::keyboard(KeyInput k)
{
}