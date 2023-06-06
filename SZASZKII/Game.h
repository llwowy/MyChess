#pragma once
#include <vector>
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h";
#include "Queen.h"
class Game
{public:
	Game();
	void drawAll(sf::RenderWindow* window);
	void loadPawns();
	void readyBackground();
	void readyGame(); // za³adowanie wsystkich potrzebnych tekstur wektorów, itp
	void play();
	void GenerateBoard();
	void GeneratePawns();
private:
	float Window_width = 1120;
	float Window_height = 1120;

	sf::RenderWindow *window;
	sf::Texture teksturaTla;
	std::vector<Piece*>PawnsVec;
	// std::vector<BoardTile*>BoardVec;
};

