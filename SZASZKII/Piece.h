#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "BoardTile.h"
#include <algorithm>



class Piece : public sf::Sprite
{
private:

	std::string Piece_id;
	
protected:

	sf::Texture Piece_texture;

public:

	Piece(const std::string& _id);
	std::string get_Piece_id();
	virtual void set_Piece();
	
	
};

