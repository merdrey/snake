#pragma once
#include "Window.h"

class Screen {
public:
	Screen() {
		font.loadFromFile("C:/Users/mergo/source/repos/snake/consola.ttf");
	}
protected:
	sf::Font font;
};