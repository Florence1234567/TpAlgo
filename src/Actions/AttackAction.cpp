//
// Created by Antoine on 2025-12-06.
//

#include "AttackAction.h"

#include "../Player/PlayerCharacter.h"

void AttackAction::Execute() {
}

bool AttackAction::Update(sf::Time dt) {
    if (owner->getHealth() <= 0 || enemy->getHealth() <= 0)
        bCompleted = true;

    owner->Attack(enemy);
    enemy->Attack(owner);


    return !Finished();
}

std::unique_ptr<Action> AttackAction::Clone() const {
    return std::make_unique<AttackAction>(*this);
}

bool AttackAction::isInRange() const {
    const sf::Vector2f a = owner->GetPosition();
    const sf::Vector2f b = enemy->GetPosition();
    const float dx = a.x - b.x;
    const float dy = a.y - b.y;
    const float distance = std::sqrt(dx * dx + dy * dy);

    return distance < range;
}

std::unique_ptr<MoveAction> AttackAction::CallMoveActionFirst() {
    return std::make_unique<MoveAction>(owner, enemy->GetPosition());
}