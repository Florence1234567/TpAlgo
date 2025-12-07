//
// Created by Antoine on 2025-12-05.
//

#include "MoveAction.h"

MoveAction::MoveAction(Character* character, const sf::Vector2f& destination, const std::vector<sf::FloatRect>& colliders)
    : Action(character, "Move"), destination(destination), colliders(colliders)
{
}

void MoveAction::Execute() {
    static_cast<Character*>(owner)->setDestination(destination.x, destination.y);
}

bool MoveAction::Update(sf::Time dt) {
    Character* character = static_cast<Character*>(owner);

    sf::FloatRect futureBounds = character->GetCollisionBounds();

    for (const auto& rect : colliders)
        if (futureBounds.findIntersection(rect)) {
            character->clearDestination();
            bCompleted = true;
            return false;
        }

    bCompleted = !owner->hasDestination();
    return !Finished();
}