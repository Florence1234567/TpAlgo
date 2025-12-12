#pragma once
#include "PlayerUIComponent.h"
#include "../UIComponent.h"
#include "../../Player/PlayerCharacter.h"
#include <iostream>
#include <queue>

class DialogUI : public UIComponent {
public:
    DialogUI(sf::Vector2f size = { 200.f, 50.f }, float durationSeconds = 3.f)
        :UIComponent(position, size), panelSize(size), duration(sf::seconds(durationSeconds)), font(font)
    {
        background.setSize(panelSize);
        background.setFillColor(sf::Color(255, 255, 255, 230));
        background.setOutlineColor(sf::Color::Black);
        background.setOutlineThickness(2);
    }

    void AddMessage(const std::string& msg, sf::Vector2f pos);

    void Draw(sf::RenderWindow& window) override;
    void Update(sf::Time dt) override;

private:
    struct Message {
        std::string text;
        sf::Vector2f position;
    };

    void ShowNextMessage();

    sf::Vector2f position;
    sf::Vector2f panelSize;
    sf::RectangleShape background;
    std::string text;
    bool isVisible = false;

    sf::Time timer;
    sf::Time duration;
    std::queue<Message> messages;

    sf::Font& font;
};