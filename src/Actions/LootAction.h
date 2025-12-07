//
// Created by Antoine on 2025-12-07.
//

#pragma once
#include "Action.h"
#include "MoveAction.h"
#include "../Game/GameObjects/GameObject.h"


class LootAction : public Action {
public:
    explicit LootAction(Character* character, const GameObject* target) : Action(character, ActionType::Loot, "Loot"), object(target) {};

    void Execute() override;
    bool Update(sf::Time dt) override;
    bool isInRange() const;

    std::unique_ptr<Action> Clone() const override;

    std::unique_ptr<MoveAction> CallMoveActionFirst();

private:
    const GameObject* object;
    const float range = 100;
};
