#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();

	virtual void update();
};
#endif // !PLAYER_H