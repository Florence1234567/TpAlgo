//
// Created by Antoine on 2025-12-06.
//

#include "AttackAction.h"

void AttackAction::Execute() {
    static_cast<Character*>(owner)->setDestination(destination.x, destination.y);
}

bool AttackAction::Update(sf::Time dt) {
    bCompleted = !owner->hasDestination();
    return !Finished();
}
