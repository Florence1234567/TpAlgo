#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include "GameMap.h"
#include "Character.h"

int main() {
    sf::Vector2u windowSize(1920, 1080);
    sf::RenderWindow window(sf::VideoMode(windowSize), "Le meilleur jeu");
    window.setFramerateLimit(120);

    try
    {
        sf::Clock moveClock;
        float interval = 3;

        GameMap GameMap(windowSize.x, windowSize.y);
        Character Player(0, 0);

        while (window.isOpen())
        {
            for (auto event = window.pollEvent(); event; event = window.pollEvent())
                if (event->is<sf::Event::Closed>())
                    window.close();

            window.clear(sf::Color::Black);

            if (moveClock.getElapsedTime().asSeconds() >= interval) {
                Player.SetDir(Direction::Down);
                Player.Move();
                std::cout << "Character row: " << Player.GetRow()
                    << ", col: " << Player.GetCol() << std::endl;
                moveClock.restart();
            }

            GameMap.Display(window, &Player);

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