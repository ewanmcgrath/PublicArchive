#include "Game.h"

Game::Game()
{m_IsRunning = true;} // Used for game logic

Game::~Game()
{}

void Game::init()
{
	spawnPlayer(); // Initializes the player
	spawnEnemies(); // Initializes the enemies
}

void Game::draw()
{
	// cycle through the vector of Game Objects ( enemy and player objects) and call the draw function for each object
	vector<GameObject*>::iterator it;
	for (it = vp_GameObjects.begin(); it != vp_GameObjects.end(); it++)
	{
		(*it)->draw();
	}
}

void Game::update()
{
	//cycle through the vector of Game Objects (enemy and player objects) and call the update function for each object
	vector<GameObject*>::iterator it;
	for (it = vp_GameObjects.begin(); it != vp_GameObjects.end(); it++)
	{
		(*it)->update();
	}
}

void Game::battle()
{
	int playersX, playersY, playersHP; // Declare integer variables for battling

	vector<GameObject*>::iterator it;
	playersX = vp_GameObjects.front()->getX();//Front() returns the first element in the vector
	playersY = vp_GameObjects.front()->getY();
	playersHP = vp_GameObjects.front()->accessHealth();

	for (it = vp_GameObjects.begin(); it != vp_GameObjects.end(); it++) // Iterate through gameObjs
	{ // Check to see if an enemy and player are on the same tile 
		if ((*it)->getIDType() == 'E' && (playersX == (*it)->getX()) && (playersY == (*it)->getY()))
		{
			if(playersHP >= (*it)->accessHealth()) // Check player hp vs enemy
			{
				cout << "---You've vanquished a foe!---" << endl;
				(*it)->mutateHealth(); // Set health to zero - Kill enemy
			}
			// An attempt at having an end for when the player kills all the enemies - Couldn't get it working
			/*else if(find(vp_GameObjects.begin(), vp_GameObjects.end(), 'P') != vp_GameObjects.end())
			{
				cout << "Congratulations, you've defeated all your enemies!" << endl;
				m_IsRunning = false;
			}*/
			else
			{
				cout << "---YOU DIED!---" << endl;
				vp_GameObjects.front()->mutateHealth(); // Set the players health to zero
				m_IsRunning = false; // End game loop
			}
		}
	}
}

void Game::info()
{
	// Cycle through the vector of GameObjects ( enemy and player objects) and call the info function for each object
	vector<GameObject*>::iterator it;
	for (it = vp_GameObjects.begin(); it != vp_GameObjects.end(); it++)
	{
		(*it)->info();
	}
}

void Game::clean()
{
	// Remove any objects from the list whose health is 0 using the isAlive function
	vector<GameObject*>::iterator it;
	for (it = vp_GameObjects.begin(); it != vp_GameObjects.end();)
	{
		if ((!(*it)->isAlive()))
		{
			delete *it;
			it = vp_GameObjects.erase(it);
		}
		else
		{
			++it;
		}
	}
}

bool Game::checkRunning()
{
	// Check if the game is running
	return m_IsRunning;
}

void Game::spawnEnemies()
{
	// Declare variables for enemies
	int health = 1;
	int speed = 1;
	int x = 1;
	int y = 1;

	for (int i = 0; i < 3; i++)
	{
		Enemy* pEnemy = 0; // Create an enemy object of type pointer
		pEnemy = new Enemy(); // Places the pEnemy on the heap

		health = rand() % 160; // Gets a pseudo random value between 1-160
		speed = 1 + rand() % 4;//Plus one to stop speed being zero
		x = rand() % (maxPerimeter + i);// i used to ensure unique set of coordinates
		y = rand() % (maxPerimeter + i);

		//C++11 - Concatenate ID and i to make a unique name for each enemy
		string result = "Enemy" + to_string(i+1);
		//string result = "Enemy" + boost::lexical_cast<std::string>(i + 1); Another attempt at concatenation
		pEnemy->spawn(result, health, speed, x, y);
		vp_GameObjects.push_back(pEnemy); // Pushes enemy to the vector
	}
}

void Game::spawnPlayer()
{
	int speed = 1;
	int x = 1;
	int y = 1;

	speed = 1 + rand() % 4;
	x = rand() % (maxPerimeter + 1);//If minPerimeter - always 0
	y = rand() % (maxPerimeter + 1);

	Player* pPlayer;
	pPlayer = new Player();

	pPlayer->spawn("Player", 160, speed, x, y);

	vp_GameObjects.push_back(pPlayer);
}