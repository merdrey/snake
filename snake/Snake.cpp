#include "Snake.h"


inline int direction()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //move up
	{
		return 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // move down
	{
		return 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // move left
	{
		return 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // move rigth
	{
		return 4;
	}
	else // dont change direction
	{
		return 0;
	}
}


inline bool notFree(sf::RectangleShape head, sf::RectangleShape tail, int dir)
{
	float dx = head.getPosition().x - tail.getPosition().x, dy = head.getPosition().y - tail.getPosition().y;
	switch (dir)
	{
	case 1: // head is lower
	{
		if (dx == 0 && dy > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	}
	case 2: // head is higher
	{
		if (dx == 0 && dy < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	}
	case 3: // head is on the right
	{
		if (dx > 0 && dy == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	}
	case 4: // head is on the left
	{
		if (dx < 0 && dy == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	}
	}
}

inline int dir_changer(int dir)
{
	switch (dir)
	{
	case 1:
	{
		return 3;
		break;
	}
	case 2:
	{
		return 4;
		break;
	}
	case 3:
	{
		return 2;
		break;
	}
	case 4:
	{
		return 1;
		break;
	}
	}
}