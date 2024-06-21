#include "Screen.h"

class GameScreen : public Screen {
public:
	GameScreen() {
		field.setSize(sf::Vector2f(width - margin, height - margin));
		field.setPosition(margin / 2, margin / 2);
		field.setFillColor(sf::Color::Black);
		field.setOutlineThickness(-5);
		field.setOutlineColor(sf::Color::White);
		border.setSize(sf::Vector2f(width - margin - 10, height - margin - 10));
		border.setPosition(margin / 2 + 5, margin / 2  + 5);
		counter.setFont(font);
		counter.setFillColor(sf::Color::White);
		death.setFont(font);
		death.setFillColor(sf::Color::White);
		death.setPosition(510, 270);
		death.setString("YOU DIED");
	}
	~GameScreen() {
	}
	void setCounter(int count) {
		counter.setString(std::to_string(count));
	}
	sf::Text getDeath() {
		return death;
	}
	sf::Text getCounter() {
		return counter;
	}
	sf::RectangleShape getField() {
		return field;
	}
	sf::RectangleShape getBorder() {
		return border;
	}
private:
	sf::RectangleShape field;
	sf::RectangleShape border;
	sf::Text death;
	sf::Text counter;
	int margin = 100;
};