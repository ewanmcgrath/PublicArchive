#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"

class Enemy: public GameObject
{
public:
	Enemy();

	virtual void update();
};
#endif // !ENEMY_H
