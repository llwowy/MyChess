#pragma once
#include "Piece.h"
class Bishop : public Piece
{
private:
	

public:
	Bishop(const std::string& _id, const Piece_colors _color, std::vector<BoardTile*>& board);
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position);
	//void Create_Bishop();
	//std::string GetColorr(); // i wtedy getter do koloru
};