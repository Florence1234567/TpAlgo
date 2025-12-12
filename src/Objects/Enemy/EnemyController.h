//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Controller.h"
#include <unordered_map>
#include "../../Game/GameMap.h"

class EnemyController : public Controller {
public:
    explicit EnemyController(Character* enemy, const GameMap* map) : Controller(enemy), gameMap(map) {};

    void HandleEvent(const sf::Event& event, sf::FloatRect playingBounds, sf::RenderWindow* window) override;

    void Update(sf::Time dt) override;

    //void PerformAction(std::unique_ptr<Action> action);

private:
    const GameMap* gameMap;
};
