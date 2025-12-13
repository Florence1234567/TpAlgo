//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Character.h"
#include <iostream>
#include <map>
#include "../GameObjects/GameObject.h"
#include "../Items/Item.h"
#include <SFML/Graphics.hpp>
#include "../../UI/DialogUI.h"

class DialogUI;

class PlayerCharacter : public Character {
public:
	PlayerCharacter(int x, int y, float size, DialogUI* dialogUI)
		: Character(x, y, size, 50.f, 100.f, 15, 0.75f, "Player", "Assets/Images/Character/C_Front.png"), dialogUI(dialogUI)
	{
		LoadCharacterTextures();
		currentDir = Direction::Down;
		walkFrameTimer = 0;
		walkFrameDuration = 1 - (speed / 75);
		isWalkFrame1 = true;
		speed = baseSpeed;
	}

	void Update(sf::Time dt) override;
	void UpdateSprite(sf::Time dt);

	void Loot(GameObject* lootTarget);

	std::vector<Item*> GetInventory() const { return inventory; };
	void UseItem(Item* item);

	void HealPlayer(float amount) { health += amount; };
	void IncreaseDamage(float amount, float buffTime);
	void IncreaseSpeed(float amount, float buffTime);

	void ShowDialog(const std::string message) const;
	DialogUI* GetDialogUI() const { return dialogUI; };

private:
	DialogUI* dialogUI;

	std::vector<Item*> inventory;
	float damageBuffTimer;
	float speedBuffTimer;

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
