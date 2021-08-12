#include "Game.h"

Game::Game()
{
    this->MakeBackground();
    
    this->font.loadFromFile("arial.ttf");
}

Game::~Game()
{
}

std::string Game::GetTime()
{
    sf::Time elapsed = this->clock.getElapsedTime();

    char timeString[33];
    _itoa_s(elapsed.asSeconds(), timeString, 10);
    
    return timeString;
}

void Game::VerifyIfKeyIsPressed(char& whereToGo)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (whereToGo != 'l')
            whereToGo = 'r';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (whereToGo != 'u')
            whereToGo = 'd';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (whereToGo != 'r')
            whereToGo = 'l';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (whereToGo != 'd')
            whereToGo = 'u';
    }
}

void Game::DrawBMT(sf::RenderWindow* window)
{
    //Background
    window->draw(this->background);

    //Mar
    window->draw(mar.GetSprite());

    //Timer
    window->draw(this->spriteTimer);
    this->time.setString(this->GetTime());
    window->draw(this->time);
}

void Game::MakeBackground()
{
    this->texturaBackground.loadFromFile("images/Background.png");
    this->texturaBackground.setRepeated(true);

    this->background.setTexture(&texturaBackground);
    this->background.setTextureRect(sf::IntRect(0, 0, 480, 320));
    this->background.setSize(sf::Vector2f(480, 320));
}

void Game::MakeTimer()
{
    this->time.setFont(this->font);
    this->time.setCharacterSize(32);
    this->time.setFillColor(sf::Color::Black);
    this->time.setPosition(572, 102);

    if (!this->texturaTimer.loadFromFile("images/timer.png"))
        return;
    this->spriteTimer.setTexture(this->texturaTimer);
    this->spriteTimer.setPosition(30 * 16, 0);
}

void Game::MakeScore()
{

    this->afiScor.setFont(this->font);
    this->afiScor.setCharacterSize(32);
    this->afiScor.setFillColor(sf::Color::Black);
    this->afiScor.setPosition(630, 245);

    if (!this->texturaScore.loadFromFile("images/score.png"))
        return;
    this->spriteScore.setTexture(this->texturaScore);
    this->spriteScore.setPosition(30 * 16, 220);
}

void Game::VerifyApplePlacement()
{
    int length = this->sarpe.GetLength();
    for(int i = -1; i < length; i++)
        if (this->sarpe.GetSnake(i) == this->mar.GetPosition()) {
            this->mar.PlaceApple();
            this->VerifyApplePlacement();
        }
}

void Game::GrowSnake(int& score)
{
    point capSarpe = this->sarpe.GetHead();
    point locatieMar = this->mar.GetLocation();
    if (capSarpe.x == locatieMar.x && capSarpe.y == locatieMar.y) {
        this->sarpe.IncreaseLength();
        score++;
        this->mar.PlaceApple();
        this->VerifyApplePlacement();
    }
}

void Game::Run()
{
    int i, j, scor = 0;
    char scorString[33];
    char whereToGo = 'r';

    this->sarpe.PlaceSnake();
    this->mar.PlaceApple();

    sf::RenderWindow window(sf::VideoMode(700, 320), "Snake");
    sf::Texture texture;

    sf::Sprite sprite, spriteScore;

    this->MakeTimer();

    this->MakeScore();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            VerifyIfKeyIsPressed(whereToGo);
        }

        window.clear();

        this->DrawBMT(&window);
        
        //Scor
        _itoa_s(scor, scorString, 10);
        this->afiScor.setString(scorString);
        window.draw(this->spriteScore);
        window.draw(this->afiScor);

        //Sarpe
        this->sarpe.PrintSnake(&window);
        for (int i = 0; i < 30000000; i++); //Pentru a incetini jocul
        this->GrowSnake(scor);
        this->sarpe.Move(whereToGo);

        window.display();
    }
}
