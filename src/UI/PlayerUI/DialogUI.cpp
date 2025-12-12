#include "DialogUI.h"

void DialogUI::AddMessage(const std::string& msg, sf::Vector2f pos)
{
    messages.push({ msg, pos });

    if (!isVisible)
        ShowNextMessage();
}

void DialogUI::Update(sf::Time dt)
{
    if (!isVisible) 
        return;

    timer += dt;
    if (timer >= duration) {
        ShowNextMessage();
    }
}

void DialogUI::ShowNextMessage()
{
    if (messages.empty()) {
        isVisible = false;
        return;
    }

    Message msg = messages.front();
    messages.pop();
    text = msg.text;
    position = msg.position;
    timer = sf::Time::Zero;
    isVisible = true;
}

void DialogUI::Draw(sf::RenderWindow& window)
{
    if (!isVisible) 
        return;

    background.setPosition(position);
    window.draw(background);

    sf::Text textBox(font, text, 20);
    textBox.setFillColor(sf::Color::Black);
    textBox.setPosition(position + sf::Vector2f(5.f, 5.f));

    window.draw(textBox);
}
