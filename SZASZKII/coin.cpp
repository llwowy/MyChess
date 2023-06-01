#include "coin.h"

coin::coin(sf::Vector2f pozycja)
{
    if (!tekstura.loadFromFile("assets/coin_gold.png"))
    {
        std::cout << "Nie za³adowano grafiki monety" << std::endl;
    }
    std::cout << "Tworze monete" << std::endl;
    setTexture(tekstura);
    setTextureRect(sf::IntRect(96, 0, 32, 20));
    setPosition(pozycja);
    setScale(2, 2);
}

coin::~coin()
{
    std::cout << "Usuwam monete" << std::endl;
}

void coin::update() // funkcja update wywolujaca animacje 
{
    this->animate();
}

void coin::animate() // animacja na podstawie uplynietego czasu 
{
    if (clock.getElapsedTime().asSeconds() < 0.15)
        setTextureRect(sf::IntRect(0, 0, 32, 20));
    else if (clock.getElapsedTime().asSeconds() < 0.3)
        setTextureRect(sf::IntRect(32, 0, 32, 20));
    else if (clock.getElapsedTime().asSeconds() < 0.45)
        setTextureRect(sf::IntRect(64, 0, 32, 20));
    else if (clock.getElapsedTime().asSeconds() < 0.6)
        setTextureRect(sf::IntRect(96, 0, 32, 20));
    else if (clock.getElapsedTime().asSeconds() < 0.75)
        setTextureRect(sf::IntRect(128, 0, 32, 20));
    else if (clock.getElapsedTime().asSeconds() < 0.9)
        setTextureRect(sf::IntRect(160, 0, 32, 20));
    else if (clock.getElapsedTime().asSeconds() < 1.05)
        setTextureRect(sf::IntRect(192, 0, 32, 20));
    else if (clock.getElapsedTime().asSeconds() < 1.2)
        setTextureRect(sf::IntRect(224, 0, 32, 20));
    else if (clock.getElapsedTime().asSeconds() > 1.2)
        clock.restart();
}