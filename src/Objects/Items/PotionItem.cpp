//
// Created by Antoine on 2025-12-09.
//

#include "PotionItem.h"

PotionItem::PotionItem(std::string texturePath, std::string potionName) : Item(5, 10, 5, texturePath, ItemType::HealthPotion, potionName) {
    bConsumable = true;
}

void PotionItem::UseItem() {
    DrinkPotion();
}