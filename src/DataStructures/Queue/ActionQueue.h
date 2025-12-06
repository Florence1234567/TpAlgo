//
// Created by Antoine on 2025-12-05.

#pragma once
#include "../../Actions/Action.h"
#include "../LinkedLIsts/DLinkedList.hpp"

/**
 * Queue d'action (Action) basé sur l'implémentation de la doubly linked list DLinkedList.
 */
class ActionQueue {
public:
    ActionQueue();
    int getSize() const;
    bool empty() const;
    const Action& front() const;
    void enqueue(std::unique_ptr<Action> action);
    void dequeue();
    std::unique_ptr<Action> getFirstAction();
    std::vector<std::string> GetActionNames() const {
        std::vector<std::string> names;

        for (int i = 0; i < list.getSize(); ++i)
        {
            const auto& action = list.At(i);

            if (action)
                names.push_back(action->getName());
        }

        return names;
    }

private:
    DLinkedList<std::unique_ptr<Action>> list;
};