#include "DialogUI.h"

void DialogUI::AddMessage(const std::string msg, sf::Vector2f pos)
{
    text = msg;
    timer = duration;
    sf::FloatRect bounds = background.getLocalBounds();
    background.setOrigin(sf::Vector2f(bounds.size.x / 2.f, bounds.size.y / 2.f));
    background.setPosition(pos);
    position = background.getPosition();
    isVisible = true;
}

void DialogUI::Update(sf::Time dt)
{
    if (!isVisible)
        return;

    timer -= dt.asSeconds();
    if (timer <= 0) {
        isVisible = false;
    }
}

void DialogUI::Draw(sf::RenderWindow& window)
{
    if (!isVisible) 
        return;

    window.draw(background);

    sf::Text textBox(font, text, 12);
    textBox.setFillColor(sf::Color::Black);
    sf::Vector2f textPosition = { position.x - background.getLocalBounds().size.x / 2.f + margin, position.y - background.getLocalBounds().size.y / 2.f + margin };
    textBox.setPosition(textPosition);

    window.draw(textBox);
}
