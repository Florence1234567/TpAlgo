#include "InventoryUI.h"

InventoryUI::InventoryUI(PlayerController& controller, sf::Vector2u& windowSize, float width, float height, float paddingTop, const std::string& titleText)
	: PlayerUIComponent(width, height, titleText)
{
	position.x = static_cast<float>(windowSize.x) - panelSize.x - margin;
	position.y = margin + paddingTop + 70;

	background.setPosition(position);
	title.setPosition({ position.x + contentMargin, position.y + contentMargin - 5 });
}

void InventoryUI::Draw(sf::RenderWindow& window)
{
	PlayerUIComponent::Draw(window);
}

void InventoryUI::Update(sf::Time dt)
{
}