#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include "GameMap.h"
#include "Character.h"

int main() {
    sf::Vector2u windowSize(800, 600);
    sf::RenderWindow window(sf::VideoMode(windowSize), "Le meilleur jeu");
    window.setFramerateLimit(60);

    try
    {
        GameMap GameMap("Map.cvs");
        Character Character(GameMap.GetWidth() / 2, GameMap.GetHeight() / 2);

        while (window.isOpen())
        {
            for (auto event = window.pollEvent(); event; event = window.pollEvent())
                if (event->is<sf::Event::Closed>())
                    window.close();

            window.clear(sf::Color::Black);

            GameMap.MoveCharacter(Direction::Up);
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