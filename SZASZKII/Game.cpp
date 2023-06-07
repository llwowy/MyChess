
#include "Game.h"
#include <SFML/Main.hpp>

void Game::play() {
    LoadBoard(board);
    readyGame();
    while (window->isOpen())
    {
        allEvents();

        drawAll(window);
        Pressed();
        window->display();
    }
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
    loadPawns();
}


void Game::loadPawns() {
    PawnsVec.push_back(new Pawn("a7", board));
    PawnsVec.push_back(new Pawn("b7", board));
    PawnsVec.push_back(new Pawn("c7", board));
    PawnsVec.push_back(new Pawn("d7", board));
    PawnsVec.push_back(new Pawn("e7", board));
    PawnsVec.push_back(new Pawn("f7", board));
    PawnsVec.push_back(new Pawn("g7", board));
    PawnsVec.push_back(new Pawn("h7", board));
    PawnsVec.push_back(new Rook("a8", board));
    PawnsVec.push_back(new Rook("h8", board));
    PawnsVec.push_back(new Knight("b8", board));
    PawnsVec.push_back(new Knight("g8", board));
    PawnsVec.push_back(new Bishop("c8", board));
    PawnsVec.push_back(new Bishop("f8", board));
    PawnsVec.push_back(new King("d8", board));
    PawnsVec.push_back(new Queen("e8", board));
}


void Game::drawAll(sf::RenderWindow* window) {
    window->draw(BoardSprite);
    for (auto& paw_and_fig : PawnsVec) {
        window->draw(*paw_and_fig);
    }
}

void Game::allEvents() {
    while (window->pollEvent(eventy)) {
        if (eventy.type == sf::Event::Closed)
            window->close();

    }
}

void Game::LoadBoard(Board& board) {
    board.push_back(new BoardTile(16 * skalaX, 16 * skalaY, "a8"));
    board.push_back(new BoardTile(32 * skalaX, 16 * skalaY, "b8"));
    board.push_back(new BoardTile(48 * skalaX, 16 * skalaY, "c8"));
    board.push_back(new BoardTile(64 * skalaX, 16 * skalaY, "d8"));
    board.push_back(new BoardTile(80 * skalaX, 16 * skalaY, "e8"));
    board.push_back(new BoardTile(96 * skalaX, 16 * skalaY, "f8"));
    board.push_back(new BoardTile(112 * skalaX, 16 * skalaY, "g8"));
    board.push_back(new BoardTile(128 * skalaX, 16 * skalaY, "h8"));
    board.push_back(new BoardTile(16 * skalaX, 32 * skalaY, "a7"));
    board.push_back(new BoardTile(32 * skalaX, 32 * skalaY, "b7"));
    board.push_back(new BoardTile(48 * skalaX, 32 * skalaY, "c7"));
    board.push_back(new BoardTile(64 * skalaX, 32 * skalaY, "d7"));
    board.push_back(new BoardTile(80 * skalaX, 32 * skalaY, "e7"));
    board.push_back(new BoardTile(96 * skalaX, 32 * skalaY, "f7"));
    board.push_back(new BoardTile(112 * skalaX, 32 * skalaY, "g7"));
    board.push_back(new BoardTile(128 * skalaX, 32 * skalaY, "h7"));
    board.push_back(new BoardTile(16 * skalaX, 48 * skalaY, "a6"));
    board.push_back(new BoardTile(32 * skalaX, 48 * skalaY, "b6"));
    board.push_back(new BoardTile(48 * skalaX, 48 * skalaY, "c6"));
    board.push_back(new BoardTile(64 * skalaX, 48 * skalaY, "d6"));
    board.push_back(new BoardTile(80 * skalaX, 48 * skalaY, "e6"));
    board.push_back(new BoardTile(96 * skalaX, 48 * skalaY, "f6"));
    board.push_back(new BoardTile(112 * skalaX, 48 * skalaY, "g6"));
    board.push_back(new BoardTile(128 * skalaX, 48 * skalaY, "h6"));
    board.push_back(new BoardTile(16 * skalaX, 64 * skalaY, "a5"));
    board.push_back(new BoardTile(32 * skalaX, 64 * skalaY, "b5"));
    board.push_back(new BoardTile(48 * skalaX, 64 * skalaY, "c5"));
    board.push_back(new BoardTile(64 * skalaX, 64 * skalaY, "d5"));
    board.push_back(new BoardTile(80 * skalaX, 64 * skalaY, "e5"));
    board.push_back(new BoardTile(96 * skalaX, 64 * skalaY, "f5"));
    board.push_back(new BoardTile(112 * skalaX, 64 * skalaY, "g5"));
    board.push_back(new BoardTile(128 * skalaX, 64 * skalaY, "h5"));
    board.push_back(new BoardTile(16 * skalaX, 80 * skalaY, "a4"));
    board.push_back(new BoardTile(32 * skalaX, 80 * skalaY, "b4"));
    board.push_back(new BoardTile(48 * skalaX, 80 * skalaY, "c4"));
    board.push_back(new BoardTile(64 * skalaX, 80 * skalaY, "d4"));
    board.push_back(new BoardTile(80 * skalaX, 80 * skalaY, "e4"));
    board.push_back(new BoardTile(96 * skalaX, 80 * skalaY, "f4"));
    board.push_back(new BoardTile(112 * skalaX, 80 * skalaY, "g4"));
    board.push_back(new BoardTile(128 * skalaX, 80 * skalaY, "h4"));
    board.push_back(new BoardTile(16 * skalaX, 96 * skalaY, "a3"));
    board.push_back(new BoardTile(32 * skalaX, 96 * skalaY, "b3"));
    board.push_back(new BoardTile(48 * skalaX, 96 * skalaY, "c3"));
    board.push_back(new BoardTile(64 * skalaX, 96 * skalaY, "d3"));
    board.push_back(new BoardTile(80 * skalaX, 96 * skalaY, "e3"));
    board.push_back(new BoardTile(96 * skalaX, 96 * skalaY, "f3"));
    board.push_back(new BoardTile(750 * skalaX, 96 * skalaY, "g3"));
    board.push_back(new BoardTile(875 * skalaX, 96 * skalaY, "h3"));
    board.push_back(new BoardTile(16 * skalaX, 112 * skalaY, "a2"));
    board.push_back(new BoardTile(32 * skalaX, 112 * skalaY, "b2"));
    board.push_back(new BoardTile(48 * skalaX, 112 * skalaY, "c2"));
    board.push_back(new BoardTile(64 * skalaX, 112 * skalaY, "d2"));
    board.push_back(new BoardTile(80 * skalaX, 112 * skalaY, "e2"));
    board.push_back(new BoardTile(96 * skalaX, 112 * skalaY, "f2"));
    board.push_back(new BoardTile(112 * skalaX, 112 * skalaY, "g2"));
    board.push_back(new BoardTile(128 * skalaX, 112 * skalaY, "h2"));
    board.push_back(new BoardTile(16 * skalaX, 128 * skalaY, "a1"));
    board.push_back(new BoardTile(32 * skalaX, 128 * skalaY, "b1"));
    board.push_back(new BoardTile(48 * skalaX, 128 * skalaY, "c1"));
    board.push_back(new BoardTile(64 * skalaX, 128 * skalaY, "d1"));
    board.push_back(new BoardTile(80 * skalaX, 128 * skalaY, "e1"));
    board.push_back(new BoardTile(96 * skalaX, 128 * skalaY, "f1"));
    board.push_back(new BoardTile(112 * skalaX, 128 * skalaY, "g1"));
    board.push_back(new BoardTile(128 * skalaX, 128 * skalaY, "h1"));
}


void Game::Pressed() {
    if (eventy.type == sf::Event::MouseButtonPressed) {
        if (eventy.mouseButton.button == sf::Mouse::Left) {
            Mouse_pos = sf::Mouse::getPosition(*window);
            for (auto& el : PawnsVec) {
                el->chosen(Mouse_pos);
            }
        }
    }
    if (eventy.type == sf::Event::MouseMoved) {
        Mouse_pos = sf::Mouse::getPosition(*window);
        for (auto& el : PawnsVec) {
            el->Pick_up(Mouse_pos);
        }
    }
    if (eventy.type == sf::Event::MouseButtonReleased) {
        if (eventy.mouseButton.button == sf::Mouse::Left) {
            for (auto& el : PawnsVec) {
                el->unchosen(Mouse_pos);
            }
        }
    }
}
