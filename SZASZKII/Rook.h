#pragma once
#include "Piece.h"
#include "Board.h"

class Rook : public Piece
{
private:
	

public:
	Rook(const std::string& _id, const Piece_colors _color, std::vector<BoardTile*>& board);
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
	bool collider(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	void take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
	bool take_collider_for_Black(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_collider_for_White(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
};