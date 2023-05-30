#include "Piece.h"

//Piece::Piece(const double& x_pos, const double& y_pos, const std::string& _Piece_id) :
//Piece_position(x_pos, y_pos), Piece_id(_Piece_id), Piece_size(105,105){}

Piece::Piece() {}

sf::Vector2f Piece::get_Piece_position() { return Piece_position; }
std::string Piece::get_Piece_id() { return Piece_id; }
sf::Texture Piece::get_Piece_texture() { return Piece_texture; }
sf::Sprite Piece::get_Piece_sprite() { return Piece_sprite; }