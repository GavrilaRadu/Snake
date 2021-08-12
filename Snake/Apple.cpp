#include "Apple.h"

apple::apple()
{
	if (!this->texturaMar.loadFromFile("images/AppleBaby.png"))
		std::cout << "EROARE MAR !!!";
}

apple::~apple()
{
}

sf::Sprite apple::GetSprite()
{
	return this->spriteMar;
}

point apple::GetLocation()
{
	return this->locatie;
}

//TODO: Verify if apple is spawned ON the snake
void apple::PlaceApple()
{
	this->locatie.y = rand() % 30;
	this->locatie.x = rand() % 20;

	this->spriteMar.setTexture(this->texturaMar);
	this->spriteMar.setPosition(this->locatie.y * 16, this->locatie.x * 16);
}