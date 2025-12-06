//
// Created by Antoine on 2025-12-05.
//

#include "WaitAction.h"

void WaitAction::Execute() {

}

bool WaitAction::Update(sf::Time dt) {
    waitTime -= dt.asSeconds();
    bCompleted = waitTime <= 0.f;
    return !Finished();
}
