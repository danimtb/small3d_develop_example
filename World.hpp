
class World
{
private:

	//shared_ptr<SceneObject> goat;
	//shared_ptr<SceneObject> bug;
    //shared_ptr<SceneObject> tree;

    shared_ptr<Renderer> renderer;
	shared_ptr<Text> crusoeText48;
	shared_ptr<Sound> sound;

    //enum GameState {START_SCREEN, PLAYING};
    //GameState gameState;

    unsigned int startTicks;
    int seconds;

    void initGame(int level);
    void processGame( const KeyInput &keyInput , const int level);
    void processStartScreen( const KeyInput &keyInput, int &lvl );

    void move();
	float lightModifier;

public:
	World();
    ~World();
    void process(const KeyInput &keyInput, int &level);
    void render(); 
};