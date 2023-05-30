#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Piece : public sf::RectangleShape
{
private:
	sf::Vector2f Piece_position;
	sf::Vector2f Piece_size;
	std::string Piece_id;
public:
	Piece(const double& x_pos, const double& y_pos, const std::string& _Tile_id);
	virtual sf::Vector2f get_Piece_position();
	virtual std::string get_Piece_id();
};

