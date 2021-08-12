#pragma once

#include "General.h"

class apple
{
public:
	apple();
	~apple();
	
	sf::Sprite GetSprite();
	point GetLocation();
	sf::Vector2f GetPosition();

	void PlaceApple();

private:
	point locatie;

	sf::Texture texturaMar;
	sf::Sprite spriteMar;
};