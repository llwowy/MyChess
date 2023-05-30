#pragma once

#include "Piece.h"
class Pawn : public Piece
{
private:
	sf::Sprite Piece_sprite;
public:
	Pawn(const double& x_pos, const double& y_pos, const std::string& _Piece_id, const sf::Texture& _Piece_Texture);
};

