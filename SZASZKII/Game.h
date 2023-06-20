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
#include <Windows.h>


using Board = std::vector<BoardTile*>;

class Game
{
private:

	float Window_width = 1120;
	float Window_height = 1120;
 
	float MenuWindow_width = 1120;
	float MenuWindow_height = 1120;

	float KoniecWindow_width = 1120;
	float KoniecWindow_height = 1120;

	float skalaXBoard = 7;
	float skalaYBoard = 7;

	float skalaXMenu = 1.14;
	float skalaYMenu = 1.175;

	float skalaXKoniec = 1.04;//1.039 tak dokladnie
	float skalaYKoniec = 1.04;//1.13937 tak dokladnie

	
	bool King_White_checked = false;
	bool King_Black_checked = false;

	bool madeQW1 = false; //do zmiany figur
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
	bool BlackAndWhite = true;
	bool GreenAndBlue = false;
	bool WhiteWin = false;
	bool BlackWin = false;
	bool play_chess = false;
	bool restart = false;
	float timer;
	int counter;

	Board board; // == std::vector<BoardTile*>& board
	std::pair<std::string, std::string> Choosed_colors;
	sf::RenderWindow* window = NULL;//okno gry
	sf::RenderWindow* MenuWindow = NULL;//okno menu
	sf::RenderWindow* KoniecWindow = NULL;//okno knieec
	sf::Event BoardEventy;
	sf::Event MenuEventy;
	sf::Event KoniecEventy;

	sf::Clock clock;
	sf::Time time = clock.getElapsedTime();
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
	sf::Text Title;//sprite
	sf::Text Conf1;//sprite
	sf::Text Conf2;//sprite
	sf::Text History;//sprite
	//KONIEC
	sf::Texture teksturaKoniec;
	sf::Sprite KoniecSprite;

	sf::Texture tekBialyPion;
	sf::Sprite BialyPionSprite;

	sf::Texture tekCzarnyPion;
	sf::Sprite CzarnyPionSprite;

	sf::Texture tekZielonyPion;
	sf::Sprite ZielonyPionSprite;

	sf::Texture tekNiebieskiPion;
	sf::Sprite NiebieskiPionSprite;

	sf::Text KoniecText;//sprite
	sf::Text Restart;//sprite
	
	//GRA
	std::vector<Piece*> PawnsVec;
	sf::Vector2i Mouse_pos;

	sf::Clock clockMenu;//zegar do animacji
	sf::Time timeMenu;

public:

	Game();
	void drawAllOnBoard(sf::RenderWindow* window);
	void drawAllOnMenu(sf::RenderWindow* window);
	void drawAllOnKoniec(sf::RenderWindow* window);
	void readyFonsts();
	void loadPawns();
	void readyBackground();
	void readyGame();
	void readyMenu();
	void readyKoniec();
	void readyMenuBackground();
	void readyKoniecBackground();
	void play();
	void allGameEvents();
	void allMenuEvents();
	void allKoniecEvents();
	void LoadBoard(Board& board);
	void Pressed();
	void if_end_block_Pieces(const bool WhiteWon, const bool BlackWon, std::vector<Piece*>& _PawnsVec);
	void set_that_Piece_can_be_chosen(std::vector<Piece*>& _PawnsVec);
	bool check_whether_Black_or_white_win(const bool WhiteWon, const bool BlackWon);
	void Game_clock(sf::Clock _clock, sf::Time _time, float _timer);
	void read_file(std::string file_name_txt);
	friend bool Piece::get_play_chess();
	void is_King_checked(std::vector<BoardTile*>& board, const sf::Vector2i& mouse_position, std::vector<Piece*> _PawnsVec);
	void is_Pawn_promoted(std::vector<BoardTile*>& board, std::vector<Piece*> _PawnsVec);
	void start_txt();
	void end_txt();

	~Game() {};
};

std::ostream& operator<<(std::ostream& os, std::vector<Piece*> PawnsVec);