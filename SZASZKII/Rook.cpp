#include "Rook.h"
#include "Board.h"

Rook::Rook(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board, bool BandW, bool GandB) : Piece(_id, _color, _Piece_type, BandW, GandB) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "duparook";
	}
	setTexture(Piece_texture);
	if (_color == White && GandB == true) { setTextureRect(sf::IntRect(16, 16, 16, 16)); }	//zmiany kolorów zale¿nie od Pawn_color
	if (_color == Black && GandB == true) { setTextureRect(sf::IntRect(95, 16, 16, 16)); }
	if (_color == White && BandW == true) { setTextureRect(sf::IntRect(16, 112, 16, 16)); }
	if (_color == Black && BandW == true) { setTextureRect(sf::IntRect(96, 112, 16, 16)); }
	setScale(7, 7);
}

void Rook::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y);
			});

		if (it != board.end() && collider(_PawnsVec, (*it)->get_Tile_position()) && (
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


void Rook::take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec) {
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

bool Rook::collider(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		}); sf::Vector2f chosen_pos = selected_Tile_pos;
	sf::Vector2f starting_pos = get_Starting_Piece_pos();
	bool found_obstacle = false;

	if (itr == _PawnsVec.end()) {
		if (chosen_pos.x - starting_pos.x > 0) {
			for (int i = chosen_pos.x - starting_pos.x; i != 0;) {
				auto itr1 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos, i](Piece* _piece) {
					return selected_Tile_pos - sf::Vector2f(i, 0) == _piece->getPosition();
					});
				if (itr1 != _PawnsVec.end()) {
					found_obstacle = true;
					return false;
					break;
				}
				i -= 112;
			}
			if (found_obstacle == false) {
				return true;
			}
		}
		else if (chosen_pos.x - starting_pos.x < 0) {
			for (int i = chosen_pos.x - starting_pos.x; i != 0;) {
				auto itr1 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos, i](Piece* _piece) {
					return selected_Tile_pos - sf::Vector2f(i, 0) == _piece->getPosition();
					});

				if (itr1 != _PawnsVec.end()) {
					found_obstacle = true;
					return false;
					break;
				}
				i += 112;
			}
			if (found_obstacle == false) {
				return true;
			}
		}
		else if (chosen_pos.y - starting_pos.y > 0) {
			for (int i = chosen_pos.y - starting_pos.y; i != 0;) {
				auto itr1 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos, i](Piece* _piece) {
					return selected_Tile_pos - sf::Vector2f(0, i) == _piece->getPosition();
					});

				if (itr1 != _PawnsVec.end()) {
					found_obstacle = true;
					return false;
					break;
				}
				i -= 112;
			}
			if (found_obstacle == false) {
				return true;
			}
		}
		else if (chosen_pos.y - starting_pos.y < 0) {
			for (int i = chosen_pos.y - starting_pos.y; i != 0;) {
				auto itr1 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos, i](Piece* _piece) {
					return selected_Tile_pos - sf::Vector2f(0, i) == _piece->getPosition();
					});

				if (itr1 != _PawnsVec.end()) {
					found_obstacle = true;
					return false;
					break;
				}
				i += 112;
			}
			if (found_obstacle == false) {
				return true;
			}
		}
	}
	else {
		return false;
	}
}

void Rook::mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec) {

	sf::Vector2f Piece_pos = getPosition();

	if (get_Piece_color() == White) {

		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(i, 0); });

			if (it != board.end()) {
				(*it)->set_Tile_marked_for_White(true);
				auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* _piece) {
					return (*it)->get_Tile_position() == _piece->getPosition();
					});
				if (itr != _PawnsVec.end()) {
					break;
				}
			}
			i += 112;
		}
		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-i, 0); });

			if (it != board.end()) {
				(*it)->set_Tile_marked_for_White(true);
				auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* _piece) {
					return (*it)->get_Tile_position() == _piece->getPosition();
					});
				if (itr != _PawnsVec.end()) {
					break;
				}
			}
			i += 112;
		}
		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(0, i); });

			if (it != board.end()) {
				(*it)->set_Tile_marked_for_White(true);
				auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* _piece) {
					return (*it)->get_Tile_position() == _piece->getPosition();
					});
				if (itr != _PawnsVec.end()) {
					break;
				}
			}
			i += 112;
		}
		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(0, -i); });

			if (it != board.end()) {
				(*it)->set_Tile_marked_for_White(true);
				auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* _piece) {
					return (*it)->get_Tile_position() == _piece->getPosition();
					});
				if (itr != _PawnsVec.end()) {
					break;
				}
			}
			i += 112;
		}
	}
	if (get_Piece_color() == Black) {

		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(i, 0); });

			if (it != board.end()) {
				(*it)->set_Tile_marked_for_Black(true);
				auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* _piece) {
					return (*it)->get_Tile_position() == _piece->getPosition();
					});
				if (itr != _PawnsVec.end()) {
					break;
				}
			}
			i += 112;
		}
		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-i, 0); });

			if (it != board.end()) {
				(*it)->set_Tile_marked_for_Black(true);
				auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* _piece) {
					return (*it)->get_Tile_position() == _piece->getPosition();
					});
				if (itr != _PawnsVec.end()) {
					break;
				}
			}
			i += 112;
		}
		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(0, i); });

			if (it != board.end()) {
				(*it)->set_Tile_marked_for_Black(true);
				auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* _piece) {
					return (*it)->get_Tile_position() == _piece->getPosition();
					});
				if (itr != _PawnsVec.end()) {
					break;
				}
			}
			i += 112;
		}
		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(0, -i); });

			if (it != board.end()) {
				(*it)->set_Tile_marked_for_Black(true);
				auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* _piece) {
					return (*it)->get_Tile_position() == _piece->getPosition();
					});
				if (itr != _PawnsVec.end()) {
					break;
				}
			}
			i += 112;
		}
	}
}