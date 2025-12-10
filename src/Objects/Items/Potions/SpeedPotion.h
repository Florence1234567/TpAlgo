//
// Created by Antoine on 2025-12-09.
//

#pragma once
#include "../PotionItem.h"


class SpeedPotion : public PotionItem {
public:
    SpeedPotion() : PotionItem("Assets/Images/Objects/Berries.png", "Speed Potion") {};
    void DrinkPotion() override;

private:
};