#pragma once
#include "Piece.h"
class Bishop : public Piece
{
private:
	

public:
	Bishop(const std::string& _id, const Piece_colors _color, std::vector<BoardTile*>& board);
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
	void take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
	bool collider(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos);
	//std::string GetColorr(); // i wtedy getter do koloru
};