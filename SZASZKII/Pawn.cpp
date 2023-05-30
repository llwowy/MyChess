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

void Pawn::set_Piece(const std::vector<BoardTile*> board, std::string Tile_id) {
	auto it = std::find_if(board.begin(), board.end(), [Tile_id](BoardTile* Tile) {
		return Tile->get_Tile_id() == Tile_id;});
	setPosition((*it)->get_Tile_position());
	setSize((*it)->get_Tile_size());
	get_Piece_sprite().setTexture(get_Piece_texture());
}
