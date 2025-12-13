#include "NPCCharacter.h"

void NPCCharacter::Update(sf::Time dt)
{
	Character::Update(dt);
	UpdateSprite(dt);

    if (dialogActive) {
        if (dialogUI->DialogOver()) {
            ShowDialogs(currentDialogs[0]);
            currentDialogs.erase(currentDialogs.begin());
        }

        if (currentDialogs.empty())
            dialogActive = false;
    }
}

void NPCCharacter::UpdateSprite(sf::Time dt)
{
    std::string spriteName;

    walkFrameTimer += dt.asSeconds();

    if (walkFrameTimer >= walkFrameDuration) {
        walkFrameTimer = 0;
        isWalkFrame1 = !isWalkFrame1;
    }

    if (NPCType == NPCTypes::Fox)
        spriteName = "Fox";

    if (!isWalkFrame1)
        spriteName += "1";
    else
        spriteName += "2";


    auto it = NPCSprites.find(spriteName);
    if (it != NPCSprites.end()) {
        sf::Vector2f currentPos = sprite.getPosition();
        sprite = *(it->second.get());
        sprite.setPosition(currentPos);
    }
}

sf::FloatRect NPCCharacter::GetCollisionBounds() const
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

void NPCCharacter::LoadCharacterTextures()
{
    for (const auto& [name, path] : NPCTextureFiles) {
        sf::Texture texture;
        if (texture.loadFromFile(path))
            NPCTextures[name] = std::move(texture);
        else
            std::cerr << "Error loading " << path << std::endl;
    }

    for (const auto& [name, texture] : NPCTextures) {
        NPCSprites[name] = std::make_unique<sf::Sprite>(texture);
        NPCSprites[name]->setScale(sf::Vector2f(scale, scale));
        sf::FloatRect bounds = NPCSprites[name]->getLocalBounds();
        NPCSprites[name]->setOrigin(sf::Vector2f(bounds.size.x / 2.f, bounds.size.y / 2.f));
    }
}

void NPCCharacter::StartDialog() {
    currentDialogs = Dialogs;
    dialogActive = true;
}


void NPCCharacter::ShowDialogs(const std::string message) const {
    if (!dialogUI)
        return;

    sf::Vector2f pos = sf::Vector2f({sprite.getPosition().x, sprite.getPosition().y - sprite.getLocalBounds().size.y - 15.f});
    dialogUI->AddMessage(message, pos);
}
