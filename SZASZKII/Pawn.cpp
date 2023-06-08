
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

void::Pawn::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y); });

		if (it != board.end() &&  (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0,112)) {
			setPosition((*it)->get_Tile_position());
		}
		else if (it != board.end() && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 224) && ((*it)->get_Tile_id() == "a5" ||
			(*it)->get_Tile_id() == "b5" || (*it)->get_Tile_id() == "c5" || (*it)->get_Tile_id() == "d5" || (*it)->get_Tile_id() == "e5" ||
			(*it)->get_Tile_id() == "f5" || (*it)->get_Tile_id() == "g5" || (*it)->get_Tile_id() == "h5")) {
			setPosition((*it)->get_Tile_position());
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}





