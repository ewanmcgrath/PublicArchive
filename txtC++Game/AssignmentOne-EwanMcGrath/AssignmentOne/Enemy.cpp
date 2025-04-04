#include "Enemy.h"

Enemy::Enemy()
{}

void Enemy::update()
{
	m_directionToWalk = static_cast<Walk>(rand() % directions);

	if (m_directionToWalk == NORTH)
	{
		if ((m_y + m_speed) > maxPerimeter)// If speed and direction are greater than perimeter, change direction.
		{
			m_y = maxPerimeter;
			m_directionToWalk = SOUTH;
		}
		else
		{
			m_y += m_speed;// Move the Enemy with regards to speed
		}
	}
	if (m_directionToWalk == EAST)
	{
		if ((m_x + m_speed) > maxPerimeter)
		{
			m_x = maxPerimeter;
			m_directionToWalk = WEST;
		}
		else
		{
			m_x += m_speed;
		}
	}
	if (m_directionToWalk == SOUTH)
	{
		if ((m_y - m_speed) < minPerimeter)
		{
			m_y = minPerimeter;
			m_directionToWalk = NORTH;
		}
		else
		{
			m_y -= m_speed;
		}
	}
	if (m_directionToWalk == WEST)
	{
		if ((m_x - m_speed) < maxPerimeter)
		{
			m_x = minPerimeter;
			m_directionToWalk = EAST;
		}
		else
		{
			m_x -= m_speed;
		}
	}
	
	const int deductedHealth = m_speed * 3; // Deduct from health based on speed

	m_health -= deductedHealth;
}
