#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "BoardTile.h"
#include <algorithm>



class Piece : public sf::RectangleShape
{
private:

	sf::Texture Piece_texture;
	sf::Vector2f Piece_position;
	sf::Vector2f Piece_size;
	std::string Piece_id;
	sf::Sprite Piece_sprite;

public:
	
	Piece(const double& x_pos, const double& y_pos, const std::string& _Piece_id);
	Piece();
	sf::Vector2f get_Piece_position();
	std::string get_Piece_id();
	sf::Texture get_Piece_texture();
	sf::Sprite get_Piece_sprite();
	virtual void set_Piece();
	virtual void move();
	
	
};

