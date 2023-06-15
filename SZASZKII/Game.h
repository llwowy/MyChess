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

	float skalaXMenu = 1.14;//1.33971 tak dokladnie
	float skalaYMenu = 1.175;//1.13937 tak dokladnie

	bool last_move_was_Black = true;

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
//	sf::Color colours;
	bool PlayChess = false;

	//GRA
	std::vector<Piece*> PawnsVec;
	sf::Vector2i Mouse_pos;

	sf::Clock clockMenu;//zegar do animacji

public:
	void drawAllOnBoard(sf::RenderWindow* window);
	void drawAllOnMenu(sf::RenderWindow* window);
	void readyFonsts();
	void loadPawns();
	void readyBackground();
	void readyGame(); // za³adowanie wsystkich potrzebnych tekstur wektorów, itp
	void readyMenu();
	void readyMenuBackground();
	void play();
	void allGameEvents();
	void allMenuEvents();
	void GenerateBoard();
	void GeneratePawns();
	void LoadBoard(Board& board);
	void Pressed();
	Game() {
		readyMenu();
		readyFonsts();
	};
	void getStartMenu(sf::Event& e, sf::RenderWindow* window);
	
};