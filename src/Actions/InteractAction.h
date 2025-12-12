//
// Created by Antoine on 2025-12-12.
//

#pragma once
#include "Action.h"
#include "MoveAction.h"
#include "../Objects/NPC/NPCCharacter.h"


class InteractAction : public Action {
public:
explicit InteractAction(Character* character, NPCCharacter* target) : Action(character, ActionType::Interact, "Interact"), NPC(target) {};

    void Execute() override;
    bool Update(sf::Time dt) override;
    bool isInRange() const;

    std::unique_ptr<Action> Clone() const override;

    std::unique_ptr<MoveAction> CallMoveActionFirst();

private:
    NPCCharacter* NPC;
    const float range = 10;
};
