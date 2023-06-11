#include "Rook.h"
#include "Board.h"

Rook::Rook(const std::string& _id, const Piece_colors _color, std::vector<BoardTile*>& board) : Piece(_id, _color) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "duparook";
	}
	setTexture(Piece_texture);
	if (_color == Blue) { setTextureRect(sf::IntRect(16, 16, 16, 16)); }	//zmiany kolorów zale¿nie od Pawn_color
	if (_color == Green) { setTextureRect(sf::IntRect(95, 16, 16, 16)); }
	if (_color == White) { setTextureRect(sf::IntRect(16, 112, 16, 16)); }
	if (_color == Black) { setTextureRect(sf::IntRect(96, 112, 16, 16)); }
	setScale(7, 7);
}

void Rook::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y);
			});

		if (it != board.end() && collider_for_Rook(_PawnsVec, (*it)->get_Tile_position()) && (
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -2 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -3 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -4 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -5 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -6 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -7 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 2 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 3 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 4 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 5 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 6 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 7 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, 0) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, 0)
			)) {
			setPosition((*it)->get_Tile_position());
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}


void Rook::take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y); });
		if (it != board.end()) {
			if (get_Piece_color() == Black && take_collider_for_BlackRook(_PawnsVec, (*it)->get_Tile_position())) {
				setPosition((*it)->get_Tile_position());
			}
			if (get_Piece_color() == White && take_collider_for_WhiteRook(_PawnsVec, (*it)->get_Tile_position())) {
				setPosition((*it)->get_Tile_position());
			}
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}

