//
// Created by Antoine on 2025-12-05.
//

#include "PlayerController.h"

#include "../Actions/AttackAction.h"
#include "../Player//PlayerCharacter.h"
#include "../Actions/MoveAction.h"
#include "../Actions/WaitAction.h"
#include "../UI/PlayerUI/ActionContextMenuUI.h"

void PlayerController::HandleEvent(const sf::Event &event, sf::FloatRect playingBounds, sf::RenderWindow *window) {
    if (const auto *mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        sf::Vector2i mousePos = mouseButtonPressed->position;
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        if (!playingBounds.contains(worldPos))
            return;

        for (const auto &objBounds: gameMap->GetObjectBounds()) {
            if (objBounds.contains(worldPos)) {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left && !bShowContextMenu) {
                    cachedExecutableAction.clear();
                    lastClickedPosition = worldPos;
                    cachedExecutableAction.push_back(std::make_unique<MoveAction>(owner, worldPos));
                    cachedExecutableAction.push_back(std::make_unique<AttackAction>(owner, worldPos));
                    bShowContextMenu = true;
                    contextMenuPosition = worldPos;
                }
                return;
            }
        }

        if (mouseButtonPressed->button == sf::Mouse::Button::Left && !bShowContextMenu) {
            cachedExecutableAction.clear();
            lastClickedPosition = worldPos;
            cachedExecutableAction.push_back(std::make_unique<MoveAction>(owner, worldPos));
            bShowContextMenu = true;
            contextMenuPosition = worldPos;
        }
    }
}

void PlayerController::Update(sf::Time dt) {
    Controller::Update(dt);
}

void PlayerController::PerformAction(std::unique_ptr<Action> action) {
    PushAction(std::move(action));
    bShowContextMenu = false;
}
