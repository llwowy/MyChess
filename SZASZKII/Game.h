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
	Game() {};
	void readyBackground() {};
	void radyGame() {}; // za³adowanie wsystkich potrzebnych tekstur wektorów, itp
	void play() {};
	void GenerateBoard() {};
	void GeneratePawns() {};
private:
	sf::Texture teksturaTla;
	std::vector<Piece*>PawnsVec;
	// std::vector<BoardTile*>BoardVec;
};

