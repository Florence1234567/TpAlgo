//
// Created by Antoine on 2025-12-09.
//

#include "Item.h"

Item::Item(int x, int y, float size, std::string texturePath, ItemType itemType, std::string itemName) : Object(x, y, size, texturePath), name(itemName) {
    type = itemType;
}

void Item::Draw(sf::RenderWindow& window) const {
    Object::Draw(window);
}
