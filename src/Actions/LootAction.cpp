//
// Created by Antoine on 2025-12-07.
//

#include "LootAction.h"

#include "../Objects/Player/PlayerCharacter.h"

void LootAction::Execute() {
    std::cout << "Looting" << std::endl;
}

bool LootAction::Update(sf::Time dt) {
    lootTime -= dt.asSeconds();
    bCompleted = lootTime <= 0.f;

    if (bCompleted) {
        static_cast<PlayerCharacter*>(owner)->Loot(object);
    }

    return !Finished();
}

std::unique_ptr<Action> LootAction::Clone() const {
    return std::make_unique<LootAction>(*this);
}

bool LootAction::isInRange() const {
    const sf::Vector2f a = owner->GetPosition();
    const sf::Vector2f b = object->GetPosition();
    const float dx = a.x - b.x;
    const float dy = a.y - b.y;
    const float distance = std::sqrt(dx * dx + dy * dy);

    return distance < range;
}

std::unique_ptr<MoveAction> LootAction::CallMoveActionFirst() {
    return std::make_unique<MoveAction>(owner, object->GetPosition());
}

