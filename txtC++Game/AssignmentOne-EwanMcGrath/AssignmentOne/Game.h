#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Enemy.h"
#include <stdlib.h> //I don't actually know if this is needed - It's not needed as another library contains rand
#include <time.h> //Allows for seeding of rand

using namespace std;

class Game
{

public:
	Game();
	~Game();

	void init();//Create objects, assign spawn vars. Put in vector of gameObject pointers
	void draw();//Cycle through obj's, call draw func
	void update();//Cycle through obj's, call update func
	void battle();//Check vector to see if obj's occupy same cords. Commence battle
	void info();//Cycle through obj's and display info
	void clean();//Use isAlive func
	bool checkRunning();

protected:
	vector<GameObject*>vp_GameObjects;
	void spawnEnemies();
	void spawnPlayer();
	bool m_IsRunning;
};

#endif // !GAME_H