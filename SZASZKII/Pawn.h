#pragma once
#include "Piece.h"
class Pawn : public Piece
{
private:


public:

	Pawn(const std::string& _id, const std::vector<BoardTile*> board);
	void Create_white_pawn(Pawn());
	void Create_black_pawn();
	
};

