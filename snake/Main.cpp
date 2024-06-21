#pragma warning(disable : 4996)
#include "Game.cpp"
#include "MenuScreen.cpp"


int main()
{
    Window okno;
    GameScreen screenGame;
    MenuScreen menu;
    sf::Mouse mouse;
    mouse.setPosition(sf::Vector2i(20, 20), okno.window);
    bool isGameStarted = false;
    srand(time(NULL));
    Game game = Game(screenGame);
    while (okno.window.isOpen())
    {
        sf::Event event;
        while (okno.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                okno.window.close();
            }
        }
        if (menu.menuButton.getGlobalBounds().contains(sf::Vector2f(mouse.getPosition(okno.window)))) {
            menu.menuButton.setFillColor(sf::Color::White);
            menu.menuText.setFillColor(sf::Color::Black);
            if (mouse.isButtonPressed(mouse.Left)) {
                isGameStarted = true;
            }
        }
        else {
            menu.menuButton.setFillColor(sf::Color::Color(125, 125, 125));
            menu.menuText.setFillColor(sf::Color::White);
        }
        if (menu.exitButton.getGlobalBounds().contains(sf::Vector2f(mouse.getPosition(okno.window)))) {
            menu.exitButton.setFillColor(sf::Color::White);
            menu.exitText.setFillColor(sf::Color::Black);
            if (mouse.isButtonPressed(mouse.Left)) {
                okno.window.close();
            }
        }
        else {
            menu.exitButton.setFillColor(sf::Color::Color(125, 125, 125));
            menu.exitText.setFillColor(sf::Color::White);
        }
        okno.window.clear();
        if (isGameStarted == false) {
            okno.window.draw(menu.title);
            okno.window.draw(menu.menuButton);
            okno.window.draw(menu.exitButton);
            okno.window.draw(menu.menuText);
            okno.window.draw(menu.exitText);
        }
        else {
            if (game.getHead().inBorder(screenGame.getBorder()) || game.getBiteSelf()) {
                okno.window.draw(screenGame.getDeath());
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    okno.window.close();
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    game.restart(screenGame, width / 2, height / 2);
                    screenGame.setCounter(0);
                }
            }
            else {
                game.loop(screenGame);
                screenGame.setCounter(game.getCount());
                okno.window.clear();
                okno.window.draw(screenGame.getField());
                okno.window.draw(screenGame.getCounter());
                okno.window.draw(game.getHead().shape);
                for (int i = 0; i < game.getCount(); i++)
                {
                    okno.window.draw(game.getBody()[i].shape);
                }
                okno.window.draw(game.getFood().foodShape);
            }
        }
        okno.window.display();
    }
    return 0;
}