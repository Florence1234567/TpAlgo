//
// Created by Antoine on 2025-12-09.
//

#pragma once
#include "../PotionItem.h"


class DamagePotion : public PotionItem {
public:
    DamagePotion() : PotionItem("Assets/Images/Objects/Berries.png", "Damage Potion") {};
    void DrinkPotion() override;

private:
};