#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

enum color {black, white};

class Piece : public sf::RectangleShape
{
private:

	sf::Texture Piece_texture;
	sf::Vector2f Piece_position;
	sf::Vector2f Piece_size;
	std::string Piece_id;

public:
	
	Piece(const double& x_pos, const double& y_pos, const std::string& _Piece_id, const sf::Texture& _Piece_Texture);
	sf::Vector2f get_Piece_position();
	std::string get_Piece_id();
	sf::Texture get_Texture();
	
};

