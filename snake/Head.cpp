#include "Snake.h"

class Head : public SnakePart {
public: 
	Head() {
		
	}
	~Head() {

	}
	bool collision(sf::CircleShape foodShape)
	{
		sf::FloatRect foodBord = foodShape.getGlobalBounds();
		sf::FloatRect headBord = shape.getGlobalBounds();
		if (headBord.intersects(foodBord))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};