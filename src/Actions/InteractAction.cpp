//
// Created by Antoine on 2025-12-12.
//

#include "InteractAction.h"

void InteractAction::Execute() {}

bool InteractAction::Update(sf::Time dt) {
    bCompleted = true;
    return !Finished();
}

std::unique_ptr<Action> InteractAction::Clone() const {
    return std::make_unique<InteractAction>(*this);
}

bool InteractAction::isInRange() const {
    const sf::Vector2f a = owner->GetPosition();
    const sf::Vector2f b = NPC->GetPosition();
    const float dx = a.x - b.x;
    const float dy = a.y - b.y;
    const float distance = std::sqrt(dx * dx + dy * dy);

    return distance < range;
}

std::unique_ptr<MoveAction> InteractAction::CallMoveActionFirst() {
    return std::make_unique<MoveAction>(owner, NPC->GetPosition());
}