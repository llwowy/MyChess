#include "Bishop.h"


//Bishop::Bishop(const std::string& _id, const std::vector<BoardTile*> board, std::string color_) : Piece(_id) {
//	auto it = std::find_if(board.begin(), board.end(), [_id](BoardTile* Tile) {
//		return Tile->get_Tile_id() == _id; });
//	setPosition((*it)->get_Tile_position());
//	color = color_;
//	Create_Bishop();
//}

void Bishop::Create_Bishop() {
	if (Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "bishop";
	}
	std::cout << "\n" << "stworzono Bishopa o kolorze:" << color << std::endl;
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(16, 48, 16, 16));
	setScale(7, 7);
}

std::string Bishop::GetColorr() {
	return color;
}