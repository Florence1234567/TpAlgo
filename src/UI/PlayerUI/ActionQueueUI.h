#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerUIComponent.h"
#include "../../Player/PlayerController.h"
#include <vector>
#include <string>

class ActionQueueUI : public PlayerUIComponent {
public:
    ActionQueueUI(PlayerController& controller, sf::Vector2u& windowSize, float margin = 20, float rightPadding = 280);

    void Draw(sf::RenderWindow& window) override;
    void Update(sf::Time dt) override;

private:
    PlayerController& playerController; 
    std::vector<sf::Text> items;

    float timeSinceLastUpdate = 0;
    float interval = 0.5;
    sf::Vector2f size = sf::Vector2f(5, 7);
};
