//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Controller.h"
#include <unordered_map>
#include "../../Game/GameMap.h"

class NPCController : public Controller {
public:
    explicit NPCController(Character* NPC, const GameMap* map) : Controller(NPC), gameMap(map) {};

    void HandleEvent(const sf::Event& event, sf::FloatRect playingBounds, sf::RenderWindow* window) override;

    void Update(sf::Time dt) override;

    //void PerformAction(std::unique_ptr<Action> action);

private:
    const GameMap* gameMap;
};
