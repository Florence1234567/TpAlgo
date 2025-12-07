#pragma once
#include "PlayerUIComponent.h"
#include "../../Player/PlayerController.h"

class InventoryUI : PlayerUIComponent {
public:
    InventoryUI(PlayerController& controller, sf::Vector2u& windowSize,
        float width, float height, float paddingTop, const std::string& titleText = "Inventory");

    void Draw(sf::RenderWindow& window) override;
    void Update(sf::Time dt) override;

private:
    float contentMargin = 30;
};