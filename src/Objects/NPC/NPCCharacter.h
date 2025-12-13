//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Character.h"
#include <iostream>
#include <map>

#include "../../UI/PlayerUI/DialogUI.h"
#include "../GameObjects/GameObject.h"

class DialogUI;

enum NPCTypes {
	Fox
};

class NPCCharacter : public Character {
public:
	NPCCharacter(int x, int y, float size, NPCTypes type, std::string name, DialogUI* dialogUI)
		: Character(x, y, size, 0.f, 1000.f, 0.f, 0.f, name, "Assets/Images/Character/C_Front.png"), ATTACKCOOLDOWN(0), currentCooldown(0), dialogUI(dialogUI) {
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

	void StartDialog() const;

private:
	std::vector<Item*> inventory;
	const float ATTACKCOOLDOWN;
	float currentCooldown;

	DialogUI* dialogUI;
	void ShowDialogs(const std::string message) const;
	std::vector<std::string> Dialogs;


	//NPC Sprites
	std::map<std::string, std::string> NPCTextureFiles = {
	 {"Fox", "Assets/Images/Character/Fox1.png"},
	 {"Fox1", "Assets/Images/Character/Fox2.png"},
	};

	void LoadCharacterTextures();

	std::map<std::string, sf::Texture> NPCTextures;
	std::map<std::string, std::unique_ptr<sf::Sprite>> NPCSprites;

	float walkFrameTimer;
	float walkFrameDuration;
	bool isWalkFrame1;

	NPCTypes NPCType;
};
