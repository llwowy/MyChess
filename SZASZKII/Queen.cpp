#include "Queen.h"

Queen::Queen(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board, bool BandW, bool GandB) : Piece(_id, _color, _Piece_type, BandW, GandB) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
	}
	setTexture(Piece_texture);
	setTextureRect(sf::IntRect(16, 80, 16, 16));
	if (_color == White && GandB == true) { setTextureRect(sf::IntRect(32, 80, 16, 16)); }	//zmiany kolor�w zale�nie od Pawn_color
	if (_color == Black && GandB == true) { setTextureRect(sf::IntRect(112, 80, 16, 16)); }
	if (_color == White && BandW == true) { setTextureRect(sf::IntRect(32, 176, 16, 16)); }
	if (_color == Black && BandW == true) { setTextureRect(sf::IntRect(112, 176, 16, 16)); }
	setScale(7, 7);
}

void Queen::dance(int &counter) {


	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {}
	setTexture(Piece_texture);

	if (get_Piece_color() == White && get_GandB() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(16, 80, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(32, 80, 16, 16));
	}

	if (get_Piece_color() == Black && get_GandB() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(96, 80, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(112, 80, 16, 16));
	}

	if (get_Piece_color() == White && get_BandW() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(16, 176, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(32, 176, 16, 16));
	}

	if (get_Piece_color() == Black && get_BandW() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(96, 176, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(112, 176, 16, 16));
	}

}

void::Queen::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec) {
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
			std::cout << print_move(getPosition()) << std::endl;
			append_move(print_move(getPosition()));
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}


	}
}

bool Queen::collider(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	sf::Vector2f chosen_pos = selected_Tile_pos;
	sf::Vector2f starting_pos = get_Starting_Piece_pos();
	bool found_obstacle = false;

	if (itr == _PawnsVec.end()) {
		if (chosen_pos.x - starting_pos.x > 0 && chosen_pos.y - starting_pos.y > 0) {
			for (int i = chosen_pos.x - starting_pos.x -112; i != 0;) {
				auto itr1 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos, i](Piece* _piece) {
					return selected_Tile_pos - sf::Vector2f(i, i) == _piece->getPosition();
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
		else if (chosen_pos.x - starting_pos.x > 0 && chosen_pos.y - starting_pos.y < 0) {
			for (int i = chosen_pos.x - starting_pos.x - 112; i != 0;) {
				auto itr1 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos, i](Piece* _piece) {
					return selected_Tile_pos - sf::Vector2f(i, -i) == _piece->getPosition();
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
		else if (chosen_pos.x - starting_pos.x < 0 && chosen_pos.y - starting_pos.y > 0) {
			for (int i = chosen_pos.x - starting_pos.x + 112; i != 0;) {
				auto itr1 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos, i](Piece* _piece) {
					return selected_Tile_pos - sf::Vector2f(i, -i) == _piece->getPosition();
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
		else if (chosen_pos.x - starting_pos.x < 0 && chosen_pos.y - starting_pos.y < 0) {
			for (int i = chosen_pos.x - starting_pos.x + 112; i != 0;) {
				auto itr1 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos, i](Piece* _piece) {
					return selected_Tile_pos - sf::Vector2f(i, i) == _piece->getPosition();
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
		else if (chosen_pos.x - starting_pos.x > 0) {
			for (int i = chosen_pos.x - starting_pos.x - 112; i != 0;) {
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
			for (int i = chosen_pos.x - starting_pos.x + 112; i != 0;) {
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
			for (int i = chosen_pos.y - starting_pos.y - 112; i != 0;) {
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
			for (int i = chosen_pos.y - starting_pos.y + 112; i != 0;) {
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

void Queen::take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y); });
		if (it != board.end()) {
			if (get_Piece_color() == Black && take_collider_for_Black(_PawnsVec, (*it)->get_Tile_position())) {
				setPosition((*it)->get_Tile_position());
				std::cout << print_move(getPosition()) << std::endl;
				append_move(print_move(getPosition()));
			}
			if (get_Piece_color() == White && take_collider_for_White(_PawnsVec, (*it)->get_Tile_position())) {
				setPosition((*it)->get_Tile_position());
				std::cout << print_move(getPosition()) << std::endl;
				append_move(print_move(getPosition()));
			}
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}

bool Queen::take_collider_for_Black(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	if (take_collider_for_BlackBishop(_PawnsVec, selected_Tile_pos) == true || take_collider_for_BlackRook(_PawnsVec, selected_Tile_pos) == true) {
		return true;
	}
	else{
		return false;
	}
}

bool Queen::take_collider_for_White(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	if (take_collider_for_WhiteBishop(_PawnsVec, selected_Tile_pos) == true || take_collider_for_WhiteRook(_PawnsVec, selected_Tile_pos) == true) {
		return true;
	}
	else {
		return false;
	}
}

void Queen::mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec) {
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
		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(i, i); });

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
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-i, i); });

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
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(i, -i); });

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
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-i, -i); });

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
		for (int i = 112; i != 8 * 112;) {
			auto it = std::find_if(board.begin(), board.end(), [Piece_pos, i](BoardTile* Tile) {
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(i, i); });

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
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-i, i); });

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
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(i, -i); });

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
				return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-i, -i); });

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

bool Queen::possible_move(const sf::Vector2f& Tile_pos, std::vector<Piece*>& _PawnsVec) {
	if ((Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 1 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 2 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, 3 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, 4 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, 5 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, 6 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, 7 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -1 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, -2 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, -3 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, -4 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, -5 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, -6 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, -7 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -1 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, -2 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, -3 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, -4 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, -5 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, -6 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, -7 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 1 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 2 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, 3 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, 4 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, 5 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, 6 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, 7 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -1 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -2 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -3 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -4 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -5 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -6 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -7 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 1 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 2 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 3 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 4 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 5 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 6 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 7 * 112) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, 0) ||
		Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, 0))) {

		if (get_Piece_color() == Black && (collider(_PawnsVec, Tile_pos) || _collider_for_BlackBishop(_PawnsVec, Tile_pos) || _collider_for_BlackRook(_PawnsVec, Tile_pos))) {
			return true;
		}
		else if (get_Piece_color() == White && (collider(_PawnsVec, Tile_pos) || _collider_for_WhiteBishop(_PawnsVec, Tile_pos) || _collider_for_WhiteRook(_PawnsVec, Tile_pos))) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}