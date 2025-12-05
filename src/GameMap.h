#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <map>
#include "Character.h"

enum Tile {
	EdgeUpLeft, EdgeUp, EdgeUpRight,
	EdgeLeft, Grass, EdgeRight,
	EdgeDownLeft, EdgeDown, EdgeDownRight
};

class GameMap
{
public:
	GameMap(int width, int height);

	void Display(sf::RenderWindow& window, Character* character);

	int GetWidth() { return Width; };
	int GetHeight() { return Height; };

private:
	int Width;
	int Height;
	static const int PixelsPerSquare = 64;

	Tile DecideTile(int x, int y);

	std::vector<std::vector<Tile>> map;

	std::map<Tile, std::string> textureFiles = {
		{EdgeUpLeft, "Images/Ground/E_UL.png"},
		{EdgeUp, "Images/Ground/E_U.png"},
		{EdgeUpRight, "Images/Ground/E_UR.png"},
		{EdgeLeft, "Images/Ground/E_L.png"},
		{Grass, "Images/Ground/Grass.png"},
		{EdgeRight, "Images/Ground/E_R.png"},
		{EdgeDownLeft, "Images/Ground/E_DL.png"},
		{EdgeDown, "Images/Ground/E_D.png"},
		{EdgeDownRight, "Images/Ground/E_DR.png"}
	};

	std::map<Tile, sf::Texture> textures;
	std::map<Tile, std::unique_ptr<sf::Sprite>> sprites;

	//Character
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
	std::map<std::string, std::unique_ptr<sf::Sprite>> characterSprites;

	std::string GetCharacterSpriteName(Character* Character);
};