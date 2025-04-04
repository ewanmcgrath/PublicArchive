#include "Player.h"

Player::Player()
{}

void Player::update()
{
	string direction = "";

	cout << "---Enter a cardinal direction you'd like to move in---" << endl;
	cin >> direction;

	for (int i = 0; i<direction.length(); i++) //Changes the users input to uppercase for checking
	{ direction[i] = toupper(direction[i]); }

	if ((direction == "NORTH")||(direction == "N")) // Checks user input
	{
		if ((m_y + m_speed) > maxPerimeter) // If speed and direction are greater than perimeter, change direction.
		{
			m_y = maxPerimeter;
			m_directionToWalk = SOUTH;
		}
		else
		{
			m_y += m_speed; // Move the player with regards to speed
			cout << "---You've travelled North---" << "\n";
		}
	}
	else if ((direction == "EAST") || (direction == "E"))
	{
		if ((m_x + m_speed) > maxPerimeter)
		{
			m_x = maxPerimeter;
			m_directionToWalk = WEST;
		}
		else
		{
			m_x += m_speed;
			cout << "---You've travelled East---" << "\n";
		}
	}
	else if ((direction == "SOUTH") || (direction == "S"))
	{
		if ((m_y - m_speed) < minPerimeter)
		{
			m_y = minPerimeter;
			m_directionToWalk = NORTH;
		}
		else
		{
			m_y -= m_speed;
			cout << "---You've travelled South---" << "\n";
		}
	}
	else if ((direction == "WEST") || (direction == "W"))
	{
		if ((m_x - m_speed) < maxPerimeter)
		{
			m_x = minPerimeter;
			m_directionToWalk = EAST;
		}
		else
		{
			m_x -= m_speed;
			cout << "---You've travelled West---" << "\n";
		}
	}

	const int deductedHealth = m_speed * 2; // Deduct from health based on speed

	m_health -= deductedHealth;
}
