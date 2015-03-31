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
    void process();
    void render();

    float lightModifier; 

    World world;

private:
	enum GameState {START_SCREEN, PLAYING};
	GameState gameState;
	
	unsigned int startTicks;
	int seconds;
	
	shared_ptr<small3d::Renderer> renderer;
	shared_ptr<small3d::Text> crusoeText48;
	shared_ptr<small3d::Sound> sound;
};

using namespace small3d;

Coordinator::Coordinator(void)
{
	initLogger();
	renderer = shared_ptr<Renderer>(new Renderer());

	gameState=START_SCREEN;

	renderer->init(854, 480, false);
    crusoeText48 = shared_ptr<Text>(new Text(renderer));

	unique_ptr<Image> startScreenTexture( new Image("Dani_MTB/small3d_develop_example/resources/images/startScreen.png") );
	renderer->generateTexture("startScreen", startScreenTexture->getData(), startScreenTexture->getWidth(), startScreenTexture->getHeight());

	startTicks = 0;
    seconds = 0;

    lightModifier= -0.01f;
}

Coordinator::~Coordinator(void)
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

void Coordinator::process()
{
	switch(gameState)
	{
		case START_SCREEN:
			//processStartScreen(keyInput);
      		break;
    	
    	case PLAYING:
      		world.move();
      		break;

    	default:
      		throw Exception("Urecognised game state");
      		break;
    }
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