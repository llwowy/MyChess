#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include "BoardTile.h"
#include <fstream>




	enum Piece_colors {White, Black, Green, Blue};
	enum Piece_types {P,R,R1,N,B,Q,K};

class Piece : public sf::Sprite
{
private:

	std::string Piece_id;
	Piece_colors Piece_color;
	Piece_types Piece_type;
	bool is_selected = false;
	sf::Vector2f position;
	sf::Vector2f Starting_Piece_pos;
	bool colorWhiteAndBlack = NULL;
	bool colorBlueAndGreen = NULL;
	bool BandW;
	bool GandB;
	bool can_be_chosen = true;
	static bool last_move_was_Black;
	
protected:

	sf::Texture Piece_texture;

public:

	Piece(const std::string _id, Piece_colors _color, Piece_types _Piece_type, bool BandW, bool GandB);

	Piece_types get_Piece_type();

	Piece_colors get_Piece_color();

	void set_last_move_was_black(bool b);
	
	std::string get_Piece_id();
	sf::Vector2f get_position();
	sf::Vector2f get_Starting_Piece_pos();
	bool get_is_selected();
	bool get_BandW();
	bool get_GandB();
	bool get_play_chess();
	std::string print_move(sf::Vector2f position);
	
	virtual void set_Piece(const std::vector<BoardTile*> board, std::string Tile_id);
	virtual void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {};
	virtual void take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {};
	virtual void mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*>& _PawnsVec) {};
	virtual void dance(int &counter);

	void append_move(std::string move);
	void select();
	void unselect();
	void chosen(std::vector<BoardTile*>& _board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec);
	void King_chosen(std::vector<BoardTile*>& _board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec);
	void unchosen();
	void cant_be_chosen_f();
	void can_be_chosen_f();
	void Pick_up(const sf::Vector2i& mouse_position);
	void Landing(std::vector<BoardTile*> board, const sf::Vector2i& mouse_position);

	bool take_collider_for_BlackRook(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_collider_for_WhiteRook(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_collider_for_BlackBishop(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_collider_for_WhiteBishop(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	bool collider_for_King(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);

	virtual ~Piece() {};
};
