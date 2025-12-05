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
		sf::Clock moveClock;
		float interval = 3;

		GameMap GameMap("Map.cvs");
		Character Character(0, 0);

		while (window.isOpen())
		{
			for (auto event = window.pollEvent(); event; event = window.pollEvent())
				if (event->is<sf::Event::Closed>())
					window.close();

			window.clear(sf::Color::Black);

			if (moveClock.getElapsedTime().asSeconds() >= interval)
			{
				Character.SetDir(Direction::Down);
				Character.Move();
				std::cout << "Character row: " << Character.GetRow()
					<< " col: " << Character.GetCol() << std::endl;
				moveClock.restart();
			}

			GameMap.Display(window, &Character);

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