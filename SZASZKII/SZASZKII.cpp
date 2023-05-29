#include "BoardTile.h"
#include <memory>
#include <iostream>

using Board = std::vector<BoardTile*>;
//chhhhhhhhhhhhhhuj cIPA DUPA
void CreateBoard(Board& board) {
    sf::Color white = sf::Color(255, 255, 255);
    sf::Color black = sf::Color(0, 0, 0);
    board.push_back(new BoardTile(0, 100, white, "a8"));
    board.push_back(new BoardTile(125, 100, black, "b8"));
    board.push_back(new BoardTile(250, 100, white, "c8"));
    board.push_back(new BoardTile(375, 100, black, "d8"));
    board.push_back(new BoardTile(500, 100, white, "e8"));
    board.push_back(new BoardTile(625, 100, black, "f8"));
    board.push_back(new BoardTile(750, 100, white, "g8"));
    board.push_back(new BoardTile(875, 100, black, "h8"));
    board.push_back(new BoardTile(0, 225, black, "a7"));
    board.push_back(new BoardTile(125, 225, white, "b7"));
    board.push_back(new BoardTile(250, 225, black, "c7"));
    board.push_back(new BoardTile(375, 225, white, "d7"));
    board.push_back(new BoardTile(500, 225, black, "e7"));
    board.push_back(new BoardTile(625, 225, white, "f7"));
    board.push_back(new BoardTile(750, 225, black, "g7"));
    board.push_back(new BoardTile(875, 225, white, "h7"));
    board.push_back(new BoardTile(0, 350, white, "a6"));
    board.push_back(new BoardTile(125, 350, black, "b6"));
    board.push_back(new BoardTile(250, 350, white, "c6"));
    board.push_back(new BoardTile(375, 350, black, "d6"));
    board.push_back(new BoardTile(500, 350, white, "e6"));
    board.push_back(new BoardTile(625, 350, black, "f6"));
    board.push_back(new BoardTile(750, 350, white, "g6"));
    board.push_back(new BoardTile(875, 350, black, "h6"));
    board.push_back(new BoardTile(0, 475, black, "a5"));
    board.push_back(new BoardTile(125, 475, white, "b5"));
    board.push_back(new BoardTile(250, 475, black, "c5"));
    board.push_back(new BoardTile(375, 475, white, "d5"));
    board.push_back(new BoardTile(500, 475, black, "e5"));
    board.push_back(new BoardTile(625, 475, white, "f5"));
    board.push_back(new BoardTile(750, 475, black, "g5"));
    board.push_back(new BoardTile(875, 475, white, "h5"));
    board.push_back(new BoardTile(0, 600, white, "a4"));
    board.push_back(new BoardTile(125, 600, black, "b4"));
    board.push_back(new BoardTile(250, 600, white, "c4"));
    board.push_back(new BoardTile(375, 600, black, "d4"));
    board.push_back(new BoardTile(500, 600, white, "e4"));
    board.push_back(new BoardTile(625, 600, black, "f4"));
    board.push_back(new BoardTile(750, 600, white, "g4"));
    board.push_back(new BoardTile(875, 600, black, "h4"));
    board.push_back(new BoardTile(0, 725, black, "a3"));
    board.push_back(new BoardTile(125, 725, white, "b3"));
    board.push_back(new BoardTile(250, 725, black, "c3"));
    board.push_back(new BoardTile(375, 725, white, "d3"));
    board.push_back(new BoardTile(500, 725, black, "e3"));
    board.push_back(new BoardTile(625, 725, white, "f3"));
    board.push_back(new BoardTile(750, 725, black, "g3"));
    board.push_back(new BoardTile(875, 725, white, "h3"));
    board.push_back(new BoardTile(0, 850, white, "a2"));
    board.push_back(new BoardTile(125, 850, black, "b2"));
    board.push_back(new BoardTile(250, 850, white, "c2"));
    board.push_back(new BoardTile(375, 850, black, "d2"));
    board.push_back(new BoardTile(500, 850, white, "e2"));
    board.push_back(new BoardTile(625, 850, black, "f2"));
    board.push_back(new BoardTile(750, 850, white, "g2"));
    board.push_back(new BoardTile(875, 850, black, "h2"));
    board.push_back(new BoardTile(0, 975, black, "a1"));
    board.push_back(new BoardTile(125, 975, white, "b1"));
    board.push_back(new BoardTile(250, 975, black, "c1"));
    board.push_back(new BoardTile(375, 975, white, "d1"));
    board.push_back(new BoardTile(500, 975, black, "e1"));
    board.push_back(new BoardTile(625, 975, white, "f1"));
    board.push_back(new BoardTile(750, 975, black, "g1"));
    board.push_back(new BoardTile(875, 975, white, "h1"));

    for (BoardTile*& el : board) {
        el->setTile();
    }
}

void DrawBoard(sf::RenderWindow& window, Board& board) {
    for (BoardTile*& el : board) {
        window.draw(*el);
    }
}

int main() {

    auto Window_width = 1200;
    auto Window_height = 1000;

    sf::RenderWindow window(sf::VideoMode(Window_width, Window_height), "MyChess");

    Board board;
    CreateBoard(board);



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Red);

        DrawBoard(window, board);


        window.display();
    }

    return 0;
}