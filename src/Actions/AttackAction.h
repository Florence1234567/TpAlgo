//
// Created by Antoine on 2025-12-06.
//

#pragma once
#include "Action.h"
#include "SFML/System/Vector2.hpp"


class AttackAction : public Action {
public:
    explicit AttackAction(Character* character, const sf::Vector2f& destination) : Action(character, ActionType::Attack, "Attack"), destination(destination) {};

    void Execute() override;
    bool Update(sf::Time dt) override;

    std::unique_ptr<Action> Clone() const override;

private:
    sf::Vector2f destination;
};
