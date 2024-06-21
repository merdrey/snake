#pragma once
#include <SFML/Graphics.hpp>

static const int width = 1200;
static const int height = 600;

class Window
{
public:
	sf::RenderWindow window;
	Window()
	{
		window.create(sf::VideoMode(width, height), name);
	}
	~Window()
	{

	}
private:
	std::string name = "snake";
};
