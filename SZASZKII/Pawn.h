#pragma once
#include "Piece.h"
#include "Board.h"
class Pawn : public Piece
{
private:

public:

	Pawn(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board, bool BandW, bool GandB);
	void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
	bool collider_for_Black(std::vector<Piece*>& PawnsVec, sf::Vector2f selected_Tile_pos);
	void take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
	bool take_Left_collider_for_Black(std::vector<Piece*>& PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_Right_collider_for_Black(std::vector<Piece*>& PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_Left_collider_for_White(std::vector<Piece*>& PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_Right_collider_for_White(std::vector<Piece*>& PawnsVec, sf::Vector2f selected_Tile_pos);
	void mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec);
	void dance(int counter) override;
	~Pawn() {};
};

