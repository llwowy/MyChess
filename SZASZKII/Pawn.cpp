#include "Pawn.h"

Pawn::Pawn(const std::string& _id, const std::vector<BoardTile*> board) : Piece(_id){
	auto it = std::find_if(board.begin(), board.end(), [_id](BoardTile* Tile) {
		return Tile->get_Tile_id() == _id; });
	setPosition((*it)->get_Tile_position());
	Create_pawn();
}

void Pawn::Create_pawn() {
	if (Piece_texture.loadFromFile("Grafika/ChessTextures/ChessPieces.png")) {
		std::cout << "dupa";
	}
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(0, 0, 15, 16));
	setScale(7, 7);
}

void Pawn::First_pawns() {


}

