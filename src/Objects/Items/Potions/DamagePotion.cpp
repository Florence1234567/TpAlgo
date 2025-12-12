//
// Created by Antoine on 2025-12-09.
//

#include "DamagePotion.h"

#include "../../Player/PlayerCharacter.h"

void DamagePotion::DrinkPotion(PlayerCharacter* player) {
    player->IncreaseDamage(damageAmount, buffDuration);
}
