//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Actions/Action.h"
#include "../DataStructures/Queue/ActionQueue.h"

class Character;

class Controller {
public:
    explicit Controller(Character* character): owner(character) { actions = new ActionQueue(); };
    virtual  ~Controller() { delete actions; };

    virtual void Update(sf::Time dt);

    virtual void HandleEvent(const sf::Event& event, const sf::FloatRect playingBounds, sf::RenderWindow* window = nullptr) = 0;

protected:
    Character* owner;
    void PushAction(std::unique_ptr<Action> action);
    void ExecuteAction();
    ActionQueue* actions;
    std::unique_ptr<Action> currentAction;
};