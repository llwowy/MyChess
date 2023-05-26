#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>


class BoardTile : public sf::RectangleShape
{
private:

	sf::Vector2f Tile_size;
	sf::Vector2f Tile_position;
	sf::Color Tile_color;
	std::string Tile_id;

public:
	sf::Vector2f get_Tile_size();
	sf::Vector2f get_Tile_position();
	sf::Color get_Tile_color();
	std::string get_Tile_id();
	BoardTile(const double& x_pos, const double& y_pos, const sf::Color& _Tile_color, const std::string& _Tile_id);
	void setTile();
};



