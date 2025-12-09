#include "InventoryUI.h"

InventoryUI::InventoryUI(PlayerController& controller, PlayerCharacter& character, sf::Vector2u& windowSize, float margin, float rightPadding)
	: PlayerUIComponent({ static_cast<float>(windowSize.x) - (4 * PixelsPerSquare) - margin - rightPadding, margin }, { 5.f, 7.f }, 20.f, 280.f), controller(controller), character(character)
{
	position.x = static_cast<float>(windowSize.x) - background.getSize().x - margin;
	position.y = static_cast<float>(windowSize.y) - background.getSize().y - margin;

	background.setPosition(position);

	title = sf::Text(font, "Inventory", 20);
	title.setFillColor(mainTextColor);
	title.setPosition({ position.x + contentMargin, position.y + contentMargin - 5 });
}

void InventoryUI::Draw(sf::RenderWindow& window)
{
	PlayerUIComponent::Draw(window);

	for (const auto& slot : items)
	{
		window.draw(slot.sprite);

		sf::Text text(font, slot.name + "		x" + std::to_string(slot.count), 16);
		text.setFillColor(mainTextColor);
		text.setPosition({ slot.sprite.getPosition().x + 60.f, slot.sprite.getPosition().y - 10.f});

		window.draw(text);
	}
}

void InventoryUI::Update(sf::Time dt)
{
	items.clear();

	std::vector<Item*> inventory = character.GetInventory();

	if (inventory.empty())
		return;

	float x = background.getPosition().x + contentMargin;
	float y = background.getPosition().y + contentMargin + 20;

	const float rowSpacing = 48.f;

	std::map<sf::String, int> typeCounts;
	std::map<sf::String, Item*> typeToExample;

	for (Item* item : inventory)
	{
		if (!item)
			continue;

		sf::String type = item->GetName();
		typeCounts[type]++;
		typeToExample[type] = item;
	}

	std::size_t index = 0;

	for (auto& pair : typeCounts)
	{
		sf::String name = pair.first;
		int count = pair.second;

		Item* exampleItem = typeToExample[name];
		if (!exampleItem)
			continue;

		const sf::Sprite* original = exampleItem->getSprite(); 
		sf::Sprite sprite = *original;                          
		sprite.setScale({ 3.f, 3.f });                          
		sprite.setPosition({ x + contentMargin, y + index * rowSpacing + contentMargin });

		InventorySlot slot(sprite, name, count);

		items.push_back(slot);

		++index;
	}
}
