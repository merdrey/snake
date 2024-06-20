#pragma once
#include "Window.h"
#include <cstdlib>

class Obj
{
public:
	sf::CircleShape food;
	Obj()
	{
		food.setRadius(rad);
		food.setFillColor(sf::Color::Red);
		food.setOrigin(rad, rad);
	}
	~Obj()
	{

	}
	void spawn(sf::RectangleShape field)
	{
		int x = RandX(), y = RandY();
		sf::FloatRect fieldborder = field.getGlobalBounds();
		while (true)
		{
			if ((fieldborder.contains(x + rad, y + rad)) && (fieldborder.contains(x + rad, y - rad))
				&& (fieldborder.contains(x - rad, y + rad)) && (fieldborder.contains(x - rad, y - rad))
				&& (x % 10 == 0) && (y % 10 == 0))
			{
				food.setPosition(x, y);
				x = 0;
				y = 0;
				break;
			}
			else
			{
				x = RandX();
				y = RandY();
			}
		}
	}
private:
	float rad = 5;
	int RandX()
	{
		return 0 + rand() % (1200 - 0);
	}
	int RandY()
	{
		return 0 + rand() % (600 - 0);
	}
};
