#pragma once

#include "General.h"
#include "Snake.h"
#include "Apple.h"

class Game
{
public:
	Game();
	~Game();

	std::string GetTime();

	void VerifyIfKeyIsPressed(char& whereToGo);
	
	void DrawBMT(sf::RenderWindow *window);

	void MakeBackground();
	void MakeTimer();
	void MakeScore();
	
	void VerifyApplePlacement();
	void GrowSnake(int& score);

	void Run();

private:
	snake sarpe;
	apple mar;

	sf::Clock clock;

	sf::Texture texturaBackground;
	sf::RectangleShape background;

	sf::Font font;

	sf::Texture texturaTimer;
	sf::Sprite spriteTimer;
	sf::Text time;

	sf::Texture texturaScore;
	sf::Sprite spriteScore;
	sf::Text afiScor;
};

std::string convert_int_string(int nrInt);