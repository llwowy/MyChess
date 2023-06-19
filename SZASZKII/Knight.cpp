
#include "Knight.h"
#include "Board.h"

Knight::Knight(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board, bool BandW, bool GandB) : Piece(_id, _color, _Piece_type, BandW, GandB) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
	}
	setTexture(Piece_texture);
	if (_color == White && GandB == true) { setTextureRect(sf::IntRect(16, 32, 16, 16)); }	//zmiany kolorów zale¿nie od Pawn_color
	if (_color == Black && GandB == true) { setTextureRect(sf::IntRect(96, 32, 16, 16)); }
	if (_color == White && BandW == true) { setTextureRect(sf::IntRect(16, 128, 16, 16)); }
	if (_color == Black && BandW == true) { setTextureRect(sf::IntRect(96, 128, 16, 16)); }
	setScale(7, 7);

}

void Knight::dance(int &counter) {


	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {}
	setTexture(Piece_texture);

	if (get_Piece_color() == White && get_GandB() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(32, 32, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(16, 32, 16, 16));
	}

	if (get_Piece_color() == Black && get_GandB() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(112, 32, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(96, 32, 16, 16));
	}

	if (get_Piece_color() == White && get_BandW() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(32, 128, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(16, 128, 16, 16));
	}

	if (get_Piece_color() == Black && get_BandW() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(112, 128, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(96, 128, 16, 16));
	}

}



void Knight::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y);
			});

		if (it != board.end() && collider(_PawnsVec, (*it)->get_Tile_position()) && (
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, -1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, -1 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 2 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 2 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -2 * 112) ||
			(*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -2 * 112)
			)) {
			setPosition((*it)->get_Tile_position());		
			std::cout << print_move(getPosition()) << std::endl;
			append_move(print_move(getPosition()));
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}

	}



}




bool Knight::collider(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
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

void Knight::mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec) {

	sf::Vector2f Piece_pos = getPosition();

	if (get_Piece_color() == White) {

		auto it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(2 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(2 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-2 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-2 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, 2 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, 2 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, -2 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, -2 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}
	}
	if (get_Piece_color() == Black) {

		auto it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(2 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(2 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-2 * 112, 1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-2 * 112, -1 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, 2 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, 2 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(1 * 112, -2 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-1 * 112, -2 * 112); });
		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}
	}
}
