#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerUIComponent.h"
#include "../../Player/PlayerController.h"
#include <vector>
#include <string>

class MovementQueueUI : public PlayerUIComponent {
public:
    MovementQueueUI(PlayerController& controller, sf::Vector2u& windowSize,
        float width, float height, const std::string& title = "Player Movement Queue");

    void Draw(sf::RenderWindow& window) override;
    void Update(sf::Time dt) override;

private:
    PlayerController& playerController; 
    std::vector<sf::Text> items;

    float timeSinceLastUpdate = 0;
    float interval = 0.5;
};
