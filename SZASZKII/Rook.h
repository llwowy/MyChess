#pragma once
#include "Piece.h"
#include "Board.h"

class Rook : public Piece
{
private:
	//std::string color;//mo¿e lepiej jak dodamy kolor jako atrybut

public:
	Rook(const std::string& _id, std::vector<BoardTile*>& board);
	//void Create_Rook();
};