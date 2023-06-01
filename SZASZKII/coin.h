#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class coin : public sf::Sprite
{
public:
    coin(sf::Vector2f posyzcja);
    ~coin();
    void update(); // metoda nazwana tak aby byla spojnosc , wywoluje wylacznie metode animate
private:
    void animate(); // animacja
    sf::Texture tekstura; // teksutra 
    sf::Clock clock; // zegar uzywany do animacji 
};
