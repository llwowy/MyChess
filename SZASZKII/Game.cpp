#include "Game.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h";
#include "Queen.h"

void Game::play(){
	readyGame();
    window = new sf::RenderWindow(sf::VideoMode(Window_width, Window_height), "MyChess");
    loadPawns();

    drawAll(window);
}

//void Game::GeneratePawns() {
//	Pionki.emplace_back(new Pawn a2("a2", board), new Pawn b2("b2", board), new Pawn c2("c2", board), // generowanie pionków
//		new Pawn d2("d2", board), new Pawn e2("e2", board), new Pawn f2("f2", board),
//		new Pawn g2("g2", board), new Pawn h2("h2", board), new Rook a1("a1", board,
//			"black"), new Rook h1("h1", board, "black"), new Knight b1("b1", board, "black"),
//		new Knight g1("g1", board, "black"), new Bishop c1("c1", board, "black"), new Bishop f1("f1", board, "black"),
//		new King d1("d1", board, "black"), new Queen e1("e1", board, "black"));
//};

void Game::readyGame() {
    if (!teksturaTla.loadFromFile("Grafika/ChessTextures/chessBoardsWithBorder2.png")) { //tekstura tla
        std::cout << "load chessBoard failed" << std::endl;
        system("pause");
    }

}

void Game::loadPawns() {
    PawnsVec.emplace_back();
}
void Game::drawAll(sf::RenderWindow *window) {
    for (auto& paw_and_fig : PawnsVec) {
        window->draw(*paw_and_fig);
    }
}