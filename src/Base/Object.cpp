//
// Created by Antoine on 2025-12-05.
//

#include "Object.h"

Object::Object(int x, int y, float size, const std::string &texturePath) : posX(x), posY(y), scale(size), sprite(sf::Sprite(texture)) {
    if (!texture.loadFromFile(texturePath))
        throw std::runtime_error("Failed to load texture " + texturePath);

    bDestroyed = false;
    bVisible = true;

    sprite.setTexture(texture, true);
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(sf::Vector2f(bounds.size.x / 2.f, bounds.size.y / 2.f));
    sprite.setPosition(sf::Vector2f(x, y));

    sprite.setScale(sf::Vector2f(scale, scale));
}

void Object::Draw(sf::RenderWindow &window) const {
    if (bVisible || !bDestroyed)
        window.draw(sprite);
}

void Object::Destroy() {
    bDestroyed = true;
    bVisible = false;
    sprite.setPosition({-1000.f, -1000.f});
    sprite.setScale({0.f, 0.f});
}