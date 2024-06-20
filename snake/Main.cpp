#pragma warning(disable : 4996)
#include "food.h"
#include "Snake.h"
#include "Snake.cpp"

int count = 0;


int main()
{
    bool flag = false;
    Okno okno;
    Obj food;
    Player snake;
    snake.head.setPosition(490, 490);
    Body* body = new Body[count];
    sf::Font font;
    font.loadFromFile("C:/Users/mergo/source/repos/snake/consola.ttf");
    sf::Text text;
    sf::Text cntr;
    cntr.setFont(font);
    cntr.setFillColor(sf::Color::White);
    cntr.setScale(0.5, 0.5);
    text.setFont(font);
    text.setColor(sf::Color::White);
    text.setPosition(510, 270);
    text.setString("YOU DIED");
    srand(time(NULL));
    food.spawn(okno.border);
    sf::Time GlobalTime = sf::milliseconds(150);
    sf::Clock clock;
    while (okno.window.isOpen())
    {
        sf::Time t = clock.getElapsedTime();
        sf::Event event;
        while (okno.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                okno.window.close();
        }
        if (snake.getDirection() != direction() && direction() != 0) // смена направления движения змейки
        {
            if (count > 0)
            {
                if (notFree(snake.head, body[0].body, direction()) == false)
                {
                    snake.setDirection(direction());
                }
            }
            else
            {
                snake.setDirection(direction());
            }
        }
        if (snake.collision(food.food)) // рост змейки
        {
            food.spawn(okno.border);
            count++;
            cntr.setString(std::to_string(count));
            body = body->pushback(body, count);
            if (count == 1)
            {
                body[count - 1].setDirection(snake.getDirection());
                body[count - 1].spawn(body[count - 1].getDirection(), snake.head);
            }
            else
            {
                body[count - 1].setDirection(body[count - 2].getDirection());
                body[count - 1].spawn(body[count - 1].getDirection(), body[count - 2].body);
                while (body[count - 1].inBorder(okno.border) == false and body[count - 1].body.getPosition() == body[count - 2].body.getPosition())
                {
                    body[count - 1].setDirection(dir_changer(body[count - 1].getDirection()));
                }
            }
            if (count % 10 == 0)
            {
                GlobalTime -= sf::milliseconds(10);
            }
        }
        if (t.asMilliseconds() > sf::Int32(GlobalTime.asMilliseconds()))
        {
            if (snake.inBorder(okno.border) or flag == true)
            {
                okno.window.clear();
                okno.window.draw(text);
                okno.window.display();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    okno.window.close();
                }
            }
            else
            {
                okno.window.clear();
                okno.window.draw(okno.field);
                okno.window.draw(cntr);
                snake.move(snake.getDirection());
                okno.window.draw(snake.head);
                for(int i = 0; i < count; i++) // движение
                {
                    body[i].move(body[i].getDirection());
                    okno.window.draw(body[i].body);
                    if (snake.inBorder(body[i].body) == 0)
                    {
                        flag = true;
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
                        body[i].setDirection(snake.getDirection());
                    }
                }
                okno.window.draw(food.food);
                okno.window.display();
            }
            clock.restart();
        }
    }
    return 0;
}