#pragma once
#include "Piece.h"
#include "Board.h"
class Pawn : public Piece
{
private:


public:

	//Pawn(const std::string& _id, const std::vector<BoardTile*> board);
	Pawn(const std::string& _id, std::string _color, std::vector<BoardTile*>& board);
//	void Create_white_pawn();
//	void Create_black_pawn();
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position);
};

