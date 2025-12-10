//
// Created by Antoine on 2025-12-09.
//

#pragma once
#include "Item.h"


class PotionItem : public Item {
public:
    PotionItem(std::string texturePath, std::string potionName);

    void UseItem(PlayerCharacter* player) override;
    virtual void DrinkPotion(PlayerCharacter* player) = 0;

private:
};
