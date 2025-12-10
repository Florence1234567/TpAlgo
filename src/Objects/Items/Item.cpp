//
// Created by Antoine on 2025-12-09.
//

#include "Item.h"

Item::Item(std::string texturePath, ItemType itemType, std::string itemName) : Object(0, 0, 0, texturePath), name(itemName) {
    type = itemType;
}

void Item::Draw(sf::RenderWindow& window) const {
    Object::Draw(window);
}
