#include "Pawn.h"

Pawn::Pawn(const std::string& _id, const std::vector<BoardTile*> board) : Piece(_id){
	auto it = std::find_if(board.begin(), board.end(), [_id](BoardTile* Tile) {
		return Tile->get_Tile_id() == _id; });
	setPosition((*it)->get_Tile_position());
	Create_black_pawn();
}

void Pawn::Create_white_pawn(Pawn()) {
	if (Piece_texture.loadFromFile("")) {
		std::cout << "dupa";
	}
	setTexture(Piece_texture);
}

void Pawn::Create_black_pawn() {
	if (Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupa";
	}
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(0, 0, 16, 16));
	setScale(7,7);
}



