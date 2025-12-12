//
// Created by Antoine on 2025-12-10.
//

#include "HealthPotion.h"

#include "../../Player/PlayerCharacter.h"

void HealthPotion::DrinkPotion(PlayerCharacter* player) {
    player->HealPlayer(healAmount);

    // TODO ajouter message d'action (besoin implémentation UI dialogue)
    player->ShowDialog("Health potion consumed");
}
