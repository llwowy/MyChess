#pragma once
#include "Piece.h"
class King : public Piece
{
private:
	std::string color;//mo¿e lepiej jak dodamy kolor jako atrybut

public:
	King(const std::string& _id, const std::vector<BoardTile*> board, std::string color_);
	void Create_King();
	std::string GetColorr(); // i wtedy getter do koloru
};
