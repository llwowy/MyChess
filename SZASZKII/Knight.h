#pragma once
#include "Piece.h"
class Knight : public Piece
{
private:
	std::string color;//mo¿e lepiej jak dodamy kolor jako atrybut

public:
	Knight(const std::string& _id, std::string _color, std::vector<BoardTile*>& board);
	//void Create_Knight();
};

