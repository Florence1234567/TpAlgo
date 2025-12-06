//
// Created by Antoine on 2025-12-05.
//

#include "PlayerCharacter.h"

void PlayerCharacter::UpdateSprite(sf::Time dt)
{
	std::string spriteName;

	walkFrameTimer += dt.asSeconds();

	if (walkFrameTimer >= walkFrameDuration)
	{
		walkFrameTimer = 0;
		isWalkFrame1 = !isWalkFrame1;
	}

	if (bHasDestination)
	{
		switch (currentDir) {
		case Direction::Up:
			spriteName = "BackWalk";
			break;
		case Direction::Down:
			spriteName = "FrontWalk";
			break;
		case Direction::Left:
			spriteName = "LeftWalk";
			break;
		case Direction::Right:
			spriteName = "RightWalk";
			break;
		}

		if (!isWalkFrame1)
			spriteName += "1";
		else
			spriteName += "2";
	}
	else
		//Idle
		switch (currentDir) {
		case Direction::Up:
			spriteName = "Back";
			break;
		case Direction::Down:
			spriteName = "Front";
			break;
		case Direction::Left:
			spriteName = "Left";
			break;
		case Direction::Right:
			spriteName = "Right";
			break;
		}

	auto it = characterSprites.find(spriteName);
	if (it != characterSprites.end()) {
		sf::Vector2f currentPos = sprite.getPosition();
		sprite = *(it->second.get());
		sprite.setPosition(currentPos);
	}
}

void PlayerCharacter::LoadCharacterTextures()
{
	for (const auto& [name, path] : characterTextureFiles)
	{
		sf::Texture texture;
		if (texture.loadFromFile(path))
			characterTextures[name] = texture;
		else
			std::cerr << "Error loading " << path << std::endl;
	}

	for (const auto& [name, texture] : characterTextures)
	{
		characterSprites[name] = std::make_unique<sf::Sprite>(texture);
		float scale = 2;
		characterSprites[name]->setScale(sf::Vector2f(scale, scale));

	}
}
