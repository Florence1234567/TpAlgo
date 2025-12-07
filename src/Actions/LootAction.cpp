//
// Created by Antoine on 2025-12-07.
//

#include "LootAction.h"

void LootAction::Execute() {
    delete object;
}

bool LootAction::Update(sf::Time dt) {
    bCompleted = !object;
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

    std::cout << "Position joueur: " << a.x << ", " << a.y << std::endl;
    std::cout << "Position objet: " << b.x << ", " << b.y << std::endl;
    std::cout << "Distance: " << distance << std::endl;

    return distance < range;
}

std::unique_ptr<MoveAction> LootAction::CallMoveActionFirst() {
    return std::make_unique<MoveAction>(owner, object->GetPosition());
}

