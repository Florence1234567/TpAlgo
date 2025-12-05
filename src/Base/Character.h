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
    Character(int x, int y, float size, int baseSpeed, float hp, const std::string& texturePath): Object(x, y, size, texturePath), speed(baseSpeed), health(hp), maxHealth(hp) {};

protected:
    int speed;
    float health;
    float maxHealth;

};
