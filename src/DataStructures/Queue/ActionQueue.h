//
// Created by Antoine on 2025-12-05.

#pragma once
#include "../../Actions/Action.h"

/**
 * Queue basé sur la doubly linked list perso (DLinkedList) dont les éléments sont des Action (de la classe Action).
 */
class ActionQueue {
public:
    int getSize();
    bool empty();
    const Action& front() const;
    void enqueue(const Action& action);
    void dequeue();
};
