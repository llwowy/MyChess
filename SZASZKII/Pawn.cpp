#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(const std::string& _id, std::vector<BoardTile*>& board) : Piece(_id){
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupa";
	}
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(0, 0, 16, 16));
	setScale(7,7);
}
void Pawn::Create_white_pawn() {
	if (Piece_texture.loadFromFile("")) {
		std::cout << "dupa";
	}
	setTexture(Piece_texture);
}

void Pawn::set_Piece(const std::vector<BoardTile*> board, std::string Tile_id) {
	auto it = std::find_if(board.begin(), board.end(), [Tile_id](BoardTile* Tile) {
		return Tile->get_Tile_id() == Tile_id; });
	setPosition((*it)->get_Tile_position());
}

//void Pawn::Create_black_pawn() {
//	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
//		std::cout << "dupa";
//	}
//	setTexture(Piece_texture);
//	setTextureRect(sf::IntRect(0, 0, 16, 16));
//	setScale(7, 7);
//}



