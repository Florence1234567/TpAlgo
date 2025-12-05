#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include "GameMap.h"

int main() {
    sf::Vector2u windowSize(1920, 1080);
    sf::RenderWindow window(sf::VideoMode(windowSize), "Le meilleur jeu");
    window.setFramerateLimit(60);

    try
    {
        GameMap GameMap(windowSize.x, windowSize.y);

        while (window.isOpen())
        {
            for (auto event = window.pollEvent(); event; event = window.pollEvent())
                if (event->is<sf::Event::Closed>())
                    window.close();

            window.clear(sf::Color::Black);

            GameMap.Display(window);

            window.display();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}