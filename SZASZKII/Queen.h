#pragma once
#include "Piece.h"
class Queen : public Piece
{
private:
	
public:
	Queen(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board, bool BandW, bool GandB);
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec);
	bool collider(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	void take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec);
	bool take_collider_for_Black(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_collider_for_White(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	void mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec);

	~Queen() {};
};