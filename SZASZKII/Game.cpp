
#include "Game.h"
#include <SFML/Main.hpp>

void Game::play() {
    //MENU

    /*
        while (menuwindow->isopen()) {
        allmenuevents();
        drawallonmenu(menuwindow);
        menuwindow->display();
    }    
    */

    //SZASZKII
  LoadBoard(board);
    readyGame();
    while (MenuWindow->isOpen())
    {
        allGameEvents();

        drawAllOnBoard(window);
        Pressed();
        window->display();
    }
}

void Game::readyMenuBackground() {
    if (!teksturaMenu.loadFromFile("Grafika/scroll/pngs/parts/paper.png")) { //tekstura menu
        std::cout << "load Menu Texture failed" << std::endl;
        system("pause");
    }
    MenuSprite.setTexture(teksturaMenu);
    MenuSprite.setScale(skalaXMenu, skalaYMenu);

    if (!upperScroll.loadFromFile("Grafika/scroll/pngs/parts/upper.png")) { //tekstura gornego zwoju
        std::cout << "load upperscroll Texture failed" << std::endl;
        system("pause");
    }
    upperScrollSprite.setTexture(upperScroll);
    //MenuSprite.setScale(skalaXMenu, skalaYMenu);

    if (!lowerScroll.loadFromFile("Grafika/scroll/pngs/parts/lower.png")) { //tekstura dolnego zwoju
        std::cout << "load lowerscroll Texture failed" << std::endl;
        system("pause");
    }
    lowerScrollSprite.setTexture(lowerScroll);
   // MenuSprite.setScale(skalaXMenu, skalaYMenu);
}


void Game::readyMenu() {
    readyMenuBackground();
    MenuWindow = new sf::RenderWindow(sf::VideoMode(MenuWindow_width, MenuWindow_height), "ChessMenu");

}


void Game::readyBackground() {
    if (!teksturaTla.loadFromFile("Grafika/ChessTextures/chessBoardsWithBorder2.png")) { //tekstura tla
        std::cout << "load chessBoard failed" << std::endl;
        system("pause");
    }
    BoardSprite.setTexture(teksturaTla);
    BoardSprite.setScale(skalaXBoard, skalaYBoard);
}


void Game::readyGame() {
    readyBackground();
    window = new sf::RenderWindow(sf::VideoMode(Window_width, Window_height), "MyChess");
    loadPawns();

}



void Game::readyFonsts() {
    if (!Menufont.loadFromFile("Fonts/amontesa/Amontesa.ttf")) { //czcionka menu
        std::cout << "load font failed" << std::endl;
        system("pause");
    }
    else { std::cout << "Loaded\n"; }
    Text.setFont(Menufont);
    Text.setString("Play");
    Text.setFillColor(sf::Color::Black);
    Text.setCharacterSize(60);
    Text.setPosition(1120/2 - 65 ,1120/2 - 50);
}


void Game::loadPawns() {
    //domyslnie czarne
    PawnsVec.push_back(new Pawn("a7", Black, P, board));
    PawnsVec.push_back(new Pawn("b7", Black, P, board));
    PawnsVec.push_back(new Pawn("c7", Black, P, board));
    PawnsVec.push_back(new Pawn("d7", Black, P, board));
    PawnsVec.push_back(new Pawn("e7", Black, P, board));
    PawnsVec.push_back(new Pawn("f7", Black, P, board));
    PawnsVec.push_back(new Pawn("g7", Black, P, board));
    PawnsVec.push_back(new Pawn("h7", Black, P, board));
    PawnsVec.push_back(new Rook("a8", Black, R, board));
    PawnsVec.push_back(new Rook("h8", Black, R, board));
    PawnsVec.push_back(new Knight("b8", Black, N, board));
    PawnsVec.push_back(new Knight("g8", Black, N, board));
    PawnsVec.push_back(new Bishop("c8", Black, B, board));
    PawnsVec.push_back(new Bishop("f8", Black, B, board));
    PawnsVec.push_back(new King("e8", Black, K, board));
    PawnsVec.push_back(new Queen("d8", Black, Q, board));
    //domyslnie biale
    PawnsVec.push_back(new Pawn("a2", White, P, board));
    PawnsVec.push_back(new Pawn("b2", White, P, board));
    PawnsVec.push_back(new Pawn("c2", White, P, board));
    PawnsVec.push_back(new Pawn("d2", White, P, board));
    PawnsVec.push_back(new Pawn("e2", White, P, board));
    PawnsVec.push_back(new Pawn("f2", White, P, board));
    PawnsVec.push_back(new Pawn("g2", White, P, board));
    PawnsVec.push_back(new Pawn("h2", White, P, board));
    PawnsVec.push_back(new Rook("a1", White, R, board));
    PawnsVec.push_back(new Rook("h1", White, R, board));
    PawnsVec.push_back(new Knight("b1", White, N, board));
    PawnsVec.push_back(new Knight("g1", White, N, board));
    PawnsVec.push_back(new Bishop("c1", White, B, board));
    PawnsVec.push_back(new Bishop("f1", White, B, board));
    PawnsVec.push_back(new King("e1", White, K, board));
    PawnsVec.push_back(new Queen("d1", White, Q, board));
}

void Game::drawAllOnMenu(sf::RenderWindow* window) {
    window->draw(MenuSprite);
    window-> draw(Text);
        //for (auto& paw_and_fig : PawnsVec) {
    //    window->draw(*paw_and_fig);
    //}
}


void Game::drawAllOnBoard(sf::RenderWindow* window) {
    window->draw(BoardSprite);
    for (auto& paw_and_fig : PawnsVec) {
        window->draw(*paw_and_fig);
    }
}

void Game::allGameEvents() {
    while (window->pollEvent(BoardEventy)) {
        if (BoardEventy.type == sf::Event::Closed)
            window->close();
    }
}

void Game::allMenuEvents() {
    sf::Event MenuEventy;

    while (MenuWindow->pollEvent(MenuEventy)) {
        if (MenuEventy.type == sf::Event::Closed) {
            MenuWindow->close();
        }

        if (MenuEventy.type == sf::Event::MouseButtonPressed) {
            if (MenuEventy.mouseButton.button == sf::Mouse::Left) {
                if (Text.getGlobalBounds().contains(sf::Mouse::getPosition(*MenuWindow).x, sf::Mouse::getPosition(*MenuWindow).y)) {
                    std::cout << "Pressed\n";
                }
            }
        }
    }
}


void Game::LoadBoard(Board& board) {
    board.push_back(new BoardTile(16 * skalaXBoard, 16 * skalaYBoard, "a8"));
    board.push_back(new BoardTile(32 * skalaXBoard, 16 * skalaYBoard, "b8"));
    board.push_back(new BoardTile(48 * skalaXBoard, 16 * skalaYBoard, "c8"));
    board.push_back(new BoardTile(64 * skalaXBoard, 16 * skalaYBoard, "d8"));
    board.push_back(new BoardTile(80 * skalaXBoard, 16 * skalaYBoard, "e8"));
    board.push_back(new BoardTile(96 * skalaXBoard, 16 * skalaYBoard, "f8"));
    board.push_back(new BoardTile(112 * skalaXBoard, 16 * skalaYBoard, "g8"));
    board.push_back(new BoardTile(128 * skalaXBoard, 16 * skalaYBoard, "h8"));
    board.push_back(new BoardTile(16 * skalaXBoard, 32 * skalaYBoard, "a7"));
    board.push_back(new BoardTile(32 * skalaXBoard, 32 * skalaYBoard, "b7"));
    board.push_back(new BoardTile(48 * skalaXBoard, 32 * skalaYBoard, "c7"));
    board.push_back(new BoardTile(64 * skalaXBoard, 32 * skalaYBoard, "d7"));
    board.push_back(new BoardTile(80 * skalaXBoard, 32 * skalaYBoard, "e7"));
    board.push_back(new BoardTile(96 * skalaXBoard, 32 * skalaYBoard, "f7"));
    board.push_back(new BoardTile(112 * skalaXBoard, 32 * skalaYBoard, "g7"));
    board.push_back(new BoardTile(128 * skalaXBoard, 32 * skalaYBoard, "h7"));
    board.push_back(new BoardTile(16 * skalaXBoard, 48 * skalaYBoard, "a6"));
    board.push_back(new BoardTile(32 * skalaXBoard, 48 * skalaYBoard, "b6"));
    board.push_back(new BoardTile(48 * skalaXBoard, 48 * skalaYBoard, "c6"));
    board.push_back(new BoardTile(64 * skalaXBoard, 48 * skalaYBoard, "d6"));
    board.push_back(new BoardTile(80 * skalaXBoard, 48 * skalaYBoard, "e6"));
    board.push_back(new BoardTile(96 * skalaXBoard, 48 * skalaYBoard, "f6"));
    board.push_back(new BoardTile(112 * skalaXBoard, 48 * skalaYBoard, "g6"));
    board.push_back(new BoardTile(128 * skalaXBoard, 48 * skalaYBoard, "h6"));
    board.push_back(new BoardTile(16 * skalaXBoard, 64 * skalaYBoard, "a5"));
    board.push_back(new BoardTile(32 * skalaXBoard, 64 * skalaYBoard, "b5"));
    board.push_back(new BoardTile(48 * skalaXBoard, 64 * skalaYBoard, "c5"));
    board.push_back(new BoardTile(64 * skalaXBoard, 64 * skalaYBoard, "d5"));
    board.push_back(new BoardTile(80 * skalaXBoard, 64 * skalaYBoard, "e5"));
    board.push_back(new BoardTile(96 * skalaXBoard, 64 * skalaYBoard, "f5"));
    board.push_back(new BoardTile(112 * skalaXBoard, 64 * skalaYBoard, "g5"));
    board.push_back(new BoardTile(128 * skalaXBoard, 64 * skalaYBoard, "h5"));
    board.push_back(new BoardTile(16 * skalaXBoard, 80 * skalaYBoard, "a4"));
    board.push_back(new BoardTile(32 * skalaXBoard, 80 * skalaYBoard, "b4"));
    board.push_back(new BoardTile(48 * skalaXBoard, 80 * skalaYBoard, "c4"));
    board.push_back(new BoardTile(64 * skalaXBoard, 80 * skalaYBoard, "d4"));
    board.push_back(new BoardTile(80 * skalaXBoard, 80 * skalaYBoard, "e4"));
    board.push_back(new BoardTile(96 * skalaXBoard, 80 * skalaYBoard, "f4"));
    board.push_back(new BoardTile(112 * skalaXBoard, 80 * skalaYBoard, "g4"));
    board.push_back(new BoardTile(128 * skalaXBoard, 80 * skalaYBoard, "h4"));
    board.push_back(new BoardTile(16 * skalaXBoard, 96 * skalaYBoard, "a3"));
    board.push_back(new BoardTile(32 * skalaXBoard, 96 * skalaYBoard, "b3"));
    board.push_back(new BoardTile(48 * skalaXBoard, 96 * skalaYBoard, "c3"));
    board.push_back(new BoardTile(64 * skalaXBoard, 96 * skalaYBoard, "d3"));
    board.push_back(new BoardTile(80 * skalaXBoard, 96 * skalaYBoard, "e3"));
    board.push_back(new BoardTile(96 * skalaXBoard, 96 * skalaYBoard, "f3"));
    board.push_back(new BoardTile(112 * skalaXBoard, 96 * skalaYBoard, "g3"));
    board.push_back(new BoardTile(128 * skalaXBoard, 96 * skalaYBoard, "h3"));
    board.push_back(new BoardTile(16 * skalaXBoard, 112 * skalaYBoard, "a2"));
    board.push_back(new BoardTile(32 * skalaXBoard, 112 * skalaYBoard, "b2"));
    board.push_back(new BoardTile(48 * skalaXBoard, 112 * skalaYBoard, "c2"));
    board.push_back(new BoardTile(64 * skalaXBoard, 112 * skalaYBoard, "d2"));
    board.push_back(new BoardTile(80 * skalaXBoard, 112 * skalaYBoard, "e2"));
    board.push_back(new BoardTile(96 * skalaXBoard, 112 * skalaYBoard, "f2"));
    board.push_back(new BoardTile(112 * skalaXBoard, 112 * skalaYBoard, "g2"));
    board.push_back(new BoardTile(128 * skalaXBoard, 112 * skalaYBoard, "h2"));
    board.push_back(new BoardTile(16 * skalaXBoard, 128 * skalaYBoard, "a1"));
    board.push_back(new BoardTile(32 * skalaXBoard, 128 * skalaYBoard, "b1"));
    board.push_back(new BoardTile(48 * skalaXBoard, 128 * skalaYBoard, "c1"));
    board.push_back(new BoardTile(64 * skalaXBoard, 128 * skalaYBoard, "d1"));
    board.push_back(new BoardTile(80 * skalaXBoard, 128 * skalaYBoard, "e1"));
    board.push_back(new BoardTile(96 * skalaXBoard, 128 * skalaYBoard, "f1"));
    board.push_back(new BoardTile(112 * skalaXBoard, 128 * skalaYBoard, "g1"));
    board.push_back(new BoardTile(128 * skalaXBoard, 128 * skalaYBoard, "h1"));
}


void Game::Pressed() {//do pionkow
    for (auto& el : board) {
        el->set_Tile_marked_for_Black(false);
        el->set_Tile_marked_for_White(false);
    }
    for (auto& el : PawnsVec) {
        el->mark_Tiles(board, PawnsVec);
    }

    if (BoardEventy.type == sf::Event::MouseButtonPressed) {
        if (BoardEventy.mouseButton.button == sf::Mouse::Left) {
            Mouse_pos = sf::Mouse::getPosition(*window);
            for (auto& el : PawnsVec) {
                el->chosen(Mouse_pos);
            }
        }
    }
    if (BoardEventy.type == sf::Event::MouseMoved) {
        Mouse_pos = sf::Mouse::getPosition(*window);
        for (auto& el : PawnsVec) {
            el->Pick_up(Mouse_pos);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false) {
            for (auto& el : PawnsVec) {
                el->move(board, Mouse_pos, PawnsVec);
                el->take(board, Mouse_pos, PawnsVec);
                el->unchosen(Mouse_pos);
            }
        }
    }
    if (BoardEventy.type == sf::Event::MouseButtonReleased) {
        if (BoardEventy.mouseButton.button == sf::Mouse::Left) {
            Mouse_pos = sf::Mouse::getPosition(*window);
            for (auto& el : PawnsVec) {
                el->move(board, Mouse_pos, PawnsVec);
                el->take(board, Mouse_pos, PawnsVec);
                el->unchosen(Mouse_pos);
            }
        }
    }
    
}

void Game::getStartMenu(sf::Event& e, sf::RenderWindow* window)
{

}
