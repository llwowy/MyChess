
#include "Knight.h"
#include "Board.h"

Knight::Knight(const std::string& _id, const Piece_colors _color, Piece_types _Piece_type, std::vector<BoardTile*>& board) : Piece(_id, _color, _Piece_type) {
	set_Piece(board, _id);

	if (!Piece_texture.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
		std::cout << "dupaknight";
	}
	setTexture(Piece_texture);
	if (_color == Blue) { setTextureRect(sf::IntRect(16, 32, 16, 16)); }	//zmiany kolor�w zale�nie od Pawn_color
	if (_color == Green) { setTextureRect(sf::IntRect(95, 32, 16, 16)); }
	if (_color == White) { setTextureRect(sf::IntRect(16, 128, 16, 16)); }
	if (_color == Black) { setTextureRect(sf::IntRect(96, 128, 16, 16)); }
	setScale(7, 7);

	//auto it = std::find_if(board.begin(), board.end(), [_id](BoardTile* Tile) {
	//	return Tile->get_Tile_id() == _id; });
	//setPosition((*it)->get_Tile_position());
	//color = color_;
	//Create_Knight();
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
		}
		else {
			setPosition(get_Starting_Piece_pos());
		}
	}
}

bool Knight::collider(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos) {
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
