#pragma once
#include "Piece.h"
class King : public Piece
{
private:
	//std::string color;//mo¿e lepiej jak dodamy kolor jako atrybut

public:
	King(const std::string& _id, std::string _color, std::vector<BoardTile*>& board);
	//void Create_King();
	//std::string GetColorr(); // i wtedy getter do koloru
};