#include "Game.h"

int main()
{
	srand(time(NULL)); // Seed random for unique variables

	const int maxGameLoops = 20; // Max game loops to keep game engaging

	bool m_IsRunning = true;

	//Add intro/story
	cout << "---You're a highly trained mercenary---\n---Your job is to eliminate enemies of the state---\n---Stay vigilant, and stay alive if you want to be payed---\n---Good luck!---" << endl;

	while (m_IsRunning)
	{
		Game* game = new Game();
		int gameLoops = 0;
		game->init();

		//Core loop
		while (game->checkRunning() && gameLoops < maxGameLoops)
		{
			game->draw();
			game->update();
			game->battle();
			game->info();
			game->clean();

			gameLoops++;
		}

		delete game;//Free game object memory
		game = 0;//Delete game objects dangling pointer

		char playAgain;
		cout << "\n---The day has ended, for better or for worse---\n---Would you like to enter the battlefield again? Y/N\n---" << endl;
		cin >> playAgain;
		if (playAgain == 'Y')
		{
			m_IsRunning = true;
		}
		else
		{
			cout << "\n---Thank you kindly for playing. Come back anytime!--\n---We value your services.---" << endl;
			system("PAUSE");
			return 0;
		}
	}
}