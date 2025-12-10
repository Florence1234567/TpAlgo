//
// Created by Antoine on 2025-12-09.
//

#pragma once
#include "Item.h"


class PotionItem : public Item {
public:
    PotionItem(std::string texturePath, std::string potionName);

    void UseItem() override;
    virtual void DrinkPotion() = 0;

private:
};
