//
// Created by Antoine on 2025-10-15.
//

#pragma once
#include "DNode.hpp"
#include <iostream>

template<typename E>
class DLinkedList {
public:
	DLinkedList();
	~DLinkedList();
	bool empty() const;
	const E& front() const;
	const E& back() const;
	void add(DNode<E>* node, E&& element);
	void addFront(E&& element);
	void addBack(E&& element);
	void remove(DNode<E>* node);
	void removeFront();
	void removeBack();
	DNode<E>* getHead() const;
	E* getHeadElem() const;
	int getSize() const;
	const E& At(int index) const;
private:
	DNode<E>* head;
	DNode<E>* tail;
	int size;
};

template<typename E>
DLinkedList<E>::DLinkedList() {
	head = new DNode<E>();
	tail = new DNode<E>();
	head->next = tail;
	tail->prev = head;
	size = 0;
}

template<typename E>
DLinkedList<E>::~DLinkedList() {
	while (!empty()) {
		removeFront();
	}
	delete head;
	delete tail;
}

template<typename E>
bool DLinkedList<E>::empty() const {
	return size == 0;
}

template<typename E>
const E& DLinkedList<E>::front() const {
	if (empty())
		throw std::out_of_range("The list is empty.");

	return head->next->element;
}

template<typename E>
const E& DLinkedList<E>::back() const {
	if (empty())
		throw std::out_of_range("The list is empty.");

	return tail->prev->element;
}

template<typename E>
void DLinkedList<E>::add(DNode<E>* node, E&& element) {
	DNode<E>* newNode = new DNode<E>();
	newNode->element = std::move(element);
	newNode->next = node;
	newNode->prev = node->prev;
	node->prev->next = newNode;
	node->prev = newNode;
	size++;
}

template<typename E>
void DLinkedList<E>::addFront(E&& element) {
	add(head->next, std::move(element));
}

template<typename E>
void DLinkedList<E>::addBack(E&& element) {
	add(tail, std::move(element));
}

template<typename E>
void DLinkedList<E>::remove(DNode<E>* node) {
	if (empty())
		throw std::out_of_range("The list is empty.");

	DNode<E>* prev = node->prev;
	DNode<E>* next = node->next;
	prev->next = next;
	next->prev = prev;
	delete node;
	size--;
}

template<typename E>
void DLinkedList<E>::removeFront() {
	remove(head->next);
}

template<typename E>
void DLinkedList<E>::removeBack() {
	remove(tail->prev);
}

template<typename E>
DNode<E>* DLinkedList<E>::getHead() const {
	return head->next;
}

template<typename E>
E* DLinkedList<E>::getHeadElem() const {
	return &head->next->element;
}

template<typename E>
int DLinkedList<E>::getSize() const {
	return size;
}

template<typename E>
const E& DLinkedList<E>::At(int index) const
{
	DNode<E>* cur = head;

	for (int i = 0; i < index; ++i)
		cur = cur->next;

	return cur->element;
}
