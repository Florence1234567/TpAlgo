//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Character.h"
#include <iostream>
#include <map>

#include "../GameObjects/GameObject.h"

enum NPCTypes {
	NPC_Chicken,
	NPC_Cow
};

class NPCCharacter : public Character {
public:
	NPCCharacter(int x, int y, float size, NPCTypes type, std::string name)
		: Character(x, y, size, 0.f, 1000.f, 0.f, 0.f, name, "Assets/Images/Character/C_Front.png"), ATTACKCOOLDOWN(0), currentCooldown(0) {
		LoadCharacterTextures();
		currentDir = Direction::Down;
		walkFrameTimer = 0;
		walkFrameDuration = 1;
		isWalkFrame1 = true;
		speed = baseSpeed;
		NPCType = type;
	};

	void Update(sf::Time dt) override;
	void UpdateSprite(sf::Time dt);

	sf::FloatRect GetCollisionBounds() const;

private:
	std::vector<Item*> inventory;
	const float ATTACKCOOLDOWN;
	float currentCooldown;


	//NPC Sprites
	std::map<std::string, std::string> NPCTextureFiles = {
	 {"Chick", "Assets/Images/Character/Chick.png"},
	 {"Chick1", "Assets/Images/Character/Chick1.png"},
	 {"Cow", "Assets/Images/Character/Cow.png"},
	 {"Cow1", "Assets/Images/Character/Cow1.png"},
	};

	void LoadCharacterTextures();

	std::map<std::string, sf::Texture> NPCTextures;
	std::map<std::string, std::unique_ptr<sf::Sprite>> NPCSprites;

	float walkFrameTimer;
	float walkFrameDuration;
	bool isWalkFrame1;

	NPCTypes NPCType;
};
