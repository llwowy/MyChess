#pragma once
#include <vector>
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h";
#include "Queen.h"
#include <memory>
#include <iostream>
#include "BoardTile.h"
#include <fstream>


using Board = std::vector<BoardTile*>;

class Game
{
private:

	float Window_width = 1120;
	float Window_height = 1120;
 
	float MenuWindow_width = 1120;
	float MenuWindow_height = 1120;

	float skalaXBoard = 7;
	float skalaYBoard = 7;

	float skalaXMenu = 1.14;
	float skalaYMenu = 1.175;

	bool last_move_was_Black = true;
	bool King_White_checked = false;
	bool King_Black_checked = false;

	bool madeQW1 = false;
	bool madeQW2 = false;
	bool madeQW3 = false;
	bool madeQW4 = false;
	bool madeQW5 = false;
	bool madeQW6 = false;
	bool madeQW7 = false;
	bool madeQW8 = false;

	bool madeQB1 = false;
	bool madeQB2 = false;
	bool madeQB3 = false;
	bool madeQB4 = false;
	bool madeQB5 = false;
	bool madeQB6 = false;
	bool madeQB7 = false;
	bool madeQB8 = false;

	bool WhiteWon = false;
	bool BlackWon = false;

	Board board; // == std::vector<BoardTile*>& board
	std::pair<std::string, std::string> Choosed_colors;
	sf::RenderWindow* window = NULL;//okno gry
	sf::RenderWindow* MenuWindow = NULL;//okno menu
	sf::Event BoardEventy;
	sf::Event MenuEventy;
	//GRA
	sf::Texture teksturaTla;
	sf::Sprite BoardSprite;
	//MENU
	sf::Texture teksturaMenu;
	sf::Sprite MenuSprite;

	sf::Texture upperScroll;
	sf::Sprite upperScrollSprite;
	sf::Texture lowerScroll;
	sf::Sprite lowerScrollSprite;
	sf::Font Menufont;
	sf::Text Text;//sprite
	sf::Text Conf1;//sprite
	sf::Text Conf2;//sprite
	bool PlayChess = false;


	//GRA
	std::vector<Piece*> PawnsVec;
	sf::Vector2i Mouse_pos;

	sf::Clock clockMenu;//zegar do animacji
	sf::Time timeMenu;
	float timer;
	int counter;

public:

	bool BlackAndWhite = true;
	bool GreenAndBlue = false;

	void drawAllOnBoard(sf::RenderWindow* window);
	void drawAllOnMenu(sf::RenderWindow* window);
	void readyFonsts();
	void loadPawns();
	void readyBackground();
	void readyGame();
	void readyMenu();
	void readyMenuBackground();
	void play();
	void allGameEvents();
	void allMenuEvents();
	void LoadBoard(Board& board);
	void Pressed();
	Game() {
		readyMenu();
		readyFonsts();
	};
	void is_King_checked(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
	void is_Pawn_promoted(std::vector<BoardTile*>& board, std::vector<Piece*> _PawnsVec);
	void is_staleMate(std::vector<Piece*> _PawnsVec);
	void start_txt();
};

std::ostream& operator<<(std::ostream& os, std::vector<Piece*> PawnsVec);