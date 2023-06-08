#include "King.h"


King::King(const std::string& _id, std::string _color, std::vector<BoardTile*>& board) : Piece(_id, _color) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupapawn";
	}
	setTexture(Piece_texture);
	if (_color == "B") { setTextureRect(sf::IntRect(16, 64, 16, 16)); }	//zmiany kolorów zale¿nie od Pawn_color
	if (_color == "G") { setTextureRect(sf::IntRect(95, 64, 16, 16)); }
	if (_color == "Wh") { setTextureRect(sf::IntRect(16, 160, 16, 16)); }
	if (_color == "Bl") { setTextureRect(sf::IntRect(96, 160, 16, 16)); }
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