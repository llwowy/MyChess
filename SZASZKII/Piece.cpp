#include "Piece.h"

Piece::Piece(const double& x_pos, const double& y_pos, const std::string& _Piece_id) : 
Piece_position(x_pos, y_pos), Piece_id(_Piece_id){}

sf::Vector2f Piece::get_Piece_position() { return Piece_position; }
std::string Piece::get_Piece_id() { return Piece_id; }