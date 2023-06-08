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
	bool is_selected = false;
	sf::Vector2f position;
	sf::Vector2f Starting_Piece_pos;
protected:
	//std::map <std::string, sf::Vector2f > plansza{ {"a1", }}; chuj wie gówno cipsko
	sf::Texture Piece_texture;
public:
	Piece(const std::string _id);
	std::string get_Piece_id();
	void select();
	void unselect();
	virtual void set_Piece(const std::vector<BoardTile*> board, std::string Tile_id);

	//bool first_generate; // do pierwszego ustawienia pionków
	void chosen(const sf::Vector2i& mouse_position);
	void unchosen(const sf::Vector2i& mouse_position);
	void Pick_up(const sf::Vector2i& mouse_position);
	void Landing(std::vector<BoardTile*> board, const sf::Vector2i& mouse_position);
};

