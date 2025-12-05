//
// Created by Antoine on 2025-12-05.
//

#include "Object.h"

Object::Object(int x, int y, float size, const std::string &texturePath) : posX(x), posY(y), sprite(sf::Sprite(texture)) {
    if (!texture.loadFromFile(texturePath))
        throw std::runtime_error("Failed to load texture " + texturePath);

    sprite.setTexture(texture, true);
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(sf::Vector2f(bounds.size.x / 2.f, bounds.size.y / 2.f));
    sprite.setPosition(sf::Vector2f(x, y));

    sprite.setScale(sf::Vector2f(size, size));
}

void Object::Draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}
