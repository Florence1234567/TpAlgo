//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include <iostream>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"


class Object {
public:
    Object(int x, int y, float size, const std::string& texturePath);

    void Draw(sf::RenderWindow& window) const;

    const sf::Sprite* GetSprite() const { return &sprite; };

    sf::Vector2f GetPosition() const { return sf::Vector2f(posX, posY); };

    float GetSize() const { return sprite.getScale().x; };

protected:
    int posX;
    int posY;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};
