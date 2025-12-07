//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Base/Controller.h"
#include <unordered_map>
#include "../DataStructures/Queue/ActionQueue.h"


class PlayerController : public Controller {
public:
    explicit PlayerController(Character* player, const std::vector<sf::FloatRect>& objectBoundsRef) 
        : Controller(player), objectBounds(objectBoundsRef) {};

    void HandleEvent(const sf::Event& event, sf::FloatRect playingBounds, sf::RenderWindow* window) override;

    void Update(sf::Time dt) override;

private:
    const std::vector<sf::FloatRect>& objectBounds;
};
