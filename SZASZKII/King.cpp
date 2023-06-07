#include "King.h"


King::King(const std::string& _id, std::vector<BoardTile*>& board) : Piece(_id) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupapawn";
	}
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(16, 64, 16, 16));
	setScale(7, 7);
}
//void King::Create_King() {
//	if (Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
//		std::cout << "king";
//	}
//	std::cout << "\n" << "stworzono King o kolorze:" << color << std::endl;
//	setTexture(Piece_texture);
//	setTextureRect(sf::IntRect(16, 64, 16, 16));
//	setScale(7, 7);
//}
//
//std::string King::GetColorr() {
//	return color;
//}