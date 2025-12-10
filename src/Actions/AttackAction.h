//
// Created by Antoine on 2025-12-06.
//

#pragma once
#include "Action.h"
#include "MoveAction.h"
#include "../Enemy/EnemyCharacter.h"
#include "SFML/System/Vector2.hpp"


class AttackAction : public Action {
public:
    explicit AttackAction(Character* character, EnemyCharacter* target) : Action(character, ActionType::Attack, "Attack"), enemy(target) {};

    void Execute() override;
    bool Update(sf::Time dt) override;
    bool isInRange() const;

    std::unique_ptr<Action> Clone() const override;

    std::unique_ptr<MoveAction> CallMoveActionFirst();

private:
    EnemyCharacter* enemy;
    const float range = 10;
};
