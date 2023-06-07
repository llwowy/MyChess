
#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(const std::string& _id, std::vector<BoardTile*>& board) : Piece(_id) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupapawn";
	}
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(0, 0, 16, 16));
	setScale(7, 7);
}
//void Pawn::Create_white_pawn() {
//	if (Piece_texture.loadFromFile("")) {
//		std::cout << "dupa";
//	}
//	setTexture(Piece_texture);
//}






