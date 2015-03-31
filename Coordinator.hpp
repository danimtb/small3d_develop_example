#include "KeyInput.hpp"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include <dimitrikourk/small3d/MathFunctions.hpp>
#include "World.hpp"


class Coordinator
{
public:
    Coordinator(void);
    virtual ~Coordinator(void);
    void keyboard(KeyInput k);
    void move();
    void render();
    void init();
    void process();
	shared_ptr<small3d::Renderer> renderer;
	shared_ptr<small3d::Text> crusoeText48;

    World world;

private:
	enum GameState {START_SCREEN, PLAYING};
	GameState gameState;
	int seconds;
};

using namespace small3d;

Coordinator::Coordinator(void)
{
	gameState=START_SCREEN;
}

Coordinator::~Coordinator(void)
{
}

void Coordinator::process()
{
	
}

void Coordinator::keyboard(KeyInput k)
{
	if(gameState==START_SCREEN)
	{
		if(k.enter)
			gameState=PLAYING;
	}
	else
	{
		world.keyboard(k);
	}

}

void Coordinator::init()
{
}

void Coordinator::move()
{

}

void Coordinator::render()
{
	renderer->clearScreen();
	
	if(gameState == START_SCREEN)
	{
		float startScreenVerts[16] =
		{
			  -1.0f, -1.0f, 1.0f, 1.0f,
			  1.0f, -1.0f, 1.0f, 1.0f,
			  1.0f, 1.0f, 1.0f, 1.0f,
			  -1.0f, 1.0f, 1.0f, 1.0f
		  };
		renderer->renderImage(&startScreenVerts[0], "startScreen");
		
		if (seconds != 0)
		{
			SDL_Color textColour = {255, 100, 0, 255};
			crusoeText48->renderText("Goat not bitten for " + intToStr(seconds) + " seconds", textColour, -0.95f, -0.6f, 0.0f, -0.8f);
		}
	}
	else
	{
		world.render();
	}
	
	//Don`t remove this line. This line must be always at the end.
	renderer->swapBuffers();
}