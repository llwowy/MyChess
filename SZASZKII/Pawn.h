#pragma once
#include "Piece.h"
#include "Board.h"
class Pawn : public Piece
{
private:


public:
	//Pawn(const std::string& _id, const std::vector<BoardTile*> board);
	Pawn(const std::string& _id, sf::Vector2f pos);
	void Create_white_pawn();
	void Create_black_pawn();
	
};

