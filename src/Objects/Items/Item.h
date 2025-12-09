//
// Created by Antoine on 2025-12-09.
//

#pragma once
#include "../Object.h"

enum class ItemType {
    HealthPotion,
    DamagePotion,
    SpeedPotion,
    FireDamagePotion,
    IceDamagePotion,
};

class Item : public Object {
public:
    Item(int x, int y, float size, std::string texturePath, ItemType type, std::string itemName);

    void Draw(sf::RenderWindow& window) const override;

    ItemType GetItemType() const { return type; };
    bool IsConsumable() const { return bConsumable; };
    virtual void UseItem() = 0;
    std::string GetName() const { return name; };

protected:
    ItemType type;
    bool bConsumable = false;
    std::string name;
};
