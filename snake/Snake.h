#pragma once
#include "food.h"

class Player
{
public:
	sf::RectangleShape head;
	float vx = 0, vy = 0;
	Player()
	{
		x = y = 0;
		dir = 0;
		head.setSize(sf::Vector2f(size, size));
		head.setFillColor(sf::Color::Green);
		head.setOrigin(size / 2, size / 2);
	}
	~Player()
	{

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
		switch (dir)
		{
		case 1: // up
		{
			vx = 0;
			vy = -speed;
			x = head.getPosition().x + vx;
			y = head.getPosition().y + vy;
			head.setPosition(x, y);
			break;
		}
		case 2: // down
		{
			vx = 0;
			vy = speed;
			x = head.getPosition().x + vx;
			y = head.getPosition().y + vy;
			head.setPosition(x, y);
			break;
		}
		case 3: // left
		{
			vx = -speed;
			vy = 0;
			x = head.getPosition().x + vx;
			y = head.getPosition().y + vy;
			head.setPosition(x, y);
			break;
		}
		case 4: // right
		{
			vx = speed;
			vy = 0;
			x = head.getPosition().x + vx;
			y = head.getPosition().y + vy;
			head.setPosition(x, y);
			break;
		}
		}
	}
	bool collision(sf::CircleShape shape)
	{
		sf::FloatRect bordshape = shape.getGlobalBounds();
		sf::FloatRect bordhead = head.getGlobalBounds();
		if (bordhead.intersects(bordshape))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool inBorder(sf::RectangleShape shape)
	{
		sf::FloatRect bord = shape.getGlobalBounds();
		sf::FloatRect bordhead = head.getGlobalBounds();
		if (bordhead.intersects(bord))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
protected:
	float size = 10;
	float speed = 10;
private:
	int dir = 0;
	float x;
	float y;
};

class Body : public Player
{
public:
	sf::RectangleShape body;
	Body()
	{
		x = y = 0;
		dir = 0;
		body.setSize(sf::Vector2f(size, size));
		body.setFillColor(head.getFillColor());
		body.setOrigin(size / 2, size / 2);
	}
	~Body()
	{

	}

	void spawn(int dir, sf::RectangleShape shape)
	{
		switch (dir)
		{
		case 1: // up
		{
			vx = 0;
			vy = speed;
			x = shape.getPosition().x + vx;
			y = shape.getPosition().y + vy;
			this->body.setPosition(x, y);
			break;
		}
		case 2: // down
		{
			vx = 0;
			vy = -speed;
			x = shape.getPosition().x + vx;
			y = shape.getPosition().y + vy;
			this->body.setPosition(x, y);
			break;
		}
		case 3: // left
		{
			vx = speed;
			vy = 0;
			x = shape.getPosition().x + vx;
			y = shape.getPosition().y + vy;
			this->body.setPosition(x, y);
			break;
		}
		case 4: // right
		{
			vx = -speed;
			vy = 0;
			x = shape.getPosition().x + vx;
			y = shape.getPosition().y + vy;
			this->body.setPosition(x, y);
			break;
		}
		}
	}
	void move(int dir)
	{
		switch (dir)
		{
		case 1: // up
		{
			vx = 0;
			vy = -speed;
			x += vx;
			y += vy;
			this->body.setPosition(x, y);
			break;
		}
		case 2: // down
		{
			vx = 0;
			vy = speed;
			x += vx;
			y += vy;
			this->body.setPosition(x, y);
			break;
		}
		case 3: // left
		{
			vx = -speed;
			vy = 0;
			x += vx;
			y += vy;
			this->body.setPosition(x, y);
			break;
		}
		case 4: // right
		{
			vx = speed;
			vy = 0;
			x += vx;
			y += vy;
			this->body.setPosition(x, y);
			break;
		}
		}
	}
	Body* pushback(Body* nowel, int count)
	{
		Body* temp = new Body[count];
		for (int i = 0; i < count - 1; i++)
		{
			temp[i] = nowel[i];
		}
		return temp;
	}
private:
	int dir = 0;
	float x;
	float y;
};