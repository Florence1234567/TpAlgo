//
// Created by Antoine on 2025-12-05.
//

#pragma once
#include "Action.h"
#include "SFML/System/Vector2.hpp"


class MoveAction : public Action {
public:
    explicit MoveAction(Character* character, const sf::Vector2f& destination) 
        : Action(character, ActionType::Move, "Move"), destination(destination) {};

    void Execute() override;
    bool Update(sf::Time dt) override;

    std::unique_ptr<Action> Clone() const override;

private:
    sf::Vector2f destination;
};
