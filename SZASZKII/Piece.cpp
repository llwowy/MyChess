#include "Piece.h"


Piece::Piece(const std::string _id, Piece_colors _color, Piece_types _Piece_type, bool BandW, bool GandB) : Piece_id(_id), Piece_color(_color), Piece_type(_Piece_type), BandW(BandW), GandB(GandB) {
}

std::string Piece::get_Piece_id() { return Piece_id; }

Piece_colors Piece::get_Piece_color() { return Piece_color; }

Piece_types Piece::get_Piece_type() { return Piece_type; }

sf::Vector2f Piece::get_position() { return position; };

bool Piece::last_move_was_Black = true;

bool Piece::get_is_selected() { return is_selected; }

sf::Vector2f Piece::get_Starting_Piece_pos() { return Starting_Piece_pos; }

void Piece::dance(int &counter){};

void Piece::set_last_move_was_black(bool b) {
	last_move_was_Black = b;
}

bool Piece::get_BandW() { return BandW; };

bool Piece::get_GandB() { return GandB; };

bool Piece::get_can_cover() { return can_cover; }

void Piece::set_can_cover(bool b) {
	can_cover = b;
}

void Piece::set_Piece(const std::vector<BoardTile*> board, std::string Tile_id) {
	auto it = std::find_if(board.begin(), board.end(), [Tile_id](BoardTile* Tile) {
		return Tile->get_Tile_id() == Tile_id; });
	setPosition((*it)->get_Tile_position());
	Starting_Piece_pos = getPosition();
	if (get_Piece_type() != Q) {
		set_last_move_was_black(true);
	}
}

void  Piece::select() {
	if (can_be_chosen || can_cover) {
		if (get_Piece_color() == Black && last_move_was_Black == false) {
			is_selected = true;
		}
		else if (get_Piece_color() == White && last_move_was_Black == true) {
			is_selected = true;
		}
	}
}


void  Piece::unselect() {
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
		Starting_Piece_pos = getPosition();
	}
}

void Piece::chosen(std::vector<BoardTile*>& _board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec) {
	sf::FloatRect rectangle_bounds = getGlobalBounds();
	if (rectangle_bounds.left <= mouse_position.x && rectangle_bounds.left + rectangle_bounds.width >= mouse_position.x &&
		rectangle_bounds.top <= mouse_position.y && rectangle_bounds.top + rectangle_bounds.height >= mouse_position.y) {
		select();
		Starting_Piece_pos = getPosition();
	}
}

void Piece::King_chosen(std::vector<BoardTile*>& _board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec) {
	
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

void Piece::unchosen() {
	unselect();
}

void Piece::cant_be_chosen_f() {
	can_be_chosen = false;
}

void Piece::can_be_chosen_f() {
	can_be_chosen = true;
}

void Piece::Pick_up(const sf::Vector2i& mouse_position) {
	if (is_selected) {
		setPosition(mouse_position.x - 56, mouse_position.y - 56);

	}
}

void Piece::append_move(std::string move) {

	std::ofstream partia;
	partia.open("Dziennik_rozegranych_partii.txt", std::ios::app);

	partia <<  move << std::endl;
	

	partia.close();

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

bool Piece::take_collider_for_BlackBishop(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
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

bool Piece::take_collider_for_WhiteBishop(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
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

bool Piece::collider_for_King(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
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


std::string Piece::print_move(sf::Vector2f position) {


	std::string color;
	
	if (this->get_Piece_color() == 0 || this->get_Piece_color() == 2) {
		color = "w";
}
	else if (this->get_Piece_color() == 1 || this->get_Piece_color() == 3) {
		color = "b";
	}


	std::string type;

	if (this->get_Piece_type()==P) {
		type = "p";
	}
	else if (this->get_Piece_type() == R || this->get_Piece_type() == R1) {
		type = "r";
	}
	else if (this->get_Piece_type() == N) {
		type = "n";
	}
	else if (this->get_Piece_type() == B) {
		type = "b";
	}
	else if (this->get_Piece_type() == Q) {
		type = "q";
	}
	else if (this->get_Piece_type() == K) {
		type = "k";
	}


	std::string pos;
	
	if (position.x == 112 && position.y == 112) {
		pos = "a8";
	}
	else if (position.x == 112 && position.y == 224) {
		pos = "a7";
	}
	else if (position.x == 112 && position.y == 336) {
		pos = "a6";
	}
	else if (position.x == 112 && position.y == 448) {
		pos = "a5";
	}
	else if (position.x == 112 && position.y == 560) {
		pos = "a4";
	}
	else if (position.x == 112 && position.y == 672) {
		pos = "a3";
	}
	else if (position.x == 112 && position.y == 784) {
		pos = "a2";
	}
	else if (position.x == 112 && position.y == 896) {
		pos = "a1";
	}


	else if (position.x == 224 && position.y == 112) {
		pos = "b8";
	}
	else if (position.x == 224 && position.y == 224) {
		pos = "b7";
	}
	else if (position.x == 224 && position.y == 336) {
		pos = "b6";
	}
	else if (position.x == 224 && position.y == 448) {
		pos = "b5";
	}
	else if (position.x == 224 && position.y == 560) {
		pos = "b4";
	}
	else if (position.x == 224 && position.y == 672) {
		pos = "b3";
	}
	else if (position.x == 224 && position.y == 784) {
		pos = "b2";
	}
	else if (position.x == 224 && position.y == 896) {
		pos = "b1";
	}

	else if (position.x == 336 && position.y == 112) {
		pos = "c8";
	}
	else if (position.x == 336 && position.y == 224) {
		pos = "c7";
	}
	else if (position.x == 336 && position.y == 336) {
		pos = "c6";
	}
	else if (position.x == 336 && position.y == 448) {
		pos = "c5";
	}
	else if (position.x == 336 && position.y == 560) {
		pos = "c4";
	}
	else if (position.x == 336 && position.y == 672) {
		pos = "c3";
	}
	else if (position.x == 336 && position.y == 784) {
		pos = "c2";
	}
	else if (position.x == 336 && position.y == 896) {
		pos = "c1";
	}


	else if (position.x == 448 && position.y == 112) {
		pos = "d8";
	}
	else if (position.x == 448 && position.y == 224) {
		pos = "d7";
	}
	else if (position.x == 448 && position.y == 336) {
		pos = "d6";
	}
	else if (position.x == 448 && position.y == 448) {
		pos = "d5";
	}
	else if (position.x == 448 && position.y == 560) {
		pos = "d4";
	}
	else if (position.x == 448 && position.y == 672) {
		pos = "d3";
	}
	else if (position.x == 448 && position.y == 784) {
		pos = "d2";
	}
	else if (position.x == 448 && position.y == 896) {
		pos = "d1";
	}


	else if (position.x == 560 && position.y == 112) {
		pos = "e8";
	}
	else if (position.x == 560 && position.y == 224) {
		pos = "e7";
	}
	else if (position.x == 560 && position.y == 336) {
		pos = "e6";
	}
	else if (position.x == 560 && position.y == 448) {
		pos = "e5";
	}
	else if (position.x == 560 && position.y == 560) {
		pos = "e4";
	}
	else if (position.x == 560 && position.y == 672) {
		pos = "e3";
	}
	else if (position.x == 560 && position.y == 784) {
		pos = "e2";
	}
	else if (position.x == 560 && position.y == 896) {
		pos = "e1";
	}

	else if (position.x == 672 && position.y == 112) {
		pos = "f8";
	}
	else if (position.x == 672 && position.y == 224) {
		pos = "f7";
	}
	else if (position.x == 672 && position.y == 336) {
		pos = "f6";
	}
	else if (position.x == 672 && position.y == 448) {
		pos = "f5";
	}
	else if (position.x == 672 && position.y == 560) {
		pos = "f4";
	}
	else if (position.x == 672 && position.y == 672) {
		pos = "f3";
	}
	else if (position.x == 672 && position.y == 784) {
		pos = "f2";
	}
	else if (position.x == 672 && position.y == 896) {
		pos = "f1";
	}

	else if (position.x == 784 && position.y == 112) {
		pos = "g8";
	}
	else if (position.x == 784 && position.y == 224) {
		pos = "g7";
	}
	else if (position.x == 784 && position.y == 336) {
		pos = "g6";
	}
	else if (position.x == 784 && position.y == 448) {
		pos = "g5";
	}
	else if (position.x == 784 && position.y == 560) {
		pos = "g4";
	}
	else if (position.x == 784 && position.y == 672) {
		pos = "g3";
	}
	else if (position.x == 784 && position.y == 784) {
		pos = "g2";
	}
	else if (position.x == 784 && position.y == 896) {
		pos = "g1";
	}

	else if (position.x == 896 && position.y == 112) {
		pos = "h8";
	}
	else if (position.x == 896 && position.y == 224) {
		pos = "h7";
	}
	else if (position.x == 896 && position.y == 336) {
		pos = "h6";
	}
	else if (position.x == 896 && position.y == 448) {
		pos = "h5";
	}
	else if (position.x == 896 && position.y == 560) {
		pos = "h4";
	}
	else if (position.x == 896 && position.y == 672) {
		pos = "h3";
	}
	else if (position.x == 896 && position.y == 784) {
		pos = "h2";
	}
	else if (position.x == 896 && position.y == 896) {
		pos = "h1";
	}

	std::string move;
	move = color + type + pos;
	return move;
}