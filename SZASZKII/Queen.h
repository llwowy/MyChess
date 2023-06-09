#pragma once
#include "Piece.h"
class Queen : public Piece
{
private:
	

public:
	Queen(const std::string& _id, const Piece_colors _color, std::vector<BoardTile*>& board);
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
};