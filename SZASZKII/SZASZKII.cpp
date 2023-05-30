#include "BoardTile.h"
#include <memory>
#include <iostream>

float skalaX = 7;
float skalaY = 7;


using Board = std::vector<BoardTile*>;

void CreateBoard(Board& board) {
    sf::Color white = sf::Color(255, 255, 255);
    sf::Color black = sf::Color(0, 0, 0);
    board.push_back(new BoardTile(16*skalaX, 16*skalaY, white, "a8"));
    board.push_back(new BoardTile(32 * skalaX, 16 * skalaY, black, "b8"));
    board.push_back(new BoardTile(48 * skalaX, 16 * skalaY, white, "c8"));
    board.push_back(new BoardTile(64 * skalaX, 16 * skalaY, black, "d8"));
    board.push_back(new BoardTile(80 * skalaX, 16 * skalaY, white, "e8"));
    board.push_back(new BoardTile(96 * skalaX, 16 * skalaY, black, "f8"));
    board.push_back(new BoardTile(112 * skalaX, 16 * skalaY, white, "g8"));
    board.push_back(new BoardTile(128 * skalaX, 16 * skalaY, black, "h8"));
    board.push_back(new BoardTile(16 * skalaX, 32 * skalaY, black, "a7"));
    board.push_back(new BoardTile(32 * skalaX, 32 * skalaY, white, "b7"));
    board.push_back(new BoardTile(48 * skalaX, 32 * skalaY, black, "c7"));
    board.push_back(new BoardTile(64 * skalaX, 32 * skalaY, white, "d7"));
    board.push_back(new BoardTile(80 * skalaX, 32 * skalaY, black, "e7"));
    board.push_back(new BoardTile(96 * skalaX, 32 * skalaY, white, "f7"));
    board.push_back(new BoardTile(112 * skalaX, 32 * skalaY, black, "g7"));
    board.push_back(new BoardTile(128 * skalaX, 32 * skalaY, white, "h7"));
    board.push_back(new BoardTile(16 * skalaX, 48 * skalaY, white, "a6"));
    board.push_back(new BoardTile(32 * skalaX, 48 * skalaY, black, "b6"));
    board.push_back(new BoardTile(48 * skalaX, 48 * skalaY, white, "c6"));
    board.push_back(new BoardTile(64 * skalaX, 48 * skalaY, black, "d6"));
    board.push_back(new BoardTile(80 * skalaX, 48 * skalaY, white, "e6"));
    board.push_back(new BoardTile(96 * skalaX, 48 * skalaY, black, "f6"));
    board.push_back(new BoardTile(112 * skalaX, 48 * skalaY, white, "g6"));
    board.push_back(new BoardTile(128 * skalaX, 48 * skalaY, black, "h6"));
    board.push_back(new BoardTile(16 * skalaX, 64 * skalaY, black, "a5"));
    board.push_back(new BoardTile(32 * skalaX, 64 * skalaY, white, "b5"));
    board.push_back(new BoardTile(48 * skalaX, 64 * skalaY, black, "c5"));
    board.push_back(new BoardTile(64 * skalaX, 64 * skalaY, white, "d5"));
    board.push_back(new BoardTile(80 * skalaX, 64 * skalaY, black, "e5"));
    board.push_back(new BoardTile(96 * skalaX, 64 * skalaY, white, "f5"));
    board.push_back(new BoardTile(112 * skalaX, 64 * skalaY, black, "g5"));
    board.push_back(new BoardTile(128 * skalaX, 64 * skalaY, white, "h5"));
    board.push_back(new BoardTile(16 * skalaX, 80 * skalaY, white, "a4"));
    board.push_back(new BoardTile(32 * skalaX, 80 * skalaY, black, "b4"));
    board.push_back(new BoardTile(48 * skalaX, 80 * skalaY, white, "c4"));
    board.push_back(new BoardTile(64 * skalaX, 80 * skalaY, black, "d4"));
    board.push_back(new BoardTile(80 * skalaX, 80 * skalaY, white, "e4"));
    board.push_back(new BoardTile(96 * skalaX, 80 * skalaY, black, "f4"));
    board.push_back(new BoardTile(112 * skalaX,80 * skalaY, white, "g4"));
    board.push_back(new BoardTile(128 * skalaX, 80 * skalaY, black, "h4"));
    board.push_back(new BoardTile(16 * skalaX, 96 *skalaY, black, "a3"));
    board.push_back(new BoardTile(32 * skalaX, 96 * skalaY, white, "b3"));
    board.push_back(new BoardTile(48 * skalaX, 96 * skalaY, black, "c3"));
    board.push_back(new BoardTile(64 * skalaX, 96 * skalaY, white, "d3"));
    board.push_back(new BoardTile(80 * skalaX, 96 * skalaY, black, "e3"));
    board.push_back(new BoardTile(96 * skalaX, 96 * skalaY, white, "f3"));
    board.push_back(new BoardTile(750 * skalaX, 96 * skalaY, black, "g3"));
    board.push_back(new BoardTile(875 * skalaX, 96 * skalaY, white, "h3"));
    board.push_back(new BoardTile(16 * skalaX, 112 * skalaY, white, "a2"));
    board.push_back(new BoardTile(32 * skalaX, 112 * skalaY, black, "b2"));
    board.push_back(new BoardTile(48 * skalaX, 112 * skalaY, white, "c2"));
    board.push_back(new BoardTile(64 * skalaX, 112 * skalaY, black, "d2"));
    board.push_back(new BoardTile(80 * skalaX, 112 * skalaY, white, "e2"));
    board.push_back(new BoardTile(96 * skalaX, 112 * skalaY, black, "f2"));
    board.push_back(new BoardTile(112 * skalaX, 112 * skalaY, white, "g2"));
    board.push_back(new BoardTile(128 * skalaX, 112 * skalaY, black, "h2"));
    board.push_back(new BoardTile(16 * skalaX, 128 * skalaY, black, "a1"));
    board.push_back(new BoardTile(32 * skalaX, 128 * skalaY, white, "b1"));
    board.push_back(new BoardTile(48 * skalaX, 128 * skalaY, black, "c1"));
    board.push_back(new BoardTile(64 * skalaX, 128 * skalaY, white, "d1"));
    board.push_back(new BoardTile(80 * skalaX, 128 * skalaY, black, "e1"));
    board.push_back(new BoardTile(96 * skalaX, 128 * skalaY, white, "f1"));
    board.push_back(new BoardTile(112 * skalaX, 128 * skalaY, black, "g1"));
    board.push_back(new BoardTile(128 * skalaX, 128 * skalaY, white, "h1"));

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

    auto Window_width = 1120;
    auto Window_height = 1120;

    sf::RenderWindow window(sf::VideoMode(Window_width, Window_height), "MyChess");

    Board board;
    CreateBoard(board);


    ///////////////////////////////////////
    ///////////////////////////////////////

    sf::Texture chessBoard;
    if (!chessBoard.loadFromFile("Grafika/ChessTextures/chessBoardsWithBorder2.png")) {
        std::cout << "load chessBoard failed" << std::endl;
        system("pause");
    }
    //chessBoard.setRepeated(true);//to też do wyjebki
    sf::Sprite sprite;
    sprite.setTexture(chessBoard);
    sprite.setScale(skalaX, skalaY);
    //sprite.setTextureRect(sf::IntRect(0, 125, 1000, 1125));//do wyjebki

    ///////////////////////////////////////
    ///////////////////////////////////////

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Red);

        DrawBoard(window, board);

        ////////////////////
        window.draw(sprite);
        ////////////////////


        window.display();
    }

    return 0;
}