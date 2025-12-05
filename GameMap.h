#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <map>

enum Tile {
	EdgeUpLeft, EdgeUp, EdgeUpRight,
	EdgeLeft, Grass, EdgeRight,
	EdgeDownLeft, EdgeDown, EdgeDownRight
};

enum Direction { Left, Right, Up, Down };

class GameMap
{
public:
	GameMap(const std::string& fileName);

	void Display(sf::RenderWindow& window, Direction characterDir, bool isWalkFrame1);

	int GetWidth() { return Width; };
	int GetHeight() { return Height; };

private:
	static const int Width = 5;
	static const int Height = 5;
	static const int PixelsPerSquare = 64;

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
	 {"Back", "Images/Character/C_Back.png"},
	 {"BackJump", "Images/Character/C_BackJump.png"},
	 {"BackWalk1", "Images/Character/C_BackWalk1.png"},
	 {"BackWalk2", "Images/Character/C_BackWalk2.png"},
	 {"Front", "Images/Character/C_Front.png"},
	 {"FrontWalk1", "Images/Character/C_FrontWalk1.png"},
	 {"FrontWalk2", "Images/Character/C_FrontWalk2.png"},
	 {"Jump", "Images/Character/C_Jump.png"},
	 {"LeftWalk1", "Images/Character/C_Left.png"},
	 {"LeftWalk2", "Images/Character/C_LeftWalking.png"},
	 {"RightWalk", "Images/Character/C_Right.png"},
	 {"RightWalk2", "Images/Character/C_RightWalking.png"}
	};

	std::map<std::string, sf::Texture> characterTextures;
	std::map<std::string, std::unique_ptr<sf::Sprite>> characterSprites;

	std::string GetCharacterSpriteName(Direction dir, bool isWalkFrame1);

	Tile StringToTile(const std::string& value);
};