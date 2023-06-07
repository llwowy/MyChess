#include "King.h"


//King::King(const std::string& _id, const std::vector<BoardTile*> board, std::string color_) : Piece(_id) {
//	auto it = std::find_if(board.begin(), board.end(), [_id](BoardTile* Tile) {
//		return Tile->get_Tile_id() == _id; });
//	setPosition((*it)->get_Tile_position());
//	color = color_;
//	Create_King();
//}

void King::Create_King() {
	if (Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "king";
	}
	std::cout << "\n" << "stworzono King o kolorze:" << color << std::endl;
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(16, 64, 16, 16));
	setScale(7, 7);
}

std::string King::GetColorr() {
	return color;
}