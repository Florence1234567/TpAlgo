//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Base/Character.h"
#include <iostream>

class PlayerCharacter : public Character {
public:
	PlayerCharacter(int x, int y, float size, float baseSpeed, float hp) : Character(x, y, size, baseSpeed, hp, "Images/Character/C_Front.png") {
		LoadCharacterTextures();
		currentDir = Direction::Down;
		walkFrameTimer = 0;
		walkFrameDuration = 1;
		isWalkFrame1 = true;
		speed = baseSpeed;
	};

	void Update(sf::Time dt) override;
    void UpdateSprite(sf::Time dt);
private:
    //Character Sprites
	std::map<std::string, std::string> characterTextureFiles = {
	 {"Back", "Images/Character/C_Back.png"},
	 {"BackJump", "Images/Character/C_BackJump.png"},
	 {"BackWalk1", "Images/Character/C_BackWalk1.png"},
	 {"BackWalk2", "Images/Character/C_BackWalk2.png"},
	 {"Front", "Images/Character/C_Front.png"},
	 {"FrontWalk1", "Images/Character/C_FrontWalk1.png"},
	 {"FrontWalk2", "Images/Character/C_FrontWalk2.png"},
	 {"Jump", "Images/Character/C_Jump.png"},
	 {"Left", "Images/Character/C_Left.png"},
     {"LeftWalk1", "Images/Character/C_LeftWalking1.png"},
	 {"LeftWalk2", "Images/Character/C_LeftWalking2.png"},
	 {"Right", "Images/Character/C_Right.png"},
	 {"RightWalk1", "Images/Character/C_RightWalking1.png"},
	 {"RightWalk2", "Images/Character/C_RightWalking2.png"}
	};

	void LoadCharacterTextures();

    std::map<std::string, sf::Texture> characterTextures;
    std::map<std::string, std::unique_ptr<sf::Sprite>> characterSprites;
	
	float walkFrameTimer;
	float walkFrameDuration;
	bool isWalkFrame1;
};
