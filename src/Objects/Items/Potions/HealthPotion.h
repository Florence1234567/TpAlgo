//
// Created by Antoine on 2025-12-09.
//

#pragma once
#include "../PotionItem.h"


class HealthPotion : public PotionItem {
public:
    HealthPotion() : PotionItem("Assets/Images/Objects/Potion2.png", "Health Potion") {};
    void DrinkPotion(PlayerCharacter* player) override;

private:
    float healAmount = 10;
};