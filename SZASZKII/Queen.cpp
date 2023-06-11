#include "Queen.h"

Queen::Queen(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board) : Piece(_id, _color, _Piece_type) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupapawn";
	}
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(16, 80, 16, 16));
	if (_color == Blue) { setTextureRect(sf::IntRect(16, 80, 16, 16)); }	//zmiany kolor�w zale�nie od Pawn_color
	if (_color == Green) { setTextureRect(sf::IntRect(95, 80, 16, 16)); }
	if (_color == White) { setTextureRect(sf::IntRect(16, 176, 16, 16)); }
	if (_color == Black) { setTextureRect(sf::IntRect(96, 176, 16, 16)); }
	setScale(7, 7);
}

void::Queen::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y);
			});

		if (it != board.end() &&  collider(_PawnsVec, (*it)->get_Tile_position()) && (
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 2 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, 3 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, 4 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, 5 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, 6 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, 7 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, -2 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, -3 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, -4 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, -5 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, -6 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, -7 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, -2 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, -3 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, -4 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, -5 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, -6 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, -7 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 2 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, 3 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, 4 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, 5 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, 6 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, 7 * 112) ||
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

bool Queen::collider(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos) {
	if (collider_for_Bishop(_PawnsVec, selected_Tile_pos) == true || collider_for_Rook(_PawnsVec, selected_Tile_pos) == true) {
		return true;
	}
	else {
		return false;
	}
	
}

void Queen::take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y); });
		if (it != board.end()) {
			if (get_Piece_color() == Black && take_collider_for_Black(_PawnsVec, (*it)->get_Tile_position())) {
				setPosition((*it)->get_Tile_position());
			}
			if (get_Piece_color() == White && take_collider_for_White(_PawnsVec, (*it)->get_Tile_position())) {
				setPosition((*it)->get_Tile_position());
			}
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}

bool Queen::take_collider_for_Black(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos) {
	if (take_collider_for_BlackBishop(_PawnsVec, selected_Tile_pos) == true || take_collider_for_BlackRook(_PawnsVec, selected_Tile_pos) == true) {
		return true;
	}
	else{
		return false;
	}
}

bool Queen::take_collider_for_White(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos) {
	if (take_collider_for_WhiteBishop(_PawnsVec, selected_Tile_pos) == true || take_collider_for_WhiteRook(_PawnsVec, selected_Tile_pos) == true) {
		return true;
	}
	else {
		return false;
	}
}