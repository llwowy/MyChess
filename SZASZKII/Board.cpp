#include "Board.h"
#include "Board.h"
#include "BoardTile.h"

Board::Board()
{
    ;
}

void Board::CreateBoard() {
    sf::Color white = sf::Color(255, 255, 255);
    sf::Color black = sf::Color(0, 0, 0);
    this ->BoardVec.push_back(new BoardTile(16 * skalaX, 16 * skalaY, white, "a8"));
    this->BoardVec.push_back(new BoardTile(32 * skalaX, 16 * skalaY, black, "b8"));
    this->BoardVec.push_back(new BoardTile(48 * skalaX, 16 * skalaY, white, "c8"));
    this->BoardVec.push_back(new BoardTile(64 * skalaX, 16 * skalaY, black, "d8"));
    this->BoardVec.push_back(new BoardTile(80 * skalaX, 16 * skalaY, white, "e8"));
    this->BoardVec.push_back(new BoardTile(96 * skalaX, 16 * skalaY, black, "f8"));
    this->BoardVec.push_back(new BoardTile(112 * skalaX, 16 * skalaY, white, "g8"));
    this->BoardVec.push_back(new BoardTile(128 * skalaX, 16 * skalaY, black, "h8"));
    this->BoardVec.push_back(new BoardTile(16 * skalaX, 32 * skalaY, black, "a7"));
    this->BoardVec.push_back(new BoardTile(32 * skalaX, 32 * skalaY, white, "b7"));
    this->BoardVec.push_back(new BoardTile(48 * skalaX, 32 * skalaY, black, "c7"));
    this->BoardVec.push_back(new BoardTile(64 * skalaX, 32 * skalaY, white, "d7"));
    this->BoardVec.push_back(new BoardTile(80 * skalaX, 32 * skalaY, black, "e7"));
    this->BoardVec.push_back(new BoardTile(96 * skalaX, 32 * skalaY, white, "f7"));
    this->BoardVec.push_back(new BoardTile(112 * skalaX, 32 * skalaY, black, "g7"));
    this->BoardVec.push_back(new BoardTile(128 * skalaX, 32 * skalaY, white, "h7"));
    this->BoardVec.push_back(new BoardTile(16 * skalaX, 48 * skalaY, white, "a6"));
    this->BoardVec.push_back(new BoardTile(32 * skalaX, 48 * skalaY, black, "b6"));
    this->BoardVec.push_back(new BoardTile(48 * skalaX, 48 * skalaY, white, "c6"));
    this->BoardVec.push_back(new BoardTile(64 * skalaX, 48 * skalaY, black, "d6"));
    this->BoardVec.push_back(new BoardTile(80 * skalaX, 48 * skalaY, white, "e6"));
    this->BoardVec.push_back(new BoardTile(96 * skalaX, 48 * skalaY, black, "f6"));
    this->BoardVec.push_back(new BoardTile(112 * skalaX, 48 * skalaY, white, "g6"));
    this->BoardVec.push_back(new BoardTile(128 * skalaX, 48 * skalaY, black, "h6"));
    this->BoardVec.push_back(new BoardTile(16 * skalaX, 64 * skalaY, black, "a5"));
    this->BoardVec.push_back(new BoardTile(32 * skalaX, 64 * skalaY, white, "b5"));
    this->BoardVec.push_back(new BoardTile(48 * skalaX, 64 * skalaY, black, "c5"));
    this->BoardVec.push_back(new BoardTile(64 * skalaX, 64 * skalaY, white, "d5"));
    this->BoardVec.push_back(new BoardTile(80 * skalaX, 64 * skalaY, black, "e5"));
    this->BoardVec.push_back(new BoardTile(96 * skalaX, 64 * skalaY, white, "f5"));
    this->BoardVec.push_back(new BoardTile(112 * skalaX, 64 * skalaY, black, "g5"));
    this->BoardVec.push_back(new BoardTile(128 * skalaX, 64 * skalaY, white, "h5"));
    this->BoardVec.push_back(new BoardTile(16 * skalaX, 80 * skalaY, white, "a4"));
    this->BoardVec.push_back(new BoardTile(32 * skalaX, 80 * skalaY, black, "b4"));
    this->BoardVec.push_back(new BoardTile(48 * skalaX, 80 * skalaY, white, "c4"));
    this->BoardVec.push_back(new BoardTile(64 * skalaX, 80 * skalaY, black, "d4"));
    this->BoardVec.push_back(new BoardTile(80 * skalaX, 80 * skalaY, white, "e4"));
    this->BoardVec.push_back(new BoardTile(96 * skalaX, 80 * skalaY, black, "f4"));
    this->BoardVec.push_back(new BoardTile(112 * skalaX, 80 * skalaY, white, "g4"));
    this->BoardVec.push_back(new BoardTile(128 * skalaX, 80 * skalaY, black, "h4"));
    this->BoardVec.push_back(new BoardTile(16 * skalaX, 96 * skalaY, black, "a3"));
    this->BoardVec.push_back(new BoardTile(32 * skalaX, 96 * skalaY, white, "b3"));
    this->BoardVec.push_back(new BoardTile(48 * skalaX, 96 * skalaY, black, "c3"));
    this->BoardVec.push_back(new BoardTile(64 * skalaX, 96 * skalaY, white, "d3"));
    this->BoardVec.push_back(new BoardTile(80 * skalaX, 96 * skalaY, black, "e3"));
    this->BoardVec.push_back(new BoardTile(96 * skalaX, 96 * skalaY, white, "f3"));
    this->BoardVec.push_back(new BoardTile(750 * skalaX, 96 * skalaY, black, "g3"));
    this->BoardVec.push_back(new BoardTile(875 * skalaX, 96 * skalaY, white, "h3"));
    this->BoardVec.push_back(new BoardTile(16 * skalaX, 112 * skalaY, white, "a2"));
    this->BoardVec.push_back(new BoardTile(32 * skalaX, 112 * skalaY, black, "b2"));
    this->BoardVec.push_back(new BoardTile(48 * skalaX, 112 * skalaY, white, "c2"));
    this->BoardVec.push_back(new BoardTile(64 * skalaX, 112 * skalaY, black, "d2"));
    this->BoardVec.push_back(new BoardTile(80 * skalaX, 112 * skalaY, white, "e2"));
    this->BoardVec.push_back(new BoardTile(96 * skalaX, 112 * skalaY, black, "f2"));
    this->BoardVec.push_back(new BoardTile(112 * skalaX, 112 * skalaY, white, "g2"));
    this->BoardVec.push_back(new BoardTile(128 * skalaX, 112 * skalaY, black, "h2"));
    this->BoardVec.push_back(new BoardTile(16 * skalaX, 128 * skalaY, black, "a1"));
    this->BoardVec.push_back(new BoardTile(32 * skalaX, 128 * skalaY, white, "b1"));
    this->BoardVec.push_back(new BoardTile(48 * skalaX, 128 * skalaY, black, "c1"));
    this->BoardVec.push_back(new BoardTile(64 * skalaX, 128 * skalaY, white, "d1"));
    this->BoardVec.push_back(new BoardTile(80 * skalaX, 128 * skalaY, black, "e1"));
    this->BoardVec.push_back(new BoardTile(96 * skalaX, 128 * skalaY, white, "f1"));
    this->BoardVec.push_back(new BoardTile(112 * skalaX, 128 * skalaY, black, "g1"));
    this->BoardVec.push_back(new BoardTile(128 * skalaX, 128 * skalaY, white, "h1"));

    for (BoardTile*& el : board) {
        el->setTile();
    }
}

void Board::DrawBoard() {
    for (BoardTile*& el : BoardVec) {
        window.draw(*el);
    }
}