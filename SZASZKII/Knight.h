#pragma once
#include "Piece.h"
class Knight : public Piece
{
private:
	std::string color;//mo¿e lepiej jak dodamy kolor jako atrybut

public:
	//Knight(const std::string& _id, const std::vector<BoardTile*> board, std::string color_);
	void Create_Knight();
};

