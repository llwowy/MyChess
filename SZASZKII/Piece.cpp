
#include "Piece.h"

Piece::Piece(const std::string _id) : Piece_id(_id) {
	std::cout << "chuj";
}
std::string Piece::get_Piece_id() { return Piece_id; }

void Piece::set_Piece(const std::vector<BoardTile*> board, std::string Tile_id) {
	auto it = std::find_if(board.begin(), board.end(), [Tile_id](BoardTile* Tile) {
		return Tile->get_Tile_id() == Tile_id; });
	setPosition((*it)->get_Tile_position());
}

void::Piece::select() {
	is_selected = true;
}

void::Piece::unselect() {
	is_selected = false;
}

void Piece::chosen(const sf::Vector2i& mouse_position) {
	sf::FloatRect rectangle_bounds = getGlobalBounds();
	if (rectangle_bounds.left <= mouse_position.x && rectangle_bounds.left + rectangle_bounds.width >= mouse_position.x &&
		rectangle_bounds.top <= mouse_position.y && rectangle_bounds.top + rectangle_bounds.height >= mouse_position.y) {
		select();
	}
}

void::Piece::unchosen(const sf::Vector2i& mouse_position) {
	unselect();
}



void::Piece::Pick_up(const sf::Vector2i& mouse_position) {
	if (is_selected) {
		setPosition(mouse_position.x - 56, mouse_position.y - 56);

	}
}