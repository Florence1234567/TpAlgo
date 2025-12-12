//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "Object.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


class Character : public Object {
public:
    Character(int x, int y, float size, float baseSpeed, float hp, float damage, const float attackCooldown, std::string name, const std::string& texturePath)
        : Object(x, y, size, texturePath), baseSpeed(baseSpeed), speed(baseSpeed), health(hp), maxHealth(hp), baseDamage(damage), damage(damage), armour(0), name(name), ATTACKCOOLDOWN(attackCooldown), currentCooldown(0) {};

    enum class Direction {
        Up, Down, Left, Right
    };

    virtual void Update(sf::Time dt);
    void setDestination(float worldX, float worldY);
    sf::Vector2<float> getDestination() { return destination; };
    Direction getDirection() const { return currentDir; };
    bool hasDestination() const { return bHasDestination; };
    void Move(sf::Time dt);
    float GetHealth() const { return health; };
    float GetMaxHealth() const { return maxHealth; };

    bool isAlive() const { return health > 0; };
    void TakeDamage(float damage);
	void Attack(Character* target);

protected:
    std::string name;
    float speed;
    float baseSpeed;
    float health;
    float maxHealth;
    float damage;
    float baseDamage;
    float armour;
    sf::Vector2<float> destination;
    bool bHasDestination = false;
    Direction currentDir;

	const float ATTACKCOOLDOWN;
	float currentCooldown;
	Character* currentTarget = nullptr;
};
