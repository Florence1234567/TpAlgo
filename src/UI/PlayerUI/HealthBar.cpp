#include "HealthBar.h"

HealthBar::HealthBar(sf::Vector2f position, sf::Vector2f panelSize, sf::Vector2u windowSize, PlayerCharacter& player)
	: UIComponent(position, panelSize), playerRef(player), heartSprite(heartTexture)
{
	if (!heartTexture.loadFromFile("Assets/Images/Objects/Hearth.png"))
		std::cerr << "Failed to load heart.png\n";
}

void HealthBar::Draw(sf::RenderWindow& window)
{
	int health = playerRef.GetHealth();
	int healthPerHeart = 20;
	int numHearts = (health + healthPerHeart - 1) / healthPerHeart;

	float x = position.x;
	float y = position.y;

	for (int i = 0; i < numHearts; ++i)
	{
		heartSprite.setPosition({ 140, 140 });
		window.draw(heartSprite);
		x += heartSprite.getGlobalBounds().position.x + spacing;
	}
}

void HealthBar::Update(sf::Time dt)
{

}
