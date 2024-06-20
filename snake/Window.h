#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Okno
{
public:
	sf::RenderWindow window;
	sf::RectangleShape field;
	sf::RectangleShape border;
	float d_coord = 50;
	Okno()
	{
		window.create(sf::VideoMode(width, height), name);
		field.setSize(sf::Vector2f(width - d_coord, height - d_coord));
		field.setPosition(d_coord / 2, d_coord / 2);
		field.setFillColor(sf::Color::Black);
		field.setOutlineThickness(10);
		field.setOutlineColor(sf::Color::White);
		border.setSize(sf::Vector2f(width - d_coord, height - d_coord));
		border.setPosition(d_coord / 2, d_coord / 2);
	}
	~Okno()
	{

	}
protected:
	float width = 1200;
	float height = 600;
private:
	std::string name = "snake";
};
