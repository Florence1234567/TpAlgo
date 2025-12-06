#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

#include "../UIComponent.h"

enum Background {
	P_UL, P_U, P_UR,
	P_L, Middle, P_R,
	P_DL, P_D, P_DR
};

class PlayerUIComponent : public UIComponent {
public: 
	PlayerUIComponent(float width, float height, std::string titleText, float margin = 20, float rightPadding = 280);
	virtual ~PlayerUIComponent() = default;

	void Draw(sf::RenderWindow& window);
	void Update(sf::Time dt) override;

protected:
	void BuildBackground();

	float margin;
	float rightPadding;
	static const int PixelsPerSquare = 64;

	std::vector<std::vector<Background>> backgroundMap;

	std::map<Background, std::string> backgroundTextureFiles = {
		{ P_UL, "Assets/Images/Panel/P_UL.png" },
	    { P_U, "Assets/Images/Panel/P_U.png" },
		{ P_UR, "Assets/Images/Panel/P_UR.png" },
		{ P_L, "Assets/Images/Panel/P_L.png" },
		{ Middle, "Assets/Images/Panel/Middle.png" },
		{ P_R, "Assets/Images/Panel/P_R.png" },
		{ P_DL, "Assets/Images/Panel/P_DL.png" },
		{ P_D, "Assets/Images/Panel/P_D.png" },
		{ P_DR, "Assets/Images/Panel/P_DR.png" }
	};

	std::map<Background, sf::Texture> backgoundTextures;
	std::map<Background, std::unique_ptr<sf::Sprite>> backgroundSprites;

	sf::RectangleShape background;
	sf::Text title;
};