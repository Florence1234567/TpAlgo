//
// Created by Antoine on 2025-10-15.
//

#pragma once
#include <iostream>

template<typename E>
class DLinkedList;

template<typename E>
class DNode {
private:
    E element;
    DNode<E>* prev;
    DNode<E>* next;

    friend class DLinkedList<E>;
public:
    E& GetElement() { return element; };
};
