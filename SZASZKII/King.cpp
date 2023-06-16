#include "King.h"


King::King(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board, bool BandW, bool GandB) : Piece(_id, _color, _Piece_type, BandW, GandB) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
	}
	setTexture(Piece_texture);
	if (_color == White && GandB == true) { setTextureRect(sf::IntRect(16, 64, 16, 16)); }	//zmiany kolorów zale¿nie od Pawn_color
	if (_color == Black && GandB == true) { setTextureRect(sf::IntRect(95, 64, 16, 16)); }
	if (_color == White && BandW == true) { setTextureRect(sf::IntRect(16, 160, 16, 16)); }
	if (_color == Black && BandW == true) { setTextureRect(sf::IntRect(96, 160, 16, 16)); }
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
		else if (it != board.end() && right_castling_condition(board,_PawnsVec) && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 0 * 112) && get_Piece_color() == White) {
			setPosition((*it)->get_Tile_position());
			auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
				return _piece->get_Piece_color() == White && _piece->get_Piece_type() == R; });
			if (itr != _PawnsVec.end()) {
				(*itr)->setPosition((*it)->get_Tile_position() + sf::Vector2f(-1 * 112, 0));
			}
		}
		else if (it != board.end() && right_castling_condition(board, _PawnsVec) && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 0 * 112) && get_Piece_color() == Black) {
			setPosition((*it)->get_Tile_position());
			auto itr1 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
				return _piece->get_Piece_color() == Black && _piece->get_Piece_type() == R; });
			if (itr1 != _PawnsVec.end()) {
				(*itr1)->setPosition((*it)->get_Tile_position() + sf::Vector2f(-1 * 112, 0));
			}
		}
		else if (it != board.end() && left_castling_condition(board, _PawnsVec) && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 0 * 112) && get_Piece_color() == White) {
			setPosition((*it)->get_Tile_position());
			auto itr2 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
				return _piece->get_Piece_color() == White && _piece->get_Piece_type() == R1; });
			if (itr2 != _PawnsVec.end()) {
				(*itr2)->setPosition((*it)->get_Tile_position() + sf::Vector2f(1 * 112, 0));
			}
		}
		else if (it != board.end() && left_castling_condition(board, _PawnsVec) && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 0 * 112) && get_Piece_color() == Black) {
			setPosition((*it)->get_Tile_position());
			auto itr3 = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
				return _piece->get_Piece_color() == Black && _piece->get_Piece_type() == R1; });
			if (itr3 != _PawnsVec.end()) {
				(*itr3)->setPosition((*it)->get_Tile_position() + sf::Vector2f(1 * 112, 0));
			}
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}

bool King::collider(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
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

bool King::right_castling_condition(std::vector<BoardTile*>& board, std::vector<Piece*> _PawnsVec) {

	if (get_Piece_color() == White && get_Starting_Piece_pos() == sf::Vector2f(560, 896)) {
		auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
			return _piece->get_Piece_color() == White && _piece->get_Piece_type() == R; });

		sf::Vector2f king_pos = get_Starting_Piece_pos();

		if (itr != _PawnsVec.end()) {
			auto it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
				return Tile->get_Tile_position() == king_pos + sf::Vector2f(112, 0); });
			
			if (it != board.end()) {
				if (collider_for_King(_PawnsVec, (*it)->get_Tile_position()) == true && (*it)->get_Tile_marked_for_Black() == false) {
					it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
						return Tile->get_Tile_position() == king_pos + sf::Vector2f(2 * 112, 0); });
					if (it != board.end()) {
						if (collider_for_King(_PawnsVec, (*it)->get_Tile_position()) == true && (*it)->get_Tile_marked_for_Black() == false) {
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
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	
	
	if (get_Piece_color() == Black && get_Starting_Piece_pos() == sf::Vector2f(560, 112)) {
		auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
			return _piece->get_Piece_color() == Black && _piece->get_Piece_type() == R; });

		sf::Vector2f king_pos = get_Starting_Piece_pos();

		if (itr != _PawnsVec.end()) {
			auto it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
				return Tile->get_Tile_position() == king_pos + sf::Vector2f(112, 0); });

			if (it != board.end()) {
				if (collider_for_King(_PawnsVec, (*it)->get_Tile_position()) == true && (*it)->get_Tile_marked_for_White() == false) {
					it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
						return Tile->get_Tile_position() == king_pos + sf::Vector2f(2 * 112, 0); });
					if (it != board.end()) {
						if (collider_for_King(_PawnsVec, (*it)->get_Tile_position()) == true && (*it)->get_Tile_marked_for_White() == false) {
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
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool King::left_castling_condition(std::vector<BoardTile*>& board, std::vector<Piece*> _PawnsVec) {

	if (get_Piece_color() == White && get_Starting_Piece_pos() == sf::Vector2f(560, 896)) {
		auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
			return _piece->get_Piece_color() == White && _piece->get_Piece_type() == R1; });

		sf::Vector2f king_pos = get_Starting_Piece_pos();

		if (itr != _PawnsVec.end()) {
			auto it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
				return Tile->get_Tile_position() == king_pos + sf::Vector2f(-1 * 112, 0); });

			if (it != board.end()) {
				if (collider_for_King(_PawnsVec, (*it)->get_Tile_position()) == true && (*it)->get_Tile_marked_for_Black() == false) {
					it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
						return Tile->get_Tile_position() == king_pos + sf::Vector2f(-2 * 112, 0); });
					if (it != board.end()) {
						if (collider_for_King(_PawnsVec, (*it)->get_Tile_position()) == true && (*it)->get_Tile_marked_for_Black() == false) {
							it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
								return Tile->get_Tile_position() == king_pos + sf::Vector2f(-3 * 112, 0); });
							if (it != board.end()) {
								if (collider_for_King(_PawnsVec, (*it)->get_Tile_position())) {
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
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}


	if (get_Piece_color() == Black && get_Starting_Piece_pos() == sf::Vector2f(560, 112)) {
		auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
			return _piece->get_Piece_color() == Black && _piece->get_Piece_type() == R; });

		sf::Vector2f king_pos = get_Starting_Piece_pos();

		if (itr != _PawnsVec.end()) {
			auto it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
				return Tile->get_Tile_position() == king_pos + sf::Vector2f(-1 * 112, 0); });

			if (it != board.end()) {
				if (collider_for_King(_PawnsVec, (*it)->get_Tile_position()) == true && (*it)->get_Tile_marked_for_White() == false) {
					it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
						return Tile->get_Tile_position() == king_pos + sf::Vector2f(-2 * 112, 0); });
					if (it != board.end()) {
						if (collider_for_King(_PawnsVec, (*it)->get_Tile_position()) == true && (*it)->get_Tile_marked_for_White() == false) {
							it = std::find_if(board.begin(), board.end(), [king_pos](BoardTile* Tile) {
								return Tile->get_Tile_position() == king_pos + sf::Vector2f(-3 * 112, 0); });
							if (it != board.end()) {
								if (collider_for_King(_PawnsVec, (*it)->get_Tile_position())) {
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
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}