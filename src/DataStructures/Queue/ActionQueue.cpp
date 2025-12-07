//
// Created by Antoine on 2025-12-05.
//

#include "ActionQueue.h"
#include "../LinkedLIsts/DLinkedList.hpp"

ActionQueue::ActionQueue() : list() {
}

int ActionQueue::getSize() const {
    return list.getSize();
}

bool ActionQueue::empty() const {
    return list.empty();
}

const Action &ActionQueue::front() const {
    if (empty()) throw std::out_of_range("The queue is empty.");

    return *list.front();
}

void ActionQueue::enqueue(std::shared_ptr<Action> action) {
    if (!action) throw std::invalid_argument("The action is null.");

    list.addBack(std::move(action));
}

void ActionQueue::dequeue() {
    if (empty()) throw std::out_of_range("The queue is empty.");

    list.removeFront();
}

std::shared_ptr<Action> ActionQueue::getFirstAction() {
    if (empty()) throw std::out_of_range("The queue is empty.");

    std::shared_ptr<Action> elem = list.getHeadElem();
    return elem;
}

std::vector<std::string> ActionQueue::GetActionNames() const {
    std::vector<std::string> names;

    for (int i = 0; i < list.getSize(); ++i) {
        const auto &action = list.At(i);

        if (action)
            names.push_back(action->getName());
    }

    return names;
}
