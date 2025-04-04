#ifndef MAP_H
#define MAP_H

#include <iostream>

using namespace std;

class Map
{
public:
	Map();
	~Map();

	void initialiseMap();
	void showMap();
	//void updateMap();

private:
	char map[10][10];
};

#endif // !MAP_H
