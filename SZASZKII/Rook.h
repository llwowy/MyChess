#pragma once
#include "Piece.h"
#include "Board.h"

class Rook : public Piece
{
private:
	

public:
	Rook(const std::string& _id, const Piece_colors _color, std::vector<BoardTile*>& board);
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
};