#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

enum Background {
	P_UL, P_U, P_UR,
	P_L, Middle, P_R,
	P_DL, P_D, P_DR
};

class PlayerUI {
public: 
	virtual ~PlayerUI() = default;

	virtual void Draw(sf::RenderWindow& window);
	virtual void Update(sf::Time dt);

protected:
	PlayerUI(float width, float height, std::string titleText, float margin = 20, float rightPadding = 320);

	void BuildBackground();

	float panelWidth;
	float panelHeight;
	float margin;
	float rightPadding;
	static const int PixelsPerSquare = 64;

	std::vector<std::vector<Background>> backgroundMap;

	std::map<Background, std::string> backgroundTextureFiles = {
		{ P_UL, "Images/Panel/P_UL.png" },
	    { P_U, "Images/Panel/P_U.png" },
		{ P_UR, "Images/Panel/P_UR.png" },
		{ P_L, "Images/Panel/P_L.png" },
		{ Middle, "Images/Panel/Middle.png" },
		{ P_R, "Images/Panel/P_R.png" },
		{ P_DL, "Images/Panel/P_DL.png" },
		{ P_D, "Images/Panel/P_D.png" },
		{ P_DR, "Images/Panel/P_DR.png" }
	};

	std::map<Background, sf::Texture> backgoundTextures;
	std::map<Background, std::unique_ptr<sf::Sprite>> backgroundSprites;

	sf::RectangleShape background;
	sf::Font font;
	sf::Text title;
};