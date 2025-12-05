//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Base/Controller.h"
#include <unordered_map>


class PlayerController : public Controller {
public:
    explicit PlayerController(Character* player) : Controller(player) {};

    void HandleEvent(const sf::Event& event, sf::RenderWindow* window) override;

    void Update(sf::Time dt) override;

private:
};
