#pragma once
#include "Piece.h"
class King : public Piece
{
private:

public:
	King(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board, bool BandW, bool GandB);
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec);
	bool collider(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	void mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec);
	bool right_castling_condition(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec);
	bool left_castling_condition(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec);
	bool possible_move(const sf::Vector2f& Tile_pos, std::vector<Piece*>& _PawnsVec);
	void dance(int &counter) override;
	~King() {};
};