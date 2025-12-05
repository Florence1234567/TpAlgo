#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
    sf::Window window;
    window.create(sf::VideoMode({800, 600}), "Algo");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        // window.clear();
        // window.draw(shape);
        window.display();
    }

    return 0;
}