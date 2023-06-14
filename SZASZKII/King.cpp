#include "King.h"


King::King(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board) : Piece(_id, _color, _Piece_type) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupapawn";
	}
	setTexture(Piece_texture);
	if (_color == Blue) { setTextureRect(sf::IntRect(16, 64, 16, 16)); }	//zmiany kolorów zale¿nie od Pawn_color
	if (_color == Green) { setTextureRect(sf::IntRect(95, 64, 16, 16)); }
	if (_color == White) { setTextureRect(sf::IntRect(16, 160, 16, 16)); }
	if (_color == Black) { setTextureRect(sf::IntRect(96, 160, 16, 16)); }
	setScale(7, 7);
}
void::King::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y);
			});

		if (it != board.end() && get_Piece_color() == Black && (*it)->get_Tile_marked_for_White() == false && collider(_PawnsVec, (*it)->get_Tile_position()) && (
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
		else if(it != board.end() && get_Piece_color() == White && (*it)->get_Tile_marked_for_Black() == false && collider(_PawnsVec, (*it)->get_Tile_position()) && (
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 0 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 0 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0 * 112, -1 * 112)
			)){
			setPosition((*it)->get_Tile_position());
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}

bool King::collider(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if (itr != _PawnsVec.end()) {
		if (get_Piece_color() == Black) {
			if ((*itr)->get_Piece_color() == White && (*itr)->get_Piece_type() != K) {
				(*itr)->setPosition(0, 0);
				(*itr)->scale(0, 0);
				_PawnsVec.erase(itr);
				return true;
			}
			else {
				return false;
			}
		}
		else if (get_Piece_color() == White) {
			if ((*itr)->get_Piece_color() == Black && (*itr)->get_Piece_type() != K) {
				(*itr)->setPosition(0, 0);
				(*itr)->scale(0, 0);
				_PawnsVec.erase(itr);
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return true;
	}
}

void King::mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*> _PawnsVec) {
	sf::Vector2f Piece_pos = getPosition();

	if (get_Piece_color() == White) {

		auto it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, 0 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, 0 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(0 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(0 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}
	}
	if (get_Piece_color() == Black) {

		auto it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, 0 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, 0 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(0 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(0 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}
	}
}