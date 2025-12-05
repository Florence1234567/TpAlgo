//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Base/Character.h"
#include <iostream>


class PlayerCharacter : public Character {
public:
    PlayerCharacter(int x, int y, float size, float baseSpeed, float hp): Character(x, y, size, baseSpeed, hp, "Images/Character/C_Front.png") {};

private:
    /*//Character Sprites
    std::map<std::string, std::string> characterTextureFiles = {
        {"FrontWalk1", "Images/Character/C_FrontWalk1.png"},
        {"FrontWalk2", "Images/Character/C_FrontWalk2.png"},
        {"Jump", "Images/Character/C_Jump.png"},
        {"Left", "Images/Character/C_Left.png"},
        {"LeftWalking", "Images/Character/C_LeftWalking.png"},
        {"Right", "Images/Character/C_Right.png"},
        {"RightWalking", "Images/Character/C_RightWalking.png"}
    };

    std::map<std::string, sf::Texture> characterTextures;
    std::map<std::string, std::unique_ptr<sf::Sprite>> characterSprites;*/
};
