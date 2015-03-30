#include "KeyInput.hpp"

class Coordinator
{
public:
    Coordinator(void);
    virtual ~Coordinator(void);
    void keyboard(KeyInput k);
    void move();
    void render();
    void init();
	shared_ptr<Renderer> renderer;
	shared_ptr<Text> crusoeText48;

    World world;

private:
	enum GameState {START_SCREEN, PLAYING};
	GameState gameState;
};

Coordinator::Coordinator(void)
{
	GameState=START_SCREEN;
}

virtual Coordinador::~Coordinator(void)
{
}

void Coordinador::keyboard(KeyInput k)
{
	if(GameState==START_SCREEN)
	{
		if(k.enter)
			GameState=PLAYING;
	}
	else
	{
		world.keyboard(k);
	}

}

void Coordinador::init()
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