#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include "BoardTile.h"

	enum Piece_colors {White, Black, Green, Blue};
	enum Piece_types {P,R,N,B,Q,K};

class Piece : public sf::Sprite
{
private:

	std::string Piece_id;
	Piece_colors Piece_color;
	Piece_types Piece_type;
	bool is_selected = false;
	sf::Vector2f position;
	sf::Vector2f Starting_Piece_pos;

	bool colorWhiteAndBlack = NULL;//do koloru
	bool colorBlueAndGreen = NULL;//do koloru

	static bool last_move_was_Black;
	

protected:
	//std::map <std::string, sf::Vector2f > plansza{ {"a1", }}; chuj wie gówno cipsko
	sf::Texture Piece_texture;
public:

	Piece(const std::string _id, Piece_colors _color, Piece_types _Piece_type, bool BandW, bool GandB);
	bool BandW;
	bool GandB;
	Piece_types get_Piece_type();
	Piece_colors get_Piece_color();
	std::string get_Piece_id();
	sf::Vector2f get_Starting_Piece_pos();
	bool get_is_selected();

	void select();

	void unselect(const sf::Vector2i& mouse_position);
	virtual void set_Piece(const std::vector<BoardTile*> board, std::string Tile_id);

	void chosen(const sf::Vector2i& mouse_position);
	
	void unchosen(const sf::Vector2i& mouse_position);
	void Pick_up(const sf::Vector2i& mouse_position);
	void Landing(std::vector<BoardTile*> board, const sf::Vector2i& mouse_position);
	virtual void move(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {};
	virtual bool collider_for_Black(std::vector<Piece*> PawnsVec, sf::Vector2f selected_Tile_pos) { return 1; };
	virtual void take(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec) {};
	virtual ~Piece() { std::cout << "usun¹³em figure" << std::endl; };

	bool take_collider_for_BlackRook(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_collider_for_WhiteRook(std::vector<Piece*>& _PawnsVec, sf::Vector2f selected_Tile_pos);

	bool take_collider_for_BlackBishop(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos);
	bool take_collider_for_WhiteBishop(std::vector<Piece*> _PawnsVec, sf::Vector2f selected_Tile_pos);

	virtual void mark_Tiles(std::vector<BoardTile*>& board, std::vector<Piece*> _PawnsVec) {};
};

