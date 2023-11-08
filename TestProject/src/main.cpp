#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main()
{

    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML Base Game");
    window.setFramerateLimit(60);

    Game game(window);

    if(!game.init())
    {
        return 0;
    }

    sf::Clock clock;

    while(window.isOpen())
    {
        sf::Event event;

        sf::Time time = clock.restart();
        float dt = time.asSeconds();

        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                game.keyPressed(event, dt);

            if(event.type == sf::Event::KeyReleased)
                game.keyReleased(event, dt);

            if(event.type == sf::Event::MouseButtonPressed)
                game.mouseClicked(event);

            if(event.type == sf::Event::MouseMoved)
                game.mouseMoved(event);
        }

        game.update(dt);

        window.clear(sf::Color::Black);

        game.render();
        window.display();
    }

    return 0;
}
