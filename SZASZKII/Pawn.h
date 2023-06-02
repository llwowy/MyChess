#pragma once
#include "Piece.h"
class Pawn : public Piece
{
private:
	//jak atrybuty maj¹ byæ w publicu to trzeba do wszysrkiego zrobic gettery i settery

public:
	Pawn(const std::string& _id, const std::vector<BoardTile*> board);
	void Create_pawn();
	void First_pawns();
};

