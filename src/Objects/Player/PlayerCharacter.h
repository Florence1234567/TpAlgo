//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Character.h"
#include <iostream>
#include "../GameObjects/GameObject.h"

class PlayerCharacter : public Character {
public:
	PlayerCharacter(int x, int y, float size, float baseSpeed, float hp)
	: Character(x, y, size, baseSpeed, hp, 15, 1, "Player", "Assets/Images/Character/C_Front.png" ){
		LoadCharacterTextures();
		currentDir = Direction::Down;
		walkFrameTimer = 0;
		walkFrameDuration = 1 - (speed / 75);
		isWalkFrame1 = true;
		speed = baseSpeed;
	};

	void Update(sf::Time dt) override;
    void UpdateSprite(sf::Time dt);

	void Loot(GameObject* lootTarget);

	std::vector<Item*> GetInventory() const { return inventory; };
	void UseItem(Item* item);

	void HealPlayer(float amount) { health += amount; };

private:
	std::vector<Item*> inventory;

	void LoadCharacterTextures();

    //Character Sprites
	std::map<std::string, std::string> characterTextureFiles = {
	 {"Back", "Assets/Images/Character/C_Back.png"},
	 {"BackJump", "Assets/Images/Character/C_BackJump.png"},
	 {"BackWalk1", "Assets/Images/Character/C_BackWalk1.png"},
	 {"BackWalk2", "Assets/Images/Character/C_BackWalk2.png"},
	 {"Front", "Assets/Images/Character/C_Front.png"},
	 {"FrontWalk1", "Assets/Images/Character/C_FrontWalk1.png"},
	 {"FrontWalk2", "Assets/Images/Character/C_FrontWalk2.png"},
	 {"Jump", "Assets/Images/Character/C_Jump.png"},
	 {"Left", "Assets/Images/Character/C_Left.png"},
     {"LeftWalk1", "Assets/Images/Character/C_LeftWalking1.png"},
	 {"LeftWalk2", "Assets/Images/Character/C_LeftWalking2.png"},
	 {"Right", "Assets/Images/Character/C_Right.png"},
	 {"RightWalk1", "Assets/Images/Character/C_RightWalking1.png"},
	 {"RightWalk2", "Assets/Images/Character/C_RightWalking2.png"}
	};

    std::map<std::string, sf::Texture> characterTextures;
    std::map<std::string, std::unique_ptr<sf::Sprite>> characterSprites;

	float walkFrameTimer;
	float walkFrameDuration;
	bool isWalkFrame1;
};
