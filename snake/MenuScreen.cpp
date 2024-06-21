#include "Screen.h"

class MenuScreen : public Screen {
public:
	sf::RectangleShape menuButton;
	sf::RectangleShape exitButton;
	sf::Text title;
	sf::Text menuText;
	sf::Text exitText;
	MenuScreen() {
		title.setString("Snake The Game");
		title.setPosition(480, 100);
		title.setFont(font);
		title.setFillColor(sf::Color::White);
		menuButton.setFillColor(sf::Color::Color(125, 125, 125));
		menuButton.setSize(sf::Vector2f(180, 50));
		menuButton.setPosition(510, 200);
		exitButton.setFillColor(sf::Color::Color(125, 125, 125));
		exitButton.setSize(sf::Vector2f(180, 50));
		exitButton.setPosition(510, 275);
		menuText.setString("Start Game");
		menuText.setPosition(514, 205);
		menuText.setFont(font);
		menuText.setFillColor(sf::Color::White);
		exitText.setString("Exit Game");
		exitText.setPosition(523, 280);
		exitText.setFont(font);
		exitText.setFillColor(sf::Color::White);
	}
	~MenuScreen() {
		
	}
};