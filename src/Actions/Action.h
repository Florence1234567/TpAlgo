//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include <SFML/System/Time.hpp>
#include <stdexcept>

class Action {
public:
    virtual ~Action() = default;

    virtual void Start() {};
    virtual bool Update(sf::Time dt) = 0;
    virtual void Finish() {};
};