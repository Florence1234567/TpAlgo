//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Character;

class Controller {
public:
    explicit Controller(Character* character): owner(character) {};
    virtual  ~Controller() = default;

    virtual void Update(sf::Time dt) = 0;

    virtual void HandleEvent(const sf::Event& event, sf::RenderWindow* window = nullptr) {};

protected:
    Character* owner;
};