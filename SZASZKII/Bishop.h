#pragma once
#include "Piece.h"
class Bishop : public Piece
{
private:
	std::string color;//mo¿e lepiej jak dodamy kolor jako atrybut

public:
	//Bishop(const std::string& _id, const std::vector<BoardTile*> board, std::string color_);
	void Create_Bishop();
	std::string GetColorr(); // i wtedy getter do koloru
};
