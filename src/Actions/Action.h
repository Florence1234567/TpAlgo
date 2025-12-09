//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include <SFML/System/Time.hpp>
#include <stdexcept>

#include "../Objects/Character.h"

enum class ActionType {
    Move,
    Attack,
    Loot,
    UseItem,
    Wait,
    Unknown
};

class Action {
public:
    Action(Character* owner, ActionType actionType, const std::string& actionName) : owner(owner), type(actionType), bCompleted(false), name(actionName) {};
    virtual ~Action() = default;

    virtual void Execute() = 0;
    virtual bool Update(sf::Time dt) = 0;
    virtual bool Finished() { return bCompleted; };

    virtual std::unique_ptr<Action> Clone() const = 0;

    ActionType getType() const { return type; };
    std::string getName() const { return name; };

protected:
    Character* owner;
    bool bCompleted;
    ActionType type;
    std::string name;
};
