#pragma once
#include "Window.h"

class SnakePart {
public:
	sf::RectangleShape shape;
	SnakePart() {
		x = y = 0;
		vx = vy = 0;
		dir = 0;
		size = speed = 10;
		shape.setSize(sf::Vector2f(size, size));
		shape.setFillColor(sf::Color::Green);
		shape.setOrigin(size / 2, size / 2);
	}
	~SnakePart() {

	}
	void setDirection(int a)
	{
		this->dir = a;
	}
	int getDirection()
	{
		return dir;
	}
	void move(int dir)
	{
		switch (dir) {
			case 1: // up
			{
				vx = 0;
				vy = -speed;
				break;
			}
			case 2: // down
			{
				vx = 0;
				vy = speed;
				break;
			}
			case 3: // left
			{
				vx = -speed;
				vy = 0;
				break;
			}
			case 4: // right
			{
				vx = speed;
				vy = 0;
				break;
			}
			default: {
				vx = 0;
				vy = 0;
				break;
			}
		}
		x = shape.getPosition().x + vx;
		y = shape.getPosition().y + vy;
		shape.setPosition(x, y);
	}
	bool inBorder(sf::RectangleShape border)
	{
		sf::FloatRect bord = border.getGlobalBounds();
		sf::FloatRect shapeBord = shape.getGlobalBounds();
		if (shapeBord.intersects(bord))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
protected:
	int vx, vy, size, speed, dir, x, y;
};