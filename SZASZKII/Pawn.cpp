#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(const std::string& _id, sf::Vector2f pos) : Piece(_id){
	/*auto it = std::find_if(board.BoardVec.begin(), board.BoardVec.end(), [_id](BoardTile* Tile) {
		return Tile->get_Tile_id() == _id; });*/
	setPosition(pos);
	//Create_black_pawn();
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

//void Pawn::Create_black_pawn() {
//	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
//		std::cout << "dupa";
//	}
//	setTexture(Piece_texture);
//	setTextureRect(sf::IntRect(0, 0, 16, 16));
//	setScale(7, 7);
//}



