//
// Created by Antoine on 2025-12-05.
//

#pragma once
#include "Action.h"
#include "SFML/System/Vector2.hpp"

class MoveAction : public Action {
public:
    MoveAction(Character* character, const sf::Vector2f& destination, const std::vector<sf::FloatRect>& colliders);

    void Execute() override;
    bool Update(sf::Time dt) override;

private:
    sf::Vector2f destination;
    const std::vector<sf::FloatRect>& colliders;
};
