#include "BoardTile.h"
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h";
#include "Queen.h"
#include <memory>
#include <iostream>

///////////// TUTAJ POWINIEN BYĆ TYLKO MAIN, NIC WIĘCEJ, WSZYSTKO CO SIĘ TU DZIEJE POWINNO BYĆ METODAMI KLASY GRA ALBO INNYCH KLAS



//using Board = std::vector<BoardTile*>;
//
//void CreateBoard(Board& board) {
//    sf::Color white = sf::Color(255, 255, 255);
//    sf::Color black = sf::Color(0, 0, 0);
//    board.push_back(new BoardTile(16*skalaX, 16*skalaY, white, "a8"));
//    board.push_back(new BoardTile(32 * skalaX, 16 * skalaY, black, "b8"));
//    board.push_back(new BoardTile(48 * skalaX, 16 * skalaY, white, "c8"));
//    board.push_back(new BoardTile(64 * skalaX, 16 * skalaY, black, "d8"));
//    board.push_back(new BoardTile(80 * skalaX, 16 * skalaY, white, "e8"));
//    board.push_back(new BoardTile(96 * skalaX, 16 * skalaY, black, "f8"));
//    board.push_back(new BoardTile(112 * skalaX, 16 * skalaY, white, "g8"));
//    board.push_back(new BoardTile(128 * skalaX, 16 * skalaY, black, "h8"));
//    board.push_back(new BoardTile(16 * skalaX, 32 * skalaY, black, "a7"));
//    board.push_back(new BoardTile(32 * skalaX, 32 * skalaY, white, "b7"));
//    board.push_back(new BoardTile(48 * skalaX, 32 * skalaY, black, "c7"));
//    board.push_back(new BoardTile(64 * skalaX, 32 * skalaY, white, "d7"));
//    board.push_back(new BoardTile(80 * skalaX, 32 * skalaY, black, "e7"));
//    board.push_back(new BoardTile(96 * skalaX, 32 * skalaY, white, "f7"));
//    board.push_back(new BoardTile(112 * skalaX, 32 * skalaY, black, "g7"));
//    board.push_back(new BoardTile(128 * skalaX, 32 * skalaY, white, "h7"));
//    board.push_back(new BoardTile(16 * skalaX, 48 * skalaY, white, "a6"));
//    board.push_back(new BoardTile(32 * skalaX, 48 * skalaY, black, "b6"));
//    board.push_back(new BoardTile(48 * skalaX, 48 * skalaY, white, "c6"));
//    board.push_back(new BoardTile(64 * skalaX, 48 * skalaY, black, "d6"));
//    board.push_back(new BoardTile(80 * skalaX, 48 * skalaY, white, "e6"));
//    board.push_back(new BoardTile(96 * skalaX, 48 * skalaY, black, "f6"));
//    board.push_back(new BoardTile(112 * skalaX, 48 * skalaY, white, "g6"));
//    board.push_back(new BoardTile(128 * skalaX, 48 * skalaY, black, "h6"));
//    board.push_back(new BoardTile(16 * skalaX, 64 * skalaY, black, "a5"));
//    board.push_back(new BoardTile(32 * skalaX, 64 * skalaY, white, "b5"));
//    board.push_back(new BoardTile(48 * skalaX, 64 * skalaY, black, "c5"));
//    board.push_back(new BoardTile(64 * skalaX, 64 * skalaY, white, "d5"));
//    board.push_back(new BoardTile(80 * skalaX, 64 * skalaY, black, "e5"));
//    board.push_back(new BoardTile(96 * skalaX, 64 * skalaY, white, "f5"));
//    board.push_back(new BoardTile(112 * skalaX, 64 * skalaY, black, "g5"));
//    board.push_back(new BoardTile(128 * skalaX, 64 * skalaY, white, "h5"));
//    board.push_back(new BoardTile(16 * skalaX, 80 * skalaY, white, "a4"));
//    board.push_back(new BoardTile(32 * skalaX, 80 * skalaY, black, "b4"));
//    board.push_back(new BoardTile(48 * skalaX, 80 * skalaY, white, "c4"));
//    board.push_back(new BoardTile(64 * skalaX, 80 * skalaY, black, "d4"));
//    board.push_back(new BoardTile(80 * skalaX, 80 * skalaY, white, "e4"));
//    board.push_back(new BoardTile(96 * skalaX, 80 * skalaY, black, "f4"));
//    board.push_back(new BoardTile(112 * skalaX,80 * skalaY, white, "g4"));
//    board.push_back(new BoardTile(128 * skalaX, 80 * skalaY, black, "h4"));
//    board.push_back(new BoardTile(16 * skalaX, 96 *skalaY, black, "a3"));
//    board.push_back(new BoardTile(32 * skalaX, 96 * skalaY, white, "b3"));
//    board.push_back(new BoardTile(48 * skalaX, 96 * skalaY, black, "c3"));
//    board.push_back(new BoardTile(64 * skalaX, 96 * skalaY, white, "d3"));
//    board.push_back(new BoardTile(80 * skalaX, 96 * skalaY, black, "e3"));
//    board.push_back(new BoardTile(96 * skalaX, 96 * skalaY, white, "f3"));
//    board.push_back(new BoardTile(750 * skalaX, 96 * skalaY, black, "g3"));
//    board.push_back(new BoardTile(875 * skalaX, 96 * skalaY, white, "h3"));
//    board.push_back(new BoardTile(16 * skalaX, 112 * skalaY, white, "a2"));
//    board.push_back(new BoardTile(32 * skalaX, 112 * skalaY, black, "b2"));
//    board.push_back(new BoardTile(48 * skalaX, 112 * skalaY, white, "c2"));
//    board.push_back(new BoardTile(64 * skalaX, 112 * skalaY, black, "d2"));
//    board.push_back(new BoardTile(80 * skalaX, 112 * skalaY, white, "e2"));
//    board.push_back(new BoardTile(96 * skalaX, 112 * skalaY, black, "f2"));
//    board.push_back(new BoardTile(112 * skalaX, 112 * skalaY, white, "g2"));
//    board.push_back(new BoardTile(128 * skalaX, 112 * skalaY, black, "h2"));
//    board.push_back(new BoardTile(16 * skalaX, 128 * skalaY, black, "a1"));
//    board.push_back(new BoardTile(32 * skalaX, 128 * skalaY, white, "b1"));
//    board.push_back(new BoardTile(48 * skalaX, 128 * skalaY, black, "c1"));
//    board.push_back(new BoardTile(64 * skalaX, 128 * skalaY, white, "d1"));
//    board.push_back(new BoardTile(80 * skalaX, 128 * skalaY, black, "e1"));
//    board.push_back(new BoardTile(96 * skalaX, 128 * skalaY, white, "f1"));
//    board.push_back(new BoardTile(112 * skalaX, 128 * skalaY, black, "g1"));
//    board.push_back(new BoardTile(128 * skalaX, 128 * skalaY, white, "h1"));
//
//    for (BoardTile*& el : board) {
//        el->setTile();
//    }
//}



//void DrawBoard(sf::RenderWindow& window, Boardd& board) {
//    for (BoardTile*& el : board) {
//        window.draw(*el);
//    }
//}

int main() {

    auto Window_width = 1120;
    auto Window_height = 1120;

    sf::RenderWindow window(sf::VideoMode(Window_width, Window_height), "MyChess");

    //Board board;
  //  board.CreateBoard();
    /////////////////////////////////////
    
    Pawn a2("a2", sf::Vector2f(200,100)); // coś złego się stało z konstruktorem w piece albo pawn
    Pawn b2("b2", sf::Vector2f(300, 100));
    Pawn c2("c2", sf::Vector2f(400, 100));
    Pawn d2("d2", sf::Vector2f(500, 100));
    Pawn e2("e2", sf::Vector2f(600, 100));
    Pawn f2("f2", sf::Vector2f(700, 100));
    Pawn g2("g2", sf::Vector2f(800, 100));
    Pawn h2("h2", sf::Vector2f(900, 100));
   
  //  Rook a1("a1", board, "black");
  //  Rook h1("h1", board, "black");

  //  Knight b1("b1", board, "black");
  //  Knight g1("g1", board, "black");

  //  Bishop c1("c1", board, "black");
  //  Bishop f1("f1", board, "black");

  //  King d1("d1", board, "black");

  //  Queen e1("e1", board, "black");

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////

    sf::Texture chessBoard;
    if (!chessBoard.loadFromFile("Grafika/ChessTextures/chessBoardsWithBorder2.png")) {
        std::cout << "load chessBoard failed" << std::endl;
        system("pause");
    }
    
    sf::Sprite sprite;
    sprite.setTexture(chessBoard);
    sprite.setScale(7, 7);

    ///////////////////////////////////////
    ///////////////////////////////////////

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Red);

      //  board.DrawBoard();

        ////////////////////
        window.draw(sprite);
        window.draw(a2);//pawn
        window.draw(b2);
        window.draw(c2);
        window.draw(d2);
        window.draw(e2);
        window.draw(f2);
        window.draw(g2);
        window.draw(h2);
       // window.draw(a1);//rook
       // window.draw(h1);
       // window.draw(b1);//knight
       // window.draw(g1);
        //window.draw(c1);//bishop
       // window.draw(f1);
       // window.draw(d1);//king
       // window.draw(e1);//queen
        ////////////////////


        window.display();
    }

    return 0;
}