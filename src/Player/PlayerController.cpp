//
// Created by Antoine on 2025-12-05.
//

#include "PlayerController.h"

#include "../Actions/AttackAction.h"
#include "../Actions/LootAction.h"
#include "../Player//PlayerCharacter.h"
#include "../Actions/MoveAction.h"
#include "../UI/PlayerUI/ActionContextMenuUI.h"

void PlayerController::HandleEvent(const sf::Event &event, sf::FloatRect playingBounds, sf::RenderWindow *window) {
    if (const auto *mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        sf::Vector2i mousePos = mouseButtonPressed->position;
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        if (mouseButtonPressed->button == sf::Mouse::Button::Right && bShowContextMenu)
            CloseContextMenu();

        if (!playingBounds.contains(worldPos))
            return;

        if (bActionPerformed) {
            bActionPerformed = false;
            return;
        }

        if (mouseButtonPressed->button == sf::Mouse::Button::Left && !bShowContextMenu) {
            cachedExecutableAction.clear();
            lastClickedPosition = worldPos;
            cachedExecutableAction.push_back(std::make_unique<MoveAction>(owner, worldPos));
            bShowContextMenu = true;
            contextMenuPosition = worldPos;

            //Lootable objects check
            for (const auto &gameObject: gameMap->GetGameObjects()) {
                if (gameObject->GetCollisionBounds().contains(worldPos) && gameObject->IsLootable()) {
                    cachedExecutableAction.push_back(std::make_unique<LootAction>(owner, gameObject));
                }
            }

            //Enemy check
            for (const auto &enemy: gameMap->GetEnemies()) {
                if (!enemy)
                    continue;

                if (enemy->GetCollisionBounds().contains(worldPos)) {
                    cachedExecutableAction.push_back(std::make_unique<AttackAction>(owner, enemy));
                    return;
                }
            }
        }
    }

}

void PlayerController::Update(sf::Time dt) {
    Controller::Update(dt);
}

void PlayerController::PerformAction(std::unique_ptr<Action> action) {
    switch (action->getType()) {
        case ActionType::Move:
            PushAction(std::move(action));
            break;
        case ActionType::Loot:
            if (auto *lootAction = dynamic_cast<LootAction *>(action.get())) {
                if (!lootAction->isInRange()) {
                    std::unique_ptr<MoveAction> moveAction = static_cast<LootAction *>(action.get())->
                            CallMoveActionFirst();
                    PushAction(std::move(moveAction));
                    PushAction(std::move(action));
                } else {
                    PushAction(std::move(action));
                }
            }
            break;
        case ActionType::Attack:
            if (auto *attackAction = dynamic_cast<AttackAction*>(action.get())) {
                if (!attackAction->isInRange()) {
                    std::unique_ptr<MoveAction> moveAction = static_cast<AttackAction*>(action.get())->
                            CallMoveActionFirst();
                    PushAction(std::move(moveAction));
                    PushAction(std::move(action));
                }else {
                    PushAction(std::move(action));
                }
            }
            break;
        case ActionType::Wait:
            PushAction(std::move(action));
            break;
        default:
            PushAction(std::move(action));
            break;
    }

    CloseContextMenu();
    bActionPerformed = true;
    cachedExecutableAction.clear();
}
