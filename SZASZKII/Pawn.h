#pragma once
#include "Piece.h"
class Pawn : public Piece
{
private:

public:

	//Pawn(const double& x_pos, const double& y_pos, const std::string& _Piece_id);
	Pawn();

	void Create_white_pawn(Pawn());
	void Create_black_pawn();
	void set_Piece(std::vector<BoardTile*>, std::string Tile_id);

};

