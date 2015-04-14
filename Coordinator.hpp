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
	enum GameState {START_SCREEN, PLAYING, PAUSE};
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

	unique_ptr<Image> pauseScreenTexture( new Image("Dani_MTB/small3d_develop_example/resources/images/pauseScreen.png") );
	renderer->generateTexture("pauseScreen", pauseScreenTexture->getData(), pauseScreenTexture->getWidth(), pauseScreenTexture->getHeight());

	world.loadScene(renderer);

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
		{
			gameState=PLAYING;
			world.init();
		}
	}
	if(gameState==PLAYING)
	{
		if(k.p)
		{
			gameState=PAUSE;
		}
		else
		{
			world.keyboard(k);
		}
	}
	if(gameState==PAUSE)
	{
		if(k.enter)
			gameState=PLAYING;
	}

}

void Coordinator::process()
{
	switch(gameState)
	{
		case START_SCREEN:
      		break;
    	
    	case PLAYING:
      		world.move();
      		break;

      	case PAUSE:
      		//world.dontMove();
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
	
	if(gameState==PLAYING)
	{
		world.render(renderer);
	}

	if(gameState==PAUSE)
	{
		//world.render(renderer);

		float pauseScreenVerts[16] =
		{
			  -1.0f, -1.0f, 1.0f, 1.0f,
			  1.0f, -1.0f, 1.0f, 1.0f,
			  1.0f, 1.0f, 1.0f, 1.0f,
			  -1.0f, 1.0f, 1.0f, 1.0f
		  };
		renderer->renderImage(&pauseScreenVerts[0], "pauseScreen");
		SDL_Color colour = {255, 100, 0, 255};
		crusoeText48->renderText("Press <ENTER> to resume the game", colour, -0.95f, -0.6f, 0.0f, -0.8f);
	}
	
	//Don`t remove this line. This line must be always at the end.
	renderer->swapBuffers();
}