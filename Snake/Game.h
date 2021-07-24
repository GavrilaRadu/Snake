#pragma once

#include <SFML/Graphics.hpp>
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
	void Run();

private:
	sf::Clock clock;
};

std::string convert_int_string(int nrInt);