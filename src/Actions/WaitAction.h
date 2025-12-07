//
// Created by Antoine on 2025-12-05.
//

#pragma once
#include "Action.h"
#include "../Base/Character.h"


class WaitAction : public Action {
public:
    explicit WaitAction(Character* character) : Action(character, ActionType::Wait, "Wait Action"), waitTime(1.5f) {};

    void Execute() override;
    bool Update(sf::Time df) override;

    std::unique_ptr<Action> Clone() const override;

private:
    float waitTime;
};
