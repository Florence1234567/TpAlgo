#pragma once
#include "PlayerUIComponent.h"
#include "../UIComponent.h"
#include <iostream>
#include <queue>

class DialogUI : public UIComponent {
public:
    DialogUI(sf::Vector2f size = { 200.f, 50.f }, float durationSeconds = 3.f)
        :UIComponent({0, 0}, size), panelSize(size), duration(durationSeconds)
    {
        background.setSize(panelSize);
        background.setFillColor(sf::Color(255, 255, 255, 230));
        background.setOutlineColor(sf::Color::Black);
        background.setOutlineThickness(2);
    }

    void AddMessage(const std::string msg, sf::Vector2f pos);

    void Draw(sf::RenderWindow& window) override;
    void Update(sf::Time dt) override;

    void SetPosition(sf::Vector2f pos) { position = pos; };

private:
    sf::Vector2f panelSize;
    sf::RectangleShape background;
    std::string text;
    bool isVisible = false;
    float margin = 2.f;

    float timer;
    float duration;
};