//
// Created by Antoine on 2025-12-09.
//

#include "PotionItem.h"

PotionItem::PotionItem(std::string texturePath, std::string potionName) : Item(texturePath, ItemType::HealthPotion, potionName) {
    bConsumable = true;
}

void PotionItem::UseItem() {
    DrinkPotion();
}