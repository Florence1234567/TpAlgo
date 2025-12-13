//
// Created by Antoine on 2025-12-09.
//

#pragma once
#include "../PotionItem.h"


class DamagePotion : public PotionItem {
public:
    DamagePotion() : PotionItem("Assets/Images/Objects/Potion6.png", "Damage Potion") {};
    void DrinkPotion(PlayerCharacter* player) override;

private:
    float damageAmount = 10;
    float buffDuration = 15.f;
};