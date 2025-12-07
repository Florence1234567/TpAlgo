//
// Created by Antoine on 2025-12-05.
//

#include "PlayerCharacter.h"

void PlayerCharacter::Update(sf::Time dt) {
    Character::Update(dt);
    UpdateSprite(dt);
}

void PlayerCharacter::UpdateSprite(sf::Time dt) {
    std::string spriteName;

    walkFrameTimer += dt.asSeconds() + speed;

    if (walkFrameTimer >= walkFrameDuration) {
        walkFrameTimer = 0;
        isWalkFrame1 = !isWalkFrame1;
    }

    if (bHasDestination) {
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
    } else {
        spriteName = "Front";
    }

    if (bHasDestination) {
        if (!isWalkFrame1)
            spriteName += "Walk1";
        else
            spriteName += "Walk2";
    }


    auto it = characterSprites.find(spriteName);
    if (it != characterSprites.end()) {
        sf::Vector2f currentPos = sprite.getPosition();
        sprite = *(it->second.get());
        sprite.setPosition(currentPos);
    }
}

void PlayerCharacter::LoadCharacterTextures() {
    for (const auto &[name, path]: characterTextureFiles) {
        sf::Texture texture;
        if (texture.loadFromFile(path))
            characterTextures[name] = texture;
        else
            std::cerr << "Error loading " << path << std::endl;
    }

    for (const auto &[name, texture]: characterTextures) {
        characterSprites[name] = std::make_unique<sf::Sprite>(texture);
        characterSprites[name]->setScale(sf::Vector2f(scale, scale));
        sf::FloatRect bounds = characterSprites[name]->getLocalBounds();
        characterSprites[name]->setOrigin(sf::Vector2f(bounds.size.x/2.f, bounds.size.y/2.f));
    }
}
