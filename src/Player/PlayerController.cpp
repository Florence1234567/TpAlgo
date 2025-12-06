//
// Created by Antoine on 2025-12-05.
//

#include "PlayerController.h"
#include "../Player//PlayerCharacter.h"
#include "../Actions/MoveAction.h"
#include "../Actions/WaitAction.h"

void PlayerController::HandleEvent(const sf::Event &event, sf::FloatRect playingBounds, sf::RenderWindow *window) {
    if (const auto* mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button != sf::Mouse::Button::Left) return;
        sf::Vector2i mousePos = mouseButtonPressed->position;
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        if (playingBounds.contains(worldPos)) {
            auto moveAction = std::make_unique<MoveAction>(owner, worldPos);
            PushAction(std::move(moveAction));
        }
    }
}

void PlayerController::Update(sf::Time dt) {
    Controller::Update(dt);
}
