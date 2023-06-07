
#pragma once
#include "Piece.h"
class Rook : public Piece
{
private:
	std::string color;//mo¿e lepiej jak dodamy kolor jako atrybut

public:
	//Rook(const std::string& _id, const std::vector<BoardTile*> board, std::string color_);
	void Create_Rook();
};