//
// Created by Antoine on 2025-12-09.
//

#include "HealthPotion.h"

void HealthPotion::DrinkPotion(PlayerCharacter* player) {
    player->HealPlayer(healAmount);
}