//
// Created by Antoine on 2025-12-05.
//

#include "./Character.h"

void Character::Update(sf::Time dt) {
    if (bHasDestination) {
        sf::Vector2f curPos = sprite.getPosition();
        sf::Vector2f dir = destination - curPos;
        float distance = std::sqrt(dir.x * dir.x + dir.y * dir.y);

        if (distance < 1.f) {
            sprite.setPosition(destination);;
            bHasDestination = false;
        }else {
            sf::Vector2f relDir = dir / distance;
            sprite.move(relDir * speed * dt.asSeconds());
        }
    }
}

void Character::setDestination(float worldX, float worldY) {
    destination = sf::Vector2f(worldX, worldY);

    sf::Vector2f curPos = sprite.getPosition();
    sf::Vector2f dir = destination - curPos;

    if (std::hypot(dir.x, dir.y) < 1)
        return;
    
    bHasDestination = true;

    if (std::abs(dir.x) > std::abs(dir.y))
        currentDir = (dir.x > 0) ? Direction::Right : Direction::Left;
    else
        currentDir = (dir.y > 0) ? Direction::Down : Direction::Up;
}