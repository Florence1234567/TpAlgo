//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "Object.h"
#include <map>
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Network/SocketHandle.hpp"
#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"


class Character : public Object {
public:
    Character(int x, int y, float size, float baseSpeed, float hp, const std::string& texturePath): Object(x, y, size, texturePath), speed(baseSpeed), health(hp), maxHealth(hp) {};

    enum class Direction {
        Up, Down, Left, Right
    };

    virtual void Update(sf::Time dt);
    void setDestination(float worldX, float worldY);
    bool hasDestination() const { return bHasDestination; };
    sf::Vector2<float> getDestination() { return destination; };
    Direction getDirection() const { return currentDir; };

    void Move(sf::Time dt);

protected:
    float speed;
    float health;
    float maxHealth;
    sf::Vector2<float> destination;
    bool bHasDestination = false;
    Direction currentDir;
};
