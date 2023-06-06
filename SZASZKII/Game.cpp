#include "Game.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h";
#include "Queen.h"

void Game::play(){
	readyGame();
    loadPawns();

    drawAll(window);
    window->display();
}




void Game::readyBackground() {
    if (!teksturaTla.loadFromFile("Grafika/ChessTextures/chessBoardsWithBorder2.png")) { //tekstura tla
        std::cout << "load chessBoard failed" << std::endl;
        system("pause");
    }
    BoardSprite.setTexture(teksturaTla);
    BoardSprite.setScale(7, 7);
}


void Game::readyGame() {
    readyBackground();
    window = new sf::RenderWindow(sf::VideoMode(Window_width, Window_height), "MyChess");
}


void Game::loadPawns() {
    PawnsVec.push_back(new Pawn("a2", sf::Vector2f(200, 100)));
    PawnsVec.push_back(new Pawn("b2", sf::Vector2f(300, 100)));
    PawnsVec.push_back(new Pawn("c2", sf::Vector2f(400, 100)));
    PawnsVec.push_back(new Pawn("d2", sf::Vector2f(500, 100)));
    PawnsVec.push_back(new Pawn("e2", sf::Vector2f(600, 100)));
    PawnsVec.push_back(new Pawn("f2", sf::Vector2f(700, 100)));
    PawnsVec.push_back(new Pawn("g2", sf::Vector2f(800, 100)));
    PawnsVec.push_back(new Pawn("h2", sf::Vector2f(900, 100)));
}


void Game::drawAll(sf::RenderWindow *window) {
    window->draw(BoardSprite);
    for (auto& paw_and_fig : PawnsVec) {
        window->draw(*paw_and_fig);
    }
}