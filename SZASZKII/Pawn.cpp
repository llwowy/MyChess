#include "Pawn.h"

//Pawn::Pawn(const double& x_pos, const double& y_pos, const std::string& _Piece_id) :
//Piece(x_pos, y_pos, _Piece_id) {}

Pawn::Pawn(){}

void Pawn::Create_white_pawn(Pawn()) {
	get_Piece_texture().loadFromFile("");
}

void Pawn::Create_black_pawn() {
	get_Piece_texture().loadFromFile("Grafika/ChessTextures/chessBoardsWithBorder2.png");
}

void Pawn::set_Piece(const BoardTile& tile) {
	setPosition(tile.getPosition());
	setSize(tile.getSize());
	get_Piece_sprite().setTexture(get_Piece_texture());
}
