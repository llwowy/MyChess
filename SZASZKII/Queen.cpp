#include "Queen.h"

Queen::Queen(const std::string& _id, std::vector<BoardTile*>& board) : Piece(_id) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupapawn";
	}
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(16, 80, 16, 16));
	setScale(7, 7);
}

//void Queen::Create_Queen() {
//	if (Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
//		std::cout << "queen";
//	}
//	std::cout << "\n" << "stworzono Queen o kolorze:" << color << std::endl;
//	setTexture(Piece_texture);
//	setTextureRect(sf::IntRect(16, 80, 16, 16));
//	setScale(7, 7);
//}
//
//std::string Queen::GetColorr() {
//	return color;
//}