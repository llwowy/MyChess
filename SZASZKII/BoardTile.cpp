#include "BoardTile.h"
sf::Vector2f BoardTile::get_Tile_size() { return Tile_size; }
sf::Vector2f BoardTile::get_Tile_position() { return Tile_position; }
std::string BoardTile::get_Tile_id() { return Tile_id; }


BoardTile::BoardTile(const double& x_pos, const double& y_pos, const std::string& _Tile_id) :
	Tile_position(x_pos, y_pos), Tile_size(15 * 7, 15 * 7), Tile_id(_Tile_id) {}

void BoardTile::setTile()
{
	setPosition(Tile_position);
	setSize(Tile_size);
}

bool BoardTile::get_Tile_marked_for_White() { return Tile_marked_for_White; }

bool BoardTile::get_Tile_marked_for_Black() { return Tile_marked_for_Black; }

void BoardTile::set_Tile_marked_for_White(bool b) {
	Tile_marked_for_White = b;
}

void BoardTile::set_Tile_marked_for_Black(bool b) {
	Tile_marked_for_Black = b;
}
