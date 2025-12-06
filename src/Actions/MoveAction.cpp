//
// Created by Antoine on 2025-12-05.
//

#include "MoveAction.h"

void MoveAction::Execute() {
    static_cast<Character*>(owner)->setDestination(destination.x, destination.y);
}

bool MoveAction::Update(sf::Time dt) {
    bCompleted = owner->hasDestination();
    return !Finished();
}