#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#define minPerimeter 0 // Used for boundary detection
#define maxPerimeter 9 // Used for boundary detection
#define directions 4 // Used for getting enemy directions
enum Walk{ NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3};//Used for movement

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class GameObject
{
public:
	GameObject();
	~GameObject();

	void spawn(string typeID, int health, int speed, int x, int y); // create an object
	void draw() const; // print to the screen the typeID and its x and y coords
	void info() const; // print all info relating to the object
	bool isAlive() const; // return true if its health is greater than 0
	int accessHealth() const;//Used in Game class
	void mutateHealth();//Used in Game class
	int getX();//Used in battle function to check collision
	int getY();//Used in battle function to check collision
	char getIDType();//Used for Game class to return first letter of m_typeID
	virtual void update() = 0; // Pure virtual function that inherited classes have to use

protected:
	string m_typeID; // Differentiate between objects. Player and enemies
	int m_health; // Max 160
	int m_speed; // value between 1 and 4
	int m_x; // Limit 1-23
	int m_y; // Must be unique at start
	
	Walk m_directionToWalk;// Used to instantiate enum
};
#endif // !GAMEOBJECT_H

