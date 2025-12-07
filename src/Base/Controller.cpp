//
// Created by Antoine on 2025-12-05.
//

#include "Controller.h"

#include "../Actions/WaitAction.h"

void Controller::Update(sf::Time dt) {
    owner->Update(dt);

    if (actions->empty()) PushAction(std::make_unique<WaitAction>(owner));

    if (!currentAction) ExecuteAction();

    if (currentAction) {
        if (!currentAction->Update(dt)) {
            // std::cout << currentAction->getName() << " completed" << std::endl;
            actions->dequeue();
            currentAction = nullptr;
        } else {
            // std::cout << "Executing: " << currentAction->getName() << std::endl;
        }
    }
}

std::vector<std::string>& Controller::GetMovementQueue() const
{
    cachedActionNames = actions->GetActionNames();

    return cachedActionNames;
}

void Controller::PushAction(std::unique_ptr<Action> action) {
    actions->enqueue(std::move(action));
}

void Controller::ExecuteAction() {
    if (!actions || actions->empty()) PushAction(std::make_unique<WaitAction>(owner));

    currentAction = actions->getFirstAction();
    if (currentAction)
        currentAction->Execute();
}
