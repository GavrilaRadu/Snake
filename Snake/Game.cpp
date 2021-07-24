#include "Game.h"

std::string convert_int_string(int nrInt)
{
    std::string nrString(10, 'x');

    int clona, putere = 1, i = 0;
    clona = nrInt;

    if (nrInt == 0) {
        nrString = "0";
        nrString.shrink_to_fit();
    }
    else {
        while (clona != 0) {                              //Aflu cate cifre are numarul nostru (cate elemente
            putere = putere * 10;                       //va avea sirul de caractere)
            clona = clona / 10;
        }
        putere = putere / 10;                           //Vrem ca "putere" sa aiba acelasi nr de cifre ca x, nu cu una mai mult.
        while (putere != 0) {
            nrString[i] = (nrInt / putere) % 10 + 48;          //Iau cifra cu cifra si o adaug in sirul de caractere transformata in char
            i++;                                        //(char)48 = "0"
            putere = putere / 10;
        }
    }
    nrString.resize(i);
    nrString.shrink_to_fit();
    return nrString;
}

Game::Game()
{
}

Game::~Game()
{
}

std::string Game::GetTime()
{
    sf::Time elapsed = this->clock.getElapsedTime();
    
    return convert_int_string(elapsed.asSeconds());
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

void Game::Run()
{
    int i, j, board[30][20], scor = 0;
    char whereToGo = 'r';

    for (i = 0; i < 30; i++)
        for (j = 0; j < 20; j++)
            board[i][j] = 0;

    snake sarpe;
    sarpe.PlaceSnake(board);

    apple mar;
    mar.PlaceApple(board);

    sf::RenderWindow window(sf::VideoMode(700, 320), "Snake");
    sf::Texture texture;

    sf::Sprite sprite, spriteTimer, spriteScore;

    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text time;
    time.setFont(font);
    time.setCharacterSize(32);
    time.setFillColor(sf::Color::Black);
    time.setPosition(572, 102);

    sf::Text afiScor;
    afiScor.setFont(font);
    afiScor.setCharacterSize(32);
    afiScor.setFillColor(sf::Color::Black);
    afiScor.setPosition(630, 245);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (i = 0; i < 30; i++)
            for (j = 0; j < 20; j++) {
                switch (board[i][j])
                {
                case 0:
                    if (!texture.loadFromFile("images/Background.png"))
                        return;
                    break;
                case 1:
                    if (!texture.loadFromFile("images/AppleBaby.png"))
                        return;
                    break;
                case 2:
                    if (!texture.loadFromFile("images/Head.png"))
                        return;
                    break;
                default:
                    if (!texture.loadFromFile("images/Body.png"))
                        return;
                    break;
                }

                sprite.setTexture(texture);
                sprite.setPosition(i * 16, j * 16);
                window.draw(sprite);
            }

        if (!texture.loadFromFile("images/timer.png"))
            return;
        spriteTimer.setTexture(texture);
        spriteTimer.setPosition(30 * 16, 0);
        window.draw(spriteTimer);

        if (!texture.loadFromFile("images/score.png"))
            return;
        spriteScore.setTexture(texture);
        spriteScore.setPosition(30 * 16, 220);
        window.draw(spriteScore);

        time.setString(this->GetTime());
        window.draw(time);

        afiScor.setString(convert_int_string(scor));
        window.draw(afiScor);

        VerifyIfKeyIsPressed(whereToGo);

        if (sarpe.Move(board, scor, whereToGo) == true)
            mar.PlaceApple(board);

        window.display();
    }
}
