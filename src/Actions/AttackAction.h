//
// Created by Antoine on 2025-12-06.
//

#pragma once
#include "Action.h"
#include "SFML/System/Vector2.hpp"


class AttackAction : public Action {
public:
    explicit AttackAction(Character* character, const sf::Vector2f& destination) : Action(character, "Attack Action"), destination(destination) {};

    void Execute() override;
    bool Update(sf::Time dt) override;

private:
    sf::Vector2f destination;
};
