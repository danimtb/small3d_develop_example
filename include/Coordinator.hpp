#include "KeyInput.hpp"
#include <dimitrikourk/small3d/Logger.hpp>
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>
#include <dimitrikourk/small3d/Text.hpp>
#include <dimitrikourk/small3d/Sound.hpp>
#include <dimitrikourk/small3d/MathFunctions.hpp>
#include <dimitrikourk/small3d/Exception.hpp>
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