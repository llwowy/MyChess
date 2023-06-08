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
void::King::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y);
			});

		if (it != board.end() && (
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 0 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 0 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0 * 112, -1 * 112)
			
			)) {
			setPosition((*it)->get_Tile_position());
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}