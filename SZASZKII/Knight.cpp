
#include "Knight.h"
#include "Board.h"

Knight::Knight(const std::string& _id, std::string _color, std::vector<BoardTile*>& board) : Piece(_id, _color) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupaknight";
	}
	setTexture(Piece_texture);
	if (_color == "B") { setTextureRect(sf::IntRect(16, 32, 16, 16)); }	//zmiany kolorów zale¿nie od Pawn_color
	if (_color == "G") { setTextureRect(sf::IntRect(95, 32, 16, 16)); } 
	if (_color == "Wh") { setTextureRect(sf::IntRect(16, 128, 16, 16)); }
	if (_color == "Bl") { setTextureRect(sf::IntRect(96, 128, 16, 16)); }
	setScale(7, 7);

	//auto it = std::find_if(board.begin(), board.end(), [_id](BoardTile* Tile) {
	//	return Tile->get_Tile_id() == _id; });
	//setPosition((*it)->get_Tile_position());
	//color = color_;
	//Create_Knight();
}

//void Knight::Create_Knight() {
//	if (Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
//		std::cout << "knight";
//	}
//	std::cout << "\n" << "stworzono Knighta o kolorze:" << color << std::endl;
//	setTexture(Piece_texture);
//	setTextureRect(sf::IntRect(16, 32, 16, 16));
//	setScale(7, 7);
//}