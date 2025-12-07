//
// Created by Antoine on 2025-12-05.
//

#pragma once
#include "Action.h"
#include "../Base/Character.h"


class WaitAction : public Action {
public:
    explicit WaitAction(Character* character) : Action(character, "Wait Action"), waitTime(3.f) {};

    void Execute() override;
    bool Update(sf::Time df) override;

private:
    float waitTime;
};
