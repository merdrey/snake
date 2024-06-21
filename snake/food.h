#pragma once
#include "Window.h"

class Food
{
public:
	sf::CircleShape foodShape;
	Food()
	{
		foodShape.setRadius(rad);
		foodShape.setFillColor(sf::Color::Red);
		foodShape.setOrigin(rad, rad);
	}
	~Food()
	{

	}
	void spawn(sf::RectangleShape field)
	{
		int x = RandX(), y = RandY();
		sf::FloatRect fieldBorder = field.getGlobalBounds();
		while (true)
		{
			if ((fieldBorder.contains(x + rad, y + rad)) && (fieldBorder.contains(x + rad, y - rad))
				&& (fieldBorder.contains(x - rad, y + rad)) && (fieldBorder.contains(x - rad, y - rad))
				&& (x % 10 == 0) && (y % 10 == 0))
			{
				foodShape.setPosition(x, y);
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
		return 0 + rand() % (width - 0);
	}
	int RandY()
	{
		return 0 + rand() % (height - 0);
	}
};
