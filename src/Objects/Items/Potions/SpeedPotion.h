//
// Created by Antoine on 2025-12-09.
//

#pragma once
#include "../PotionItem.h"


class SpeedPotion : public PotionItem {
public:
    SpeedPotion() : PotionItem("Assets/Images/Objects/Potion4.png", "Speed Potion") {};
    void DrinkPotion(PlayerCharacter* player) override;

private:
    float speedBoostAmount = 40.f;
    float buffDuration = 25.f;
};