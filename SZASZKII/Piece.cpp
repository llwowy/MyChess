#include "Piece.h"



Piece::Piece(const std::string _id, Piece_colors _color, Piece_types _Piece_type, bool BandW, bool GandB) : Piece_id(_id), Piece_color(_color), Piece_type(_Piece_type), BandW(BandW), GandB(GandB) {
}


std::string Piece::get_Piece_id() { return Piece_id; }

Piece_colors Piece::get_Piece_color() { return Piece_color; }

bool Piece::last_move_was_Black = true;

bool Piece::get_is_selected() { return is_selected; }

sf::Vector2f Piece::get_Starting_Piece_pos() { return Starting_Piece_pos; }

Piece_types Piece::get_Piece_type() { return Piece_type; }

void Piece::dance(int &counter){};

bool Piece::get_BandW() { return BandW; };

bool Piece::get_GandB() { return GandB; };

void Piece::set_Piece(const std::vector<BoardTile*> board, std::string Tile_id) {
	auto it = std::find_if(board.begin(), board.end(), [Tile_id](BoardTile* Tile) {
		return Tile->get_Tile_id() == Tile_id; });
	setPosition((*it)->get_Tile_position());
}

void  Piece::select() {
	if (get_Piece_color() == Black && last_move_was_Black == false) {
		is_selected = true;
	}
	else if (get_Piece_color() == White && last_move_was_Black == true) {
		is_selected = true;
	}
}


void  Piece::unselect(const sf::Vector2i& mouse_position) {
	if (is_selected) {
		if (get_Piece_color() == Black) {
			if (get_Starting_Piece_pos() != getPosition()) {
				last_move_was_Black = true;
			}
		}
		else if (get_Piece_color() == White) {
			if (get_Starting_Piece_pos() != getPosition()) {
				last_move_was_Black = false;
			}
		}
		is_selected = false;
	}
}

void Piece::chosen(std::vector<BoardTile*>& _board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	sf::FloatRect rectangle_bounds = getGlobalBounds();
	if (rectangle_bounds.left <= mouse_position.x && rectangle_bounds.left + rectangle_bounds.width >= mouse_position.x &&
		rectangle_bounds.top <= mouse_position.y && rectangle_bounds.top + rectangle_bounds.height >= mouse_position.y) {
		select();
		Starting_Piece_pos = getPosition();
	}
}

void Piece::King_chosen(std::vector<BoardTile*>& _board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	
	if (get_Piece_color() == Black && get_Piece_type() == K) {
		auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
			return _piece->get_Piece_type() == K && _piece->get_Piece_color() == Black; });

		auto it = std::find_if(_board.begin(), _board.end(), [itr](BoardTile* Tile) {
			return Tile->get_Tile_position() == (*itr)->getPosition(); });

		if ((*it)->get_Tile_position().x <= mouse_position.x && (*it)->get_Tile_position().x + (*it)->get_Tile_size().x >= mouse_position.x &&
			(*it)->get_Tile_position().y <= mouse_position.y && (*it)->get_Tile_position().y + (*it)->get_Tile_size().y >= mouse_position.y) {
			std::cout << (*it)->get_Tile_position().x << std::endl << (*it)->get_Tile_position().y << std::endl;
			select();
			Starting_Piece_pos = getPosition();
		}
	}
	else if (get_Piece_color() == White && get_Piece_type() == K) {
		auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
			return _piece->get_Piece_type() == K && _piece->get_Piece_color() == White; });

		auto it = std::find_if(_board.begin(), _board.end(), [itr](BoardTile* Tile) {
			return Tile->get_Tile_position() == (*itr)->getPosition(); });

		if ((*it)->get_Tile_position().x <= mouse_position.x && (*it)->get_Tile_position().x + (*it)->get_Tile_size().x >= mouse_position.x &&
			(*it)->get_Tile_position().y <= mouse_position.y && (*it)->get_Tile_position().y + (*it)->get_Tile_size().y >= mouse_position.y) {
			std::cout << (*it)->get_Tile_position().x << std::endl << (*it)->get_Tile_position().y << std::endl;
			select();
			Starting_Piece_pos = getPosition();
		}
	}
}

void Piece::unchosen(const sf::Vector2i& mouse_position) {
	unselect(mouse_position);
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


bool Piece::take_collider_for_BlackRook(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if ((
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, 0)
		)) {
		if (itr != _PawnsVec.end() && (*itr)->get_Piece_type() != K) {
			sf::Vector2f chosen_pos = selected_Tile_pos;
			sf::Vector2f starting_pos = get_Starting_Piece_pos();
			bool found_obstacle = false;

			if (chosen_pos.x - starting_pos.x > 0) {
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == White) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == Black) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == White) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == Black) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == White) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == Black) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == White) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == Black) {
					return false;
				}
			}
		}
		else {
			setPosition(get_Starting_Piece_pos());
			return false;
		}
	}
	else {
		return false;
	}
}

bool Piece::take_collider_for_WhiteRook(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if ((
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, 0) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, 0)
		)) {
		if (itr != _PawnsVec.end() && (*itr)->get_Piece_type() != K) {
			sf::Vector2f chosen_pos = selected_Tile_pos;
			sf::Vector2f starting_pos = get_Starting_Piece_pos();
			bool found_obstacle = false;

			if (chosen_pos.x - starting_pos.x > 0) {
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == Black) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == White) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == Black) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == White) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == Black) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == White) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == Black) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == White) {
					return false;
				}
			}
		}
		else {
			setPosition(get_Starting_Piece_pos());
			return false;
		}
	}
	else {
		return false;
	}
}

bool Piece::take_collider_for_BlackBishop(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if ((
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, 3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, 4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, 5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, 6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, 7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, -2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, -3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, -4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, -5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, -6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, -7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, -2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, -3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, -4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, -5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, -6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, -7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, 3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, 4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, 5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, 6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, 7 * 112)
		)) {
		if (itr != _PawnsVec.end() && (*itr)->get_Piece_type() != K) {
			sf::Vector2f chosen_pos = selected_Tile_pos;
			sf::Vector2f starting_pos = get_Starting_Piece_pos();
			bool found_obstacle = false;

			if (chosen_pos.x - starting_pos.x > 0 && chosen_pos.y - starting_pos.y > 0) {
				for (int i = chosen_pos.x - starting_pos.x - 112; i != 0;) {
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == White) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == Black) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == White) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == Black) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == White) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == Black) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == White) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == Black) {
					return false;
				}
			}
		}
		else {
			setPosition(get_Starting_Piece_pos());
			return false;
		}
	}
	else {
		return false;
	}
}

bool Piece::take_collider_for_WhiteBishop(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if ((
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, 2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, 3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, 4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, 5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, 6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, 7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, -2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, -3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, -4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, -5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, -6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, -7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(2 * 112, -2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(3 * 112, -3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(4 * 112, -4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(5 * 112, -5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(6 * 112, -6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(7 * 112, -7 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 1 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-2 * 112, 2 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-3 * 112, 3 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-4 * 112, 4 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-5 * 112, 5 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-6 * 112, 6 * 112) ||
		selected_Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-7 * 112, 7 * 112)
		)) {
		if (itr != _PawnsVec.end() && (*itr)->get_Piece_type() != K) {
			sf::Vector2f chosen_pos = selected_Tile_pos;
			sf::Vector2f starting_pos = get_Starting_Piece_pos();
			bool found_obstacle = false;

			if (chosen_pos.x - starting_pos.x > 0 && chosen_pos.y - starting_pos.y > 0) {
				for (int i = chosen_pos.x - starting_pos.x - 112; i != 0;) {
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == Black) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == White) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == Black) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == White) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == Black) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == White) {
					return false;
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
				if (found_obstacle == false && (*itr)->get_Piece_color() == Black) {
					(*itr)->setPosition(0, 0);
					(*itr)->scale(0, 0);
					_PawnsVec.erase(itr);
					return true;
				}
				else if ((*itr)->get_Piece_color() == White) {
					return false;
				}
			}
		}
		else {
			setPosition(get_Starting_Piece_pos());
			return false;
		}
	}
	else {
		return false;
	}
}

bool Piece::collider_for_King(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if (itr != _PawnsVec.end()) {
		if (get_Piece_color() == Black) {
			if ((*itr)->get_Piece_color() == White && (*itr)->get_Piece_type() != K) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (get_Piece_color() == White) {
			if ((*itr)->get_Piece_color() == Black && (*itr)->get_Piece_type() != K) {
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