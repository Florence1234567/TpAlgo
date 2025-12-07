//
// Created by Antoine on 2025-12-05.

#pragma once
#include "../../Actions/Action.h"
#include "../LinkedLists/DLinkedList.hpp"

/**
 * Queue d'action (Action) basé sur l'implémentation de la doubly linked list DLinkedList.
 */
class ActionQueue {
public:
    ActionQueue();
    int getSize() const;
    bool empty() const;
    const Action& front() const;
    void enqueue(std::shared_ptr<Action> action);
    void dequeue();
    std::shared_ptr<Action> getFirstAction();
    std::vector<std::string> GetActionNames() const;

private:
    DLinkedList<std::shared_ptr<Action>> list;
};