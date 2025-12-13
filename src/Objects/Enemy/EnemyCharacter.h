//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Character.h"
#include <iostream>
#include <map>

#include "../GameObjects/GameObject.h"

enum EnemyType{
	Chicken,
	Cow
};

class EnemyCharacter : public Character {
public:
	EnemyCharacter(int x, int y, float hp, float damage, float attackSpeed, EnemyType type, std::string name)
		: Character(x, y, 2, 0.f, hp, damage, attackSpeed, name, "Assets/Images/Character/C_Front.png"), ATTACKCOOLDOWN(attackSpeed), currentCooldown(0) {
		LoadCharacterTextures();
		currentDir = Direction::Down;
		walkFrameTimer = 0;
		walkFrameDuration = 1;
		isWalkFrame1 = true;
		speed = baseSpeed;
		enemyType = type;
	};

	void Update(sf::Time dt) override;
	void UpdateSprite(sf::Time dt);

	sf::FloatRect GetCollisionBounds() const;

private:
	std::vector<Item*> inventory;
	const float ATTACKCOOLDOWN;
	float currentCooldown;

	//Enemy Sprites
	std::map<std::string, std::string> enemyTextureFiles = {
	 {"Chick", "Assets/Images/Character/Chick.png"},
	 {"Chick1", "Assets/Images/Character/Chick1.png"},
	 {"Cow", "Assets/Images/Character/Cow.png"},
	 {"Cow1", "Assets/Images/Character/Cow1.png"},
	};

	void LoadCharacterTextures();

	std::map<std::string, sf::Texture> enemyTextures;
	std::map<std::string, std::unique_ptr<sf::Sprite>> enemySprites;

	float walkFrameTimer;
	float walkFrameDuration;
	bool isWalkFrame1;

	EnemyType enemyType;
};
