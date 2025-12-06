//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include <SFML/System/Time.hpp>
#include <stdexcept>

#include "../Base/Character.h"

class Action {
public:
    Action(Character* owner, const std::string& actionName) : owner(owner), bCompleted(false), name(actionName) {};
    virtual ~Action() = default;

    virtual void Execute() = 0;
    virtual bool Update(sf::Time dt) = 0;
    virtual bool Finished() { return bCompleted; };

    std::string getName() const { return name; };

protected:
    Character* owner;
    bool bCompleted;
    std::string name;
};
