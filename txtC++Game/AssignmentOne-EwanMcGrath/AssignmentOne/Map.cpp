#include "Map.h"

Map::Map()
{}

Map::~Map()
{}

void Map::initialiseMap()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = '-';
		}
	}
}

void Map::showMap()
{
	cout << "   a b c d e f g h i j" << endl;
	cout << "  +-------------------+" << endl;
	for (int i = 0; i < 10; i++) {
		// print the first character as part of the opener.
		cout << " " << i << "|" << map[i][0];
		for (int j = 1; j < 10; j++) {
			// only add spaces for subsequent characters.
			cout << " " << map[i][j];
		}
		cout << "|" << endl;
	}
	cout << "  +-------------------+" << endl;
}

/*void Map::updateMap()
{
}*/
