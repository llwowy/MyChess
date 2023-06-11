
#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board) : Piece(_id, _color, _Piece_type) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupapawn";
	}
	setTexture(Piece_texture);

	if (_color == Blue) { setTextureRect(sf::IntRect(0, 0, 16, 16)); }	//zmiany kolor�w zale�nie od Pawn_color
	if (_color == Green) { setTextureRect(sf::IntRect(79, 0, 16, 16)); }
	if (_color == White) { setTextureRect(sf::IntRect(0, 96, 16, 16)); }
	if (_color == Black) { setTextureRect(sf::IntRect(80, 96, 16, 16)); }
	setScale(7, 7);
}
//void Pawn::Create_white_pawn() {
//	if (Piece_texture.loadFromFile("")) {
//		std::cout << "dupa";
//	}
//	setTexture(Piece_texture);
//}

void::Pawn::move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y); });
		if (it != board.end()) {
			if (get_Piece_color() == Black) {
				if (collider_for_Black(_PawnsVec, (*it)->get_Tile_position())) {
					if (it != board.end() && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 1 * 112)) {
						setPosition((*it)->get_Tile_position());
					}
					else if (it != board.end() && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, 2 * 112) && ((*it)->get_Tile_id() == "a5" ||
						(*it)->get_Tile_id() == "b5" || (*it)->get_Tile_id() == "c5" || (*it)->get_Tile_id() == "d5" || (*it)->get_Tile_id() == "e5" ||
						(*it)->get_Tile_id() == "f5" || (*it)->get_Tile_id() == "g5" || (*it)->get_Tile_id() == "h5")) {
						setPosition((*it)->get_Tile_position());
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
					}
					else if (it != board.end() && (*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(0, -2 * 112) && ((*it)->get_Tile_id() == "a4" ||
						(*it)->get_Tile_id() == "b4" || (*it)->get_Tile_id() == "c4" || (*it)->get_Tile_id() == "d4" || (*it)->get_Tile_id() == "e4" ||
						(*it)->get_Tile_id() == "f4" || (*it)->get_Tile_id() == "g4" || (*it)->get_Tile_id() == "h4")) {
						setPosition((*it)->get_Tile_position());
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

bool Pawn::collider_for_Black(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos) {
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

void Pawn::take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {
	if (get_is_selected()) {
		auto it = std::find_if(board.begin(), board.end(), [mouse_position](BoardTile* Tile) {
			return (Tile->get_Tile_position().x <= mouse_position.x && Tile->get_Tile_position().x + Tile->get_Tile_size().x >= mouse_position.x &&
				Tile->get_Tile_position().y <= mouse_position.y && Tile->get_Tile_position().y + Tile->get_Tile_size().y >= mouse_position.y); });
		if (it != board.end()) {
			if (get_Piece_color() == Black && take_Left_collider_for_Black(_PawnsVec, (*it)->get_Tile_position())) {
				if ((*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, 1 * 112)) {
					setPosition((*it)->get_Tile_position());
				}
			}
			if (get_Piece_color() == Black && take_Right_collider_for_Black(_PawnsVec, (*it)->get_Tile_position())) {
				if ((*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, 1 * 112)) {
					setPosition((*it)->get_Tile_position());
				}
			}
			if (get_Piece_color() == White && take_Left_collider_for_White(_PawnsVec, (*it)->get_Tile_position())) {
				if ((*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(-1 * 112, -1 * 112)) {
					setPosition((*it)->get_Tile_position());
				}
			}
			if (get_Piece_color() == White && take_Right_collider_for_White(_PawnsVec, (*it)->get_Tile_position())) {
				if ((*it)->get_Tile_position() == get_Starting_Piece_pos() + sf::Vector2f(1 * 112, -1 * 112)) {
					setPosition((*it)->get_Tile_position());
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
	if (itr != _PawnsVec.end() && (*itr)->get_Piece_color() == White) {
		if ((*itr)->getPosition() == get_Starting_Piece_pos() + sf::Vector2f(-112, 112)) {
			(*itr)->setPosition(0, 0);
			(*itr)->scale(0,0);
			_PawnsVec.erase(itr);
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
	if (itr != _PawnsVec.end() && (*itr)->get_Piece_color() == White) {
		if ((*itr)->getPosition() == get_Starting_Piece_pos() + sf::Vector2f(112, 112)) {
			(*itr)->setPosition(0, 0);
			(*itr)->scale(0, 0);
			_PawnsVec.erase(itr);
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
	if (itr != _PawnsVec.end() && (*itr)->get_Piece_color() == Black) {
		if ((*itr)->getPosition() == get_Starting_Piece_pos() + sf::Vector2f(-112, -112)) {
			(*itr)->setPosition(0, 0);
			(*itr)->scale(0, 0);
			_PawnsVec.erase(itr);
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
	if (itr != _PawnsVec.end() && (*itr)->get_Piece_color() == Black) {
		if ((*itr)->getPosition() == get_Starting_Piece_pos() + sf::Vector2f(112, -112)) {
			(*itr)->setPosition(0, 0);
			(*itr)->scale(0, 0);
			_PawnsVec.erase(itr);
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