//
// Created by Antoine on 2025-12-05.
//

#include "PlayerController.h"

void PlayerController::HandleEvent(const sf::Event &event, sf::RenderWindow *window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        std::cout << "Position X: " << mousePos.x << "\nPosition Y: " << mousePos.y << std::endl;
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        static_cast<Character*>(owner)->setDestination(worldPos.x, worldPos.y);
    }
}


void PlayerController::Update(sf::Time dt) {

}