#include "EnemyCharacter.h"

void EnemyCharacter::Update(sf::Time dt)
{
	Character::Update(dt);
	UpdateSprite(dt);
}

void EnemyCharacter::UpdateSprite(sf::Time dt)
{
    std::string spriteName;

    walkFrameTimer += dt.asSeconds();

    if (walkFrameTimer >= walkFrameDuration) {
        walkFrameTimer = 0;
        isWalkFrame1 = !isWalkFrame1;
    }

    if (enemyType == EnemyType::Chick)
        spriteName = "Chick";
    else
        spriteName = "Cow";

    if (!isWalkFrame1)
        spriteName += "1";


    auto it = enemySprites.find(spriteName);
    if (it != enemySprites.end()) {
        sf::Vector2f currentPos = sprite.getPosition();
        sprite = *(it->second.get());
        sprite.setPosition(currentPos);
    }
}

sf::FloatRect EnemyCharacter::GetCollisionBounds() const
{
    sf::FloatRect bounds = sprite.getGlobalBounds();

    float size = std::max(bounds.size.x, bounds.size.y);

    float offsetX = (bounds.size.x - size) / 2.f;
    float offsetY = (bounds.size.y - size) / 2.f;

    return sf::FloatRect(
        { bounds.position.x + offsetX,
          bounds.position.y + offsetY },
        { size, size }
    );
}

void EnemyCharacter::LoadCharacterTextures()
{
    for (const auto& [name, path] : enemyTextureFiles) {
        sf::Texture texture;
        if (texture.loadFromFile(path))
            enemyTextures[name] = std::move(texture);
        else
            std::cerr << "Error loading " << path << std::endl;
    }

    for (const auto& [name, texture] : enemyTextures) {
        enemySprites[name] = std::make_unique<sf::Sprite>(texture);
        enemySprites[name]->setScale(sf::Vector2f(scale, scale));
        sf::FloatRect bounds = enemySprites[name]->getLocalBounds();
        enemySprites[name]->setOrigin(sf::Vector2f(bounds.size.x / 2.f, bounds.size.y / 2.f));
    }
}
