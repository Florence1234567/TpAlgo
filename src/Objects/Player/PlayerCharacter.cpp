//
// Created by Antoine on 2025-12-05.
//

#include "PlayerCharacter.h"

#include <thread>

void PlayerCharacter::Update(sf::Time dt) {
    Character::Update(dt);
    UpdateSprite(dt);

    canMove = dialogUI->DialogOver();

    // Gestion des buff des dégats et de la vitesse
    if (damageBuffTimer > 0) damageBuffTimer -= dt.asSeconds();
    if (damageBuffTimer <= 0) damage = baseDamage;

    if (speedBuffTimer > 0) speedBuffTimer -= dt.asSeconds();
    if (speedBuffTimer <= 0) speed = baseSpeed;
}

void PlayerCharacter::UpdateSprite(sf::Time dt) {
    std::string spriteName;

    walkFrameTimer += dt.asSeconds();

    if (walkFrameTimer >= walkFrameDuration) {
        walkFrameTimer = 0;
        isWalkFrame1 = !isWalkFrame1;
    }

    if (bHasDestination && canMove) {
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

    if (bHasDestination && canMove) {
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
            characterTextures[name] = std::move(texture);
        else
            std::cerr << "Error loading " << path << std::endl;
    }

    for (const auto &[name, texture]: characterTextures) {
        characterSprites[name] = std::make_unique<sf::Sprite>(texture);
        characterSprites[name]->setScale(sf::Vector2f(scale, scale));
        sf::FloatRect bounds = characterSprites[name]->getLocalBounds();
        characterSprites[name]->setOrigin(sf::Vector2f(bounds.size.x / 2.f, bounds.size.y / 2.f));
    }
}

void PlayerCharacter::Loot(GameObject *lootTarget) {
    ShowDialog("Done looting!");

    for (auto object: lootTarget->GetInventory())
        inventory.push_back(object);

    lootTarget->Destroy();
}

void PlayerCharacter::UseItem(Item *item) {
    item->UseItem(this);
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it == inventory.end())
        return;
    inventory.erase(it);
}

void PlayerCharacter::IncreaseDamage(float amount, float buffTime) {
    damage += amount;
    damageBuffTimer = buffTime;
}

void PlayerCharacter::IncreaseSpeed(float amount, float buffTime) {
    speed += amount;
    speedBuffTimer = buffTime;
}

void PlayerCharacter::ShowDialog(const std::string message) const {
    if (!dialogUI)
        return;

    sf::Vector2f pos = sf::Vector2f({sprite.getPosition().x, sprite.getPosition().y - sprite.getLocalBounds().size.y});
    dialogUI->AddMessage(message, pos);
}
