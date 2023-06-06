#include "Rook.h"

//Rook::Rook(const std::string& _id, const std::vector<BoardTile*> board, std::string color_) : Piece(_id) {
//	auto it = std::find_if(board.begin(), board.end(), [_id](BoardTile* Tile) {
//		return Tile->get_Tile_id() == _id; });
//	setPosition((*it)->get_Tile_position());
//	color = color_;
//	Create_Rook();
//}

void Rook::Create_Rook() {
	if (Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "rook";
	}
	std::cout << "\n" << "stworzono Rooka o kolorze:" << color << std::endl;
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(16, 16, 16, 16));
	setScale(7, 7);
}