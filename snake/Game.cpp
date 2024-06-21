#include "food.h"
#include "Snake.cpp"
#include "GameScreen.cpp"
#include "Head.cpp"
#include "Body.cpp"

class Game {
public:
	Game(GameScreen gameScreen) {
		head.shape.setPosition(width / 2, height / 2);
		body = new Body[count];
		food.spawn(gameScreen.getBorder());
		biteSelf = false;
		globalTime = sf::milliseconds(150);
	}
	~Game() {

	}
	void loop(GameScreen game) {
		timer = clock.getElapsedTime();
		if (head.getDirection() != direction() && direction() != 0) // смена направления движения змейки
		{
			if (count > 0)
			{
				if (notFree(head.shape, body[0].shape, direction()) == false)
				{
					head.setDirection(direction());
				}
			}
			else
			{
				head.setDirection(direction());
			}
		}
		if (head.collision(food.foodShape)) // рост змейки
		{
			food.spawn(game.getBorder());
			count++;
			body = body->pushback(body, count);
			if (count == 1)
			{
				body[0].setDirection(head.getDirection());
				body[0].spawn(body[0].getDirection(), head.shape);
			}
			else
			{
				body[count - 1].setDirection(body[count - 2].getDirection());
				body[count - 1].spawn(body[count - 1].getDirection(), body[count - 2].shape);
				while (body[count - 1].inBorder(game.getBorder()) == false and body[count - 1].shape.getPosition() == body[count - 2].shape.getPosition())
				{
					body[count - 1].setDirection(dir_changer(body[count - 1].getDirection()));
				}
			}
			if (count % 5 == 0)
			{
				globalTime -= sf::milliseconds(5);
			}
		}
		if (timer.asMilliseconds() > sf::Int32(globalTime.asMilliseconds()))
		{
			head.move(head.getDirection());
			for (int i = 0; i < count; i++) // движение
			{
				body[i].move(body[i].getDirection());
				if (head.inBorder(body[i].shape) == 0)
				{
					biteSelf = true;
				}
			}
			for (int i = count - 1; i >= 0; i--) // смена направления 
			{
				if (i > 0)
				{
					body[i].setDirection(body[i - 1].getDirection());
				}
				else
				{
					body[i].setDirection(head.getDirection());
				}
			}
			clock.restart();
		}
	}
	void restart(GameScreen game, int x, int y) {
		count = 0;
		body = new Body[count];
		biteSelf = false;
		head.setDirection(0);
		head.shape.setPosition(x, y);
		food.spawn(game.getBorder());
	}
	Head getHead() {
		return head;
	}
	Body* getBody() {
		return body;
	}
	Food getFood() {
		return food;
	}
	bool getBiteSelf() {
		return biteSelf;
	}
	void setBiteSelf(bool set) {
		biteSelf = set;
	}
	int getCount() {
		return count;
	}
private:
	Head head;
	Body* body;
	Food food;
	sf::Time globalTime;
	sf::Time timer;
	sf::Clock clock;
	int count = 0;
	bool biteSelf;
};