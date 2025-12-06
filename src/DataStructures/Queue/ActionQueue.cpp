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

void ActionQueue::enqueue(std::unique_ptr<Action> action) {
    if (!action) throw std::invalid_argument("The action is null.");

    list.addBack(std::move(action));
}

void ActionQueue::dequeue() {
    if (empty()) throw std::out_of_range("The queue is empty.");

    list.removeFront();
}

std::unique_ptr<Action> ActionQueue::getFirstAction() {
    if (empty()) throw std::out_of_range("The queue is empty.");

    std::unique_ptr<Action> elem = std::move(*list.getHeadElem());
    return elem;
}
