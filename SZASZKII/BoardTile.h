#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class BoardTile : public sf::RectangleShape
{
private:

	sf::Vector2f Tile_size;
	sf::Vector2f Tile_position;
	std::string Tile_id;
	bool Tile_marked_for_White = false;
	bool Tile_marked_for_Black = false;

public:

	BoardTile(const double& x_pos, const double& y_pos, const std::string& _Tile_id);
	sf::Vector2f get_Tile_size();
	sf::Vector2f get_Tile_position();
	std::string get_Tile_id();
	bool get_Tile_marked_for_White();
	bool get_Tile_marked_for_Black();	

	void set_Tile_marked_for_White(bool b);
	void set_Tile_marked_for_Black(bool b);
	void setTile();

	~BoardTile() {};
};
