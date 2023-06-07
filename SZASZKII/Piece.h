#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include "BoardTile.h"



class Piece : public sf::Sprite
{
private:
	std::string Piece_id;
protected:
	//std::map <std::string, sf::Vector2f > plansza{ {"a1", }}; chuj wie gówno cipsko
	sf::Texture Piece_texture;
public:
	Piece(const std::string _id);
	std::string get_Piece_id();
	virtual void set_Piece();
	sf::Vector2f position; // pozycja ka¿dego pionka
	//bool first_generate; // do pierwszego ustawienia pionków
};

