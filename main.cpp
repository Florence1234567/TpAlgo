#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
    // Create a window (800x600)
    sf::Window window(sf::VideoMode(800, 600), "SFML Test");

    // Create a circle shape
    sf::CircleShape circle(100.f); // radius 100
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(200.f, 150.f);

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
	return 0;
}