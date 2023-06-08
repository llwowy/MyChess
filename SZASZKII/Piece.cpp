#include "Piece.h"



Piece::Piece(const std::string _id, Piece_colors _color) : Piece_id(_id), Piece_color(_color){
	std::cout << "piece\n";
}

std::string Piece::get_Piece_id() { return Piece_id; }

Piece_colors Piece::get_Piece_color() { return Piece_color; };

bool Piece::get_is_selected() { return is_selected; }

sf::Vector2f Piece::get_Starting_Piece_pos() { return Starting_Piece_pos; }

void Piece::set_Piece(const std::vector<BoardTile*> board, std::string Tile_id) {
	auto it = std::find_if(board.begin(), board.end(), [Tile_id](BoardTile* Tile) {
		return Tile->get_Tile_id() == Tile_id; });
	setPosition((*it)->get_Tile_position());
}

void  Piece::select() {
	is_selected = true;
}

void  Piece::unselect() {
	is_selected = false;
}

void Piece::chosen(const sf::Vector2i& mouse_position) {
	sf::FloatRect rectangle_bounds = getGlobalBounds();
	if (rectangle_bounds.left <= mouse_position.x && rectangle_bounds.left + rectangle_bounds.width >= mouse_position.x &&
		rectangle_bounds.top <= mouse_position.y && rectangle_bounds.top + rectangle_bounds.height >= mouse_position.y) {
		select();
		Starting_Piece_pos = getPosition();
	}
}

void Piece::unchosen(const sf::Vector2i& mouse_position) {
	unselect();
}



void Piece::Pick_up(const sf::Vector2i& mouse_position) {
	if (is_selected) {
		setPosition(mouse_position.x - 56, mouse_position.y - 56);

	}
}

void Piece::Landing(std::vector<BoardTile*> board, const sf::Vector2i& mouse_position) {
	if (is_selected) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y); });
		if (it != board.end()) {
			setPosition((*it)->get_Tile_position());
		}
		else {
			setPosition(Starting_Piece_pos);
		}
	}
}