
#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board, bool BandW, bool GandB) : Piece(_id, _color, _Piece_type, BandW, GandB) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
	}
	setTexture(Piece_texture);

	if (_color == White && GandB == true ) { setTextureRect(sf::IntRect(0, 0, 16, 16)); }	//zmiany kolorów zale¿nie od Pawn_color //niebieski
	if (_color == Black && GandB == true ) { setTextureRect(sf::IntRect(80, 0, 16, 16)); }//zielony
	if (_color == White && BandW == true) { setTextureRect(sf::IntRect(0, 96, 16, 16)); }//bialy
	if (_color == Black && BandW == true)  { setTextureRect(sf::IntRect(80, 96, 16, 16)); }//czarny
	setScale(7, 7);
}

void Pawn::dance(int &counter) {


	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {}
	setTexture(Piece_texture);

	if (get_Piece_color() == White && get_GandB() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(16, 0, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(0, 0, 16, 16));
	}

	if (get_Piece_color() == Black && get_GandB() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(96, 0, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(80, 0, 16, 16));
	}

	if (get_Piece_color() == White && get_BandW() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(16, 96, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(0, 96, 16, 16));
	}

	if (get_Piece_color() == Black && get_BandW() == true) {

		if (counter % 2 == 0) {

			setTextureRect(sf::IntRect(96, 96, 16, 16));
		}
		else

			setTextureRect(sf::IntRect(80, 96, 16, 16));
	}

}

void::Pawn::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y); });

		if (it != board.end()) {
			if (get_Piece_color() == Black) {
				
				if (collider_for_Black(_PawnsVec, (*it)->get_Tile_position())) {
					if (it != board.end() && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 1 * 112)) {
						setPosition((*it)->get_Tile_position());
						std::cout << print_move(getPosition()) << std::endl;
						append_move(print_move(getPosition()));
					}
					else if (it != board.end() && collider_for_Black(_PawnsVec, (*it)->get_Tile_position() + sf::Vector2f(0, -112)) && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 2 * 112) && ((*it)->get_Tile_id() == "a5" ||
						(*it)->get_Tile_id() == "b5" || (*it)->get_Tile_id() == "c5" || (*it)->get_Tile_id() == "d5" || (*it)->get_Tile_id() == "e5" ||
						(*it)->get_Tile_id() == "f5" || (*it)->get_Tile_id() == "g5" || (*it)->get_Tile_id() == "h5")) {
						setPosition((*it)->get_Tile_position());
						std::cout << print_move(getPosition()) << std::endl;
						append_move(print_move(getPosition()));
					}
					else {
						setPosition(get_Starting_Piece_pos());
					}
				}
				else {
					setPosition(get_Starting_Piece_pos());
				}
			}
			else {
				setPosition(get_Starting_Piece_pos());
			}


			if (get_Piece_color() == White) {
				if (collider_for_Black(_PawnsVec, (*it)->get_Tile_position())) {
					if (it != board.end() && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -1 * 112)) {
						setPosition((*it)->get_Tile_position());
						std::cout << print_move(getPosition()) << std::endl;
						append_move(print_move(getPosition()));
					}
					else if (it != board.end() && collider_for_Black(_PawnsVec, (*it)->get_Tile_position() + sf::Vector2f(0, 112)) && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -2 * 112) && ((*it)->get_Tile_id() == "a4" ||
						(*it)->get_Tile_id() == "b4" || (*it)->get_Tile_id() == "c4" || (*it)->get_Tile_id() == "d4" || (*it)->get_Tile_id() == "e4" ||
						(*it)->get_Tile_id() == "f4" || (*it)->get_Tile_id() == "g4" || (*it)->get_Tile_id() == "h4")) {
						setPosition((*it)->get_Tile_position());
						std::cout << print_move(getPosition()) << std::endl;
						append_move(print_move(getPosition()));
					}
					else {
						setPosition(get_Starting_Piece_pos());
					}
				}
				else {
					setPosition(get_Starting_Piece_pos());
				}

			}
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}

	}
}

bool Pawn::collider_for_Black(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if (itr == _PawnsVec.end()) {
		return true;
	}
	else {
		return false;
	}
}

void Pawn::take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y); });
		if (it != board.end()) {
			if (get_Piece_color() == Black && take_Left_collider_for_Black(_PawnsVec, (*it)->get_Tile_position())) {
				if ((*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 1 * 112)) {
					setPosition((*it)->get_Tile_position());
					std::cout << print_move(getPosition()) << std::endl;
					append_move(print_move(getPosition()));
				}
			}
			if (get_Piece_color() == Black && take_Right_collider_for_Black(_PawnsVec, (*it)->get_Tile_position())) {
				if ((*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 1 * 112)) {
					setPosition((*it)->get_Tile_position());
					std::cout << print_move(getPosition()) << std::endl;
					append_move(print_move(getPosition()));
				}
			}
			if (get_Piece_color() == White && take_Left_collider_for_White(_PawnsVec, (*it)->get_Tile_position())) {
				if ((*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -1 * 112)) {
					setPosition((*it)->get_Tile_position());
					std::cout << print_move(getPosition()) << std::endl;
					append_move(print_move(getPosition()));
				}
			}
			if (get_Piece_color() == White && take_Right_collider_for_White(_PawnsVec, (*it)->get_Tile_position())) {
				if ((*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -1 * 112)) {
					setPosition((*it)->get_Tile_position());
					std::cout << print_move(getPosition()) << std::endl;
					append_move(print_move(getPosition()));
				}
			}
		}

		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}

bool Pawn::take_Left_collider_for_Black(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if (itr != _PawnsVec.end() && (*itr)->get_Piece_color() == White && (*itr)->get_Piece_type() != K) {
		if ((*itr)->getPosition() == get_Starting_Piece_pos() + sf::Vector2f(-112, 112)) {
			(*itr)->set_delectable(true);
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

bool Pawn::take_Right_collider_for_Black(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if (itr != _PawnsVec.end() && (*itr)->get_Piece_color() == White && (*itr)->get_Piece_type() != K) {
		if ((*itr)->getPosition() == get_Starting_Piece_pos() + sf::Vector2f(112, 112)) {
			(*itr)->set_delectable(true);
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

bool Pawn::take_Left_collider_for_White(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if (itr != _PawnsVec.end() && (*itr)->get_Piece_color() == Black && (*itr)->get_Piece_type() != K) {
		if ((*itr)->getPosition() == get_Starting_Piece_pos() + sf::Vector2f(-112, -112)) {
			(*itr)->set_delectable(true);
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

bool Pawn::take_Right_collider_for_White(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos) {
	auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [selected_Tile_pos](Piece* _piece) {
		return selected_Tile_pos == _piece->getPosition();
		});
	if (itr != _PawnsVec.end() && (*itr)->get_Piece_color() == Black && (*itr)->get_Piece_type() != K) {
		if ((*itr)->getPosition() == get_Starting_Piece_pos() + sf::Vector2f(112, -112)) {
			(*itr)->set_delectable(true);
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

void Pawn::mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec) {
	if (get_Piece_color() == White) {

		sf::Vector2f Piece_pos = getPosition();


		auto it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(112, -112); });

		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-112, -112); });

		if (it != board.end()) {
			(*it)->set_Tile_marked_for_White(true);
		}
	}
	if (get_Piece_color() == Black) {

		sf::Vector2f Piece_pos = getPosition();


		auto it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(112, 112); });

		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}

		it = std::find_if(board.begin(), board.end(), [Piece_pos](BoardTile* Tile) {
			return Tile->get_Tile_position() == Piece_pos + sf::Vector2f(-112, 112); });

		if (it != board.end()) {
			(*it)->set_Tile_marked_for_Black(true);
		}
	}
}

bool Pawn::possible_move(const sf::Vector2f& Tile_pos, std::vector<Piece*>& _PawnsVec) {
	if (get_Piece_color() == White) {
		if (Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -1 * 112)) {
			auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [Tile_pos](Piece* piece) {
				return piece->get_Starting_Piece_pos() == Tile_pos; });
			if (itr == _PawnsVec.end()) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, -2 * 112) && (get_Piece_id() == "a2" || get_Piece_id() == "b2" || get_Piece_id() == "c2" || get_Piece_id() == "d2" ||
			get_Piece_id() == "e2" || get_Piece_id() == "f2" || get_Piece_id() == "g2" || get_Piece_id() == "h2")) {
			auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [Tile_pos](Piece* piece) {
				return piece->get_Starting_Piece_pos() == Tile_pos; });
			if (itr == _PawnsVec.end()) {
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
	else if (get_Piece_color() == Black) {
		if (Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 1 * 112)) {
			auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [Tile_pos](Piece* piece) {
				return piece->get_Starting_Piece_pos() == Tile_pos; });
			if (itr == _PawnsVec.end()) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(0, 2 * 112) && (get_Piece_id() == "a7" || get_Piece_id() == "b7" || get_Piece_id() == "c7" || get_Piece_id() == "d7" ||
			get_Piece_id() == "e7" || get_Piece_id() == "f7" || get_Piece_id() == "g7" || get_Piece_id() == "h7")) {
			auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [Tile_pos](Piece* piece) {
				return piece->get_Starting_Piece_pos() == Tile_pos; });
			if (itr == _PawnsVec.end()) {
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
}

bool Pawn::possible_move_take(const sf::Vector2f& Tile_pos, std::vector<Piece*>& _PawnsVec) {
	if (get_Piece_color() == White) {
		if (Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -1 * 112) || Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -1 * 112)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (get_Piece_color() == Black) {
		if (Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 1 * 112) || Tile_pos == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 1 * 112)) {
			return true;
		}
		else {
			return false;
		}
	}
}