
#include "HealthBar.h"
#include <algorithm>

HealthBar::HealthBar(sf::Vector2f position, sf::Vector2f size, sf::Vector2u windowSize, PlayerCharacter& player)
	: UIComponent(position, size), playerRef(player)
{
	/*if (!heartTexture.loadFromFile("Assets/Images/Objects/Heart.png"))
		std::cerr << "Failed to load heart.png\n";

	heartSprite.setTexture(heartTexture);
	heartSprite.setScale({ 2.f, 2.f });*/

    //Background
    background.setPosition(position);
    background.setSize(size);
    background.setFillColor(sf::Color(220, 220, 220));
    background.setOutlineColor(sf::Color::Black);
    background.setOutlineThickness(2);

    //Foreground
    foreground.setPosition(position);
    foreground.setSize(size);
    foreground.setFillColor(sf::Color(120, 210, 170));
    fullWidth = size.x;

    health = playerRef.GetHealth();
    maxHealth = playerRef.GetMaxHealth();
}

void HealthBar::Draw(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(foreground);
}

void HealthBar::Update(sf::Time dt)
{
    health = playerRef.GetHealth();
    maxHealth = playerRef.GetMaxHealth();
    float ratio = health / maxHealth;
    ratio = std::clamp(ratio, 0.f, 1.f);

    foreground.setSize({ fullWidth * ratio, panelSize.y});

    if (ratio > 0.5f)
        foreground.setFillColor(sf::Color(120, 210, 170));
    else if (ratio > 0.25f)
        foreground.setFillColor(sf::Color(255, 235, 150));
    else
        foreground.setFillColor(sf::Color(255, 180, 185));
}
