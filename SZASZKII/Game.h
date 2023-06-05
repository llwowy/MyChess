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
	void GenerateBoard() {};
	void GeneratePawns() {};
private:
	std::vector<Piece*>PawnsVec;
	// std::vector<BoardTile*>BoardVec;
};

