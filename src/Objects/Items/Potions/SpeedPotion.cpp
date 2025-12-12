//
// Created by Antoine on 2025-12-09.
//

#include "SpeedPotion.h"

#include "../../Player/PlayerCharacter.h"

void SpeedPotion::DrinkPotion(PlayerCharacter* player) {
    player->IncreaseSpeed(speedBoostAmount, buffDuration);
    // TODO ajouter message d'action (besoin implémentation UI dialogue)
    player->ShowDialog("Speed potion consumed");
}