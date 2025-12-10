//
// Created by Antoine on 2025-12-07.
//

#pragma once
#include "Action.h"
#include "MoveAction.h"
#include "../Objects/GameObjects/GameObject.h"


class LootAction : public Action {
public:
    explicit LootAction(Character* character, GameObject* target) : Action(character, ActionType::Loot, "Loot"), object(target) {};

    void Execute() override;
    bool Update(sf::Time dt) override;
    bool isInRange() const;

    std::unique_ptr<Action> Clone() const override;

    std::unique_ptr<MoveAction> CallMoveActionFirst();

private:
    GameObject* object;
    const float range = 10;
    float lootTime = 3.f;
};
