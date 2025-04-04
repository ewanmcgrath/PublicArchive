#include "GameObject.h"

GameObject::GameObject()
{
	//cout << "Constructor called for a GameObject" << endl;
}

GameObject::~GameObject()
{
	//cout << "Destructor called for a GameObject" << endl;
}

void GameObject::spawn(string typeID, int health, int speed, int x, int y)
{
	m_typeID = typeID;
	m_health = health;
	m_speed = speed;
	m_x = x;
	m_y = y;
}

void GameObject::draw() const
{
	cout << m_typeID << " Coordinates: " << m_x << "," << m_y << endl;
}

void GameObject::info() const
{
	cout << m_typeID << " Health:" << m_health << " Speed:" << m_speed << " Cords x,y: " << m_x << "," << m_y << endl;
}

bool GameObject::isAlive() const
{
	bool alive = true;

	if (m_health <= 0)
	{
		alive = false;
	}
	
	return alive;
}

int GameObject::accessHealth() const
{return m_health;}

void GameObject::mutateHealth()
{m_health = 0;}

int GameObject::getX()
{return m_x;}

int GameObject::getY()
{return m_y;}

char GameObject::getIDType()
{
	char firstChar = m_typeID.at(0);
	return firstChar;
}

