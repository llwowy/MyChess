#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "BoardTile.h"
#include <algorithm>



class Piece : public sf::Sprite
{
private:
	std::string Piece_id;
protected:
	//std::map <std::string, sf::Vector2f > plansza{ {"a1", }}; chuj wie g�wno cipsko
	sf::Texture Piece_texture;
public:
	Piece(const std::string _id);
	std::string get_Piece_id();
	virtual void set_Piece();
	sf::Vector2f position; // pozycja ka�dego pionka
	//bool first_generate; // do pierwszego ustawienia pionk�w
};

