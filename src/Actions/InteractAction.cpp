//
// Created by Antoine on 2025-12-12.
//

#include "InteractAction.h"

void InteractAction::Execute() {
    NPC->StartDialog();
}

bool InteractAction::Update(sf::Time dt) {
    bCompleted = NPC->DialogFinished();
    return !Finished();
}

std::unique_ptr<Action> InteractAction::Clone() const {
    return std::make_unique<InteractAction>(*this);
}

bool InteractAction::isInRange() const {
    const sf::Vector2f a = owner->GetPosition();
    const sf::Vector2f b = { NPC->GetPosition().x + NPC->GetCollisionBounds().size.x, NPC->GetPosition().y };
    const float dx = a.x - b.x;
    const float dy = a.y - b.y;
    const float distance = std::sqrt(dx * dx + dy * dy);

    return distance < range;
}

std::unique_ptr<MoveAction> InteractAction::CallMoveActionFirst() {
    const sf::Vector2f targetPosition = { NPC->GetPosition().x + NPC->GetCollisionBounds().size.x, NPC->GetPosition().y };
    return std::make_unique<MoveAction>(owner, targetPosition);
}