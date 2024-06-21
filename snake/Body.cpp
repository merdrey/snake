#include "Snake.h"

class Body : public SnakePart {
public:
	Body() {
		
	}
	~Body() {

	}
	void spawn(int dir, sf::RectangleShape shape) {
		switch (dir) {
			case 1: // up
			{
				vx = 0;
				vy = speed;
				break;
			}
			case 2: // down
			{
				vx = 0;
				vy = -speed;
				break;
			}
			case 3: // left
			{
				vx = speed;
				vy = 0;
				break;
			}
			case 4: // right
			{
				vx = -speed;
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
		this->shape.setPosition(x, y);
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
};