#pragma once
#include "Piece.h"
class King : public Piece
{
private:
	//std::string color;//mo¿e lepiej jak dodamy kolor jako atrybut

public:
	King(const std::string& _id, const Piece_colors _color, std::vector<BoardTile*>& board);
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position);
};