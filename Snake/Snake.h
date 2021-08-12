#pragma once

#include "General.h"

class snake
{
public:
	snake();
	~snake();

	void SetHead(point punct);
	void SetTail(point punct);

	point GetHead();
	int GetLength();
	sf::Vector2f GetSnake(int whatPart);

	void PlaceSnake();
	void PrintSnake(sf::RenderWindow *window);
	void Move(char direction);
	void CalculateBody();
	void IncreaseLength();

private:
	struct point head;

	sf::Texture texturaCap;
	sf::Sprite spriteCap;

	sf::Texture texturaCorp;

	sf::Sprite* body = new sf::Sprite[30];

	int maxLength = 30;
	int length = 1;

};