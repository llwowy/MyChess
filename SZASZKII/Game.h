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
#include <vector>

using Board = std::vector<BoardTile*>;

class Game
{
private:

	float Window_width = 1120;
	float Window_height = 1120;

	float skalaX = 7;
	float skalaY = 7;

	Board board;

	sf::RenderWindow* window = NULL;
	sf::Event eventy;
	sf::Texture teksturaTla;
	sf::Sprite BoardSprite;
	std::vector<Piece*> PawnsVec;
	
	

public:
	Game() {};
	void drawAll(sf::RenderWindow* window);
	void loadPawns();
	void readyBackground();
	void readyGame(); // za³adowanie wsystkich potrzebnych tekstur wektorów, itp
	void play();
	void allEvents();
	void GenerateBoard();
	void GeneratePawns();
	void LoadBoard(Board& board);

};

