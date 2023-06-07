	#include "BoardTile.h"
	sf::Vector2f BoardTile::get_Tile_size() { return Tile_size; }
	sf::Vector2f BoardTile::get_Tile_position() { return Tile_position; }
	sf::Color BoardTile::get_Tile_color() { return Tile_color; }
	std::string BoardTile::get_Tile_id() { return Tile_id; }

	BoardTile::BoardTile(const double& x_pos, const double& y_pos, const sf::Color& _Tile_color, const std::string& _Tile_id) :
		Tile_position(x_pos, y_pos), Tile_size(15 * 7, 15 * 7), Tile_color(_Tile_color), Tile_id(_Tile_id) {}

	void BoardTile::setTile()
	{
		setPosition(Tile_position);
		setFillColor(Tile_color);
		setSize(Tile_size);
	}
