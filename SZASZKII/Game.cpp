
#include "Game.h"
#include <SFML/Main.hpp>

void Game::play() {
    //MENU
    MenuWindow->setFramerateLimit(60);
        while (MenuWindow->isOpen()) {
            MenuWindow->setSize(sf::Vector2u(MenuWindow_width, MenuWindow_height));
            allMenuEvents();
            drawAllOnMenu(MenuWindow);
            MenuWindow->display();
        }
    //SZASZKII
        if (play_chess == true) {
        LoadBoard(board);
        readyGame();

            while (window->isOpen()) {
                window->setSize(sf::Vector2u(Window_width, Window_height));
                allGameEvents();
                drawAllOnBoard(window);
                Pressed();
                window->display();
                clockMenu.restart();
                timer += clock.restart().asSeconds();
                if (timer > 0.2) {
                 counter++;
                  timer = 0;
                } 
                clock.restart();
                if_end_block_Pieces(WhiteWin, BlackWin, PawnsVec);
            }
        }
        if (check_whether_Black_or_white_win(WhiteWin, BlackWin)) {
        play_chess == false;
        readyKoniec();
        while (KoniecWindow->isOpen())

        {   KoniecWindow->setSize(sf::Vector2u(KoniecWindow_width, KoniecWindow_height));
            allKoniecEvents();
            drawAllOnKoniec(KoniecWindow);
            KoniecWindow->display();
        }
    }
}

Game::Game() {
    readyMenu();
    readyFonsts();
}

void Game::start_txt() {
    std::system("cls");
    std::ofstream partia;
    partia.open("Dziennik_rozegranych_partii.txt", std::ios::app);

    partia  << "Partia szachowa z dnia: " << __DATE__ << ". Partia rozpoczela sie o: " << __TIME__ << std::endl << "Przebieg partii: " << std::endl<< "\n";

    partia.close();
}

void Game::end_txt() {

    std::ofstream partia;
    partia.open("Dziennik_rozegranych_partii.txt", std::ios::app);

    partia << std::endl;

    if (WhiteWin == true) {
        partia << "Wygraly biale! ";
    }
    else if (BlackWin == true) {
        partia << "Wygraly czarne! ";
    }
    else  {
        partia << "Remis! ";
    }

    partia << std::endl << std::endl <<"Koncowa konfiguracja szachownicy: " << std::endl << PawnsVec << std::endl << std::endl;
    partia.close();
}

std::ostream& operator<<(std::ostream& os,  std::vector<Piece*> PawnsVec) {

    for (const auto& el : PawnsVec) {

        std::string color;

        if (el->get_Piece_color() == 0 || el->get_Piece_color() == 2) {
            color = "w";
        }
        else if (el->get_Piece_color() == 1 || el->get_Piece_color() == 3) {
            color = "b";
        }

        std::string type;

        if (el->get_Piece_type() == P) {
            type = "p";
        }
        else if (el->get_Piece_type() == R || el->get_Piece_type() == R1) {
            type = "r";
        }
        else if (el->get_Piece_type() == N) {
            type = "n";
        }
        else if (el->get_Piece_type() == B) {
            type = "b";
        }
        else if (el->get_Piece_type() == Q) {
            type = "q";
        }
        else if (el->get_Piece_type() == K) {
            type = "k";
        }

        std::string pos;

        auto position = el->getPosition();

        if (position.x == 112 && position.y == 112) {
            pos = "a8";
        }
        else if (position.x == 112 && position.y == 224) {
            pos = "a7";
        }
        else if (position.x == 112 && position.y == 336) {
            pos = "a6";
        }
        else if (position.x == 112 && position.y == 448) {
            pos = "a5";
        }
        else if (position.x == 112 && position.y == 560) {
            pos = "a4";
        }
        else if (position.x == 112 && position.y == 672) {
            pos = "a3";
        }
        else if (position.x == 112 && position.y == 784) {
            pos = "a2";
        }
        else if (position.x == 112 && position.y == 896) {
            pos = "a1";
        }


        else if (position.x == 224 && position.y == 112) {
            pos = "b8";
        }
        else if (position.x == 224 && position.y == 224) {
            pos = "b7";
        }
        else if (position.x == 224 && position.y == 336) {
            pos = "b6";
        }
        else if (position.x == 224 && position.y == 448) {
            pos = "b5";
        }
        else if (position.x == 224 && position.y == 560) {
            pos = "b4";
        }
        else if (position.x == 224 && position.y == 672) {
            pos = "b3";
        }
        else if (position.x == 224 && position.y == 784) {
            pos = "b2";
        }
        else if (position.x == 224 && position.y == 896) {
            pos = "b1";
        }

        else if (position.x == 336 && position.y == 112) {
            pos = "c8";
        }
        else if (position.x == 336 && position.y == 224) {
            pos = "c7";
        }
        else if (position.x == 336 && position.y == 336) {
            pos = "c6";
        }
        else if (position.x == 336 && position.y == 448) {
            pos = "c5";
        }
        else if (position.x == 336 && position.y == 560) {
            pos = "c4";
        }
        else if (position.x == 336 && position.y == 672) {
            pos = "c3";
        }
        else if (position.x == 336 && position.y == 784) {
            pos = "c2";
        }
        else if (position.x == 336 && position.y == 896) {
            pos = "c1";
        }


        else if (position.x == 448 && position.y == 112) {
            pos = "d8";
        }
        else if (position.x == 448 && position.y == 224) {
            pos = "d7";
        }
        else if (position.x == 448 && position.y == 336) {
            pos = "d6";
        }
        else if (position.x == 448 && position.y == 448) {
            pos = "d5";
        }
        else if (position.x == 448 && position.y == 560) {
            pos = "d4";
        }
        else if (position.x == 448 && position.y == 672) {
            pos = "d3";
        }
        else if (position.x == 448 && position.y == 784) {
            pos = "d2";
        }
        else if (position.x == 448 && position.y == 896) {
            pos = "d1";
        }


        else if (position.x == 560 && position.y == 112) {
            pos = "e8";
        }
        else if (position.x == 560 && position.y == 224) {
            pos = "e7";
        }
        else if (position.x == 560 && position.y == 336) {
            pos = "e6";
        }
        else if (position.x == 560 && position.y == 448) {
            pos = "e5";
        }
        else if (position.x == 560 && position.y == 560) {
            pos = "e4";
        }
        else if (position.x == 560 && position.y == 672) {
            pos = "e3";
        }
        else if (position.x == 560 && position.y == 784) {
            pos = "e2";
        }
        else if (position.x == 560 && position.y == 896) {
            pos = "e1";
        }

        else if (position.x == 672 && position.y == 112) {
            pos = "f8";
        }
        else if (position.x == 672 && position.y == 224) {
            pos = "f7";
        }
        else if (position.x == 672 && position.y == 336) {
            pos = "f6";
        }
        else if (position.x == 672 && position.y == 448) {
            pos = "f5";
        }
        else if (position.x == 672 && position.y == 560) {
            pos = "f4";
        }
        else if (position.x == 672 && position.y == 672) {
            pos = "f3";
        }
        else if (position.x == 672 && position.y == 784) {
            pos = "f2";
        }
        else if (position.x == 672 && position.y == 896) {
            pos = "f1";
        }

        else if (position.x == 784 && position.y == 112) {
            pos = "g8";
        }
        else if (position.x == 784 && position.y == 224) {
            pos = "g7";
        }
        else if (position.x == 784 && position.y == 336) {
            pos = "g6";
        }
        else if (position.x == 784 && position.y == 448) {
            pos = "g5";
        }
        else if (position.x == 784 && position.y == 560) {
            pos = "g4";
        }
        else if (position.x == 784 && position.y == 672) {
            pos = "g3";
        }
        else if (position.x == 784 && position.y == 784) {
            pos = "g2";
        }
        else if (position.x == 784 && position.y == 896) {
            pos = "g1";
        }

        else if (position.x == 896 && position.y == 112) {
            pos = "h8";
        }
        else if (position.x == 896 && position.y == 224) {
            pos = "h7";
        }
        else if (position.x == 896 && position.y == 336) {
            pos = "h6";
        }
        else if (position.x == 896 && position.y == 448) {
            pos = "h5";
        }
        else if (position.x == 896 && position.y == 560) {
            pos = "h4";
        }
        else if (position.x == 896 && position.y == 672) {
            pos = "h3";
        }
        else if (position.x == 896 && position.y == 784) {
            pos = "h2";
        }
        else if (position.x == 896 && position.y == 896) {
            pos = "h1";
        }

        else if (pos.empty()) {
            color = "";
            type = "";
        }

        os << color + type + pos << " ";

    }
  return os;
}



void Game::readyMenuBackground() {
    if (!teksturaMenu.loadFromFile("Grafika/bg1.png")) {
        std::cout << "load Menu Texture failed" << std::endl;
        system("pause");
    }
    MenuSprite.setTexture(teksturaMenu);
    MenuSprite.setScale(skalaXMenu, skalaYMenu);

}

void Game::readyKoniecBackground()
{
    if (!teksturaKoniec.loadFromFile("Grafika/cat.jpg")) { //tekstura dolnego zwoju
        std::cout << "load koniec tlo Texture failed" << std::endl;
        system("pause");
    }
    KoniecSprite.setTexture(teksturaKoniec);


    if (!tekBialyPion.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
        std::cout << "load koniec bialy pion Texture failed" << std::endl;
        system("pause");
    }
   
    BialyPionSprite.setTexture(tekBialyPion);
    BialyPionSprite.setTextureRect(sf::IntRect(0, 96, 16, 16)); //bialy
    BialyPionSprite.setScale(-19, 19);
    BialyPionSprite.setPosition(KoniecWindow_width / 2 - 280, KoniecWindow_height / 2 + 10);


    if (!tekCzarnyPion.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
        std::cout << "load koniec czarny pion Texture failed" << std::endl;
        system("pause");
    }
    CzarnyPionSprite.setTexture(tekCzarnyPion);
    CzarnyPionSprite.setTextureRect(sf::IntRect(80, 96, 16, 16)); //czarny
    CzarnyPionSprite.setScale(-19, 19);
    CzarnyPionSprite.setPosition(KoniecWindow_width / 2 - 280, KoniecWindow_height / 2 + 10);


    if (!tekZielonyPion.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
        std::cout << "load koniec czarny pion Texture failed" << std::endl;
        system("pause");
    }
    ZielonyPionSprite.setTexture(tekZielonyPion);
    ZielonyPionSprite.setTextureRect(sf::IntRect(80, 0, 16, 16));//zielony
    ZielonyPionSprite.setScale(-19, 19);
    ZielonyPionSprite.setPosition(KoniecWindow_width / 2 - 280, KoniecWindow_height / 2 + 10);


    if (!tekNiebieskiPion.loadFromFile("Grafika/ChessTextures/Chess Pieces.png")) {
        std::cout << "load koniec czarny pion Texture failed" << std::endl;
        system("pause");
    }
    NiebieskiPionSprite.setTexture(tekNiebieskiPion);
    NiebieskiPionSprite.setTextureRect(sf::IntRect(0, 0, 16, 16)); //niebieski
    NiebieskiPionSprite.setScale(-19, 19);
    NiebieskiPionSprite.setPosition(KoniecWindow_width / 2 - 280, KoniecWindow_height / 2 + 10);

}


void Game::readyMenu() {
    readyMenuBackground();
    MenuWindow = new sf::RenderWindow(sf::VideoMode(MenuWindow_width, MenuWindow_height), "ChessMenu");

}


void Game::readyKoniec() {
    readyKoniecBackground();
    KoniecWindow = new sf::RenderWindow(sf::VideoMode(KoniecWindow_width, KoniecWindow_height), "Congratulations!!");
    end_txt();
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
    start_txt();
    set_that_Piece_can_be_chosen(PawnsVec);
}



void Game::readyFonsts() {
    if (!Menufont.loadFromFile("Fonts/karma/KarmaFuture.ttf")) { //czcionka menu
        std::cout << "load font failed" << std::endl;
        system("pause");
    }
    else { std::cout << "Loaded\n"; }
    ///Napis Menu
    Title.setFont(Menufont);
    Title.setString("8-bit Chess");
    Title.setFillColor(sf::Color::White);
    Title.setCharacterSize(130);
    Title.setPosition(1120 / 2 - 350, 1120 / 2 - 420);
    ///Napis Menu
    Text.setFont(Menufont);
    Text.setString("- Play Chess");
    Text.setFillColor(sf::Color::White);
    Text.setCharacterSize(80);
    Text.setPosition(1120/2 - 260 ,1120/2 - 190);
    ///Napis Menu
    Conf1.setFont(Menufont);
    Conf1.setString("- Black & White");
    Conf1.setFillColor(sf::Color::White);
    Conf1.setCharacterSize(80);
    Conf1.setPosition(1120 / 2 - 260, 1120 / 2 -40 );
    ///Napis Menu
    Conf2.setFont(Menufont);
    Conf2.setString("- Green & Blue");
    Conf2.setFillColor(sf::Color::White);
    Conf2.setCharacterSize(80);
    Conf2.setPosition(1120 / 2 - 260, 1120 / 2 + 110);
    // Historia
    History.setFont(Menufont);
    History.setString("- History");
    History.setFillColor(sf::Color::White);
    History.setCharacterSize(80);
    History.setPosition(1120 / 2 - 260, 1120 / 2 + 260);


    //Napis koñcowy
    KoniecText.setFont(Menufont);
    KoniecText.setString("Better player wins! ;)");
    KoniecText.setFillColor(sf::Color::White);
    KoniecText.setCharacterSize(70);
    KoniecText.setPosition(KoniecWindow_width / 2 - 320, KoniecWindow_height / 2 + 150);

    //Napis koñcowy
    Restart.setFont(Menufont);
    Restart.setString("- Menu");
    Restart.setFillColor(sf::Color::White);
    Restart.setCharacterSize(80);
    Restart.setPosition(KoniecWindow_width / 2 - 330, KoniecWindow_height / 2 - 450);

}


void Game::loadPawns() {

    //domyslnie czarne
    PawnsVec.push_back(new Pawn("a7", Black, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("b7", Black, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("c7", Black, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("d7", Black, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("e7", Black, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("f7", Black, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("g7", Black, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("h7", Black, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Rook("a8", Black, R1, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Rook("h8", Black, R, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Knight("b8", Black, N, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Knight("g8", Black, N, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Bishop("c8", Black, B, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Bishop("f8", Black, B, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new King("e8", Black, K, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Queen("d8", Black, Q, board, BlackAndWhite, GreenAndBlue));
    //domyslnie biale
    PawnsVec.push_back(new Pawn("a2", White, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("b2", White, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("c2", White, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("d2", White, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("e2", White, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("f2", White, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("g2", White, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Pawn("h2", White, P, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Rook("a1", White, R1, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Rook("h1", White, R, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Knight("b1", White, N, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Knight("g1", White, N, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Bishop("c1", White, B, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Bishop("f1", White, B, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new King("e1", White, K, board, BlackAndWhite, GreenAndBlue));
    PawnsVec.push_back(new Queen("d1", White, Q, board, BlackAndWhite, GreenAndBlue));
}

void Game::drawAllOnMenu(sf::RenderWindow* window) {
    window->draw(MenuSprite);
    window-> draw(Text);
    window->draw(Title);
    window->draw(Conf1);
    window->draw(Conf2);
    window->draw(History);
}

void Game::drawAllOnKoniec(sf::RenderWindow* window) {
    window->draw(KoniecSprite);
    if (WhiteWin == true && BlackAndWhite == true) { window->draw(BialyPionSprite); }
    if (BlackWin == true && BlackAndWhite == true){ window->draw(CzarnyPionSprite); }
    if (WhiteWin == true && GreenAndBlue == true) { window->draw(NiebieskiPionSprite); }
    if (BlackWin == true && GreenAndBlue == true) { window->draw(ZielonyPionSprite); }
    window->draw(KoniecText);
    window->draw(Restart);
  

}

void Game::drawAllOnBoard(sf::RenderWindow* window) {
    window->draw(BoardSprite);
    for (auto& paw_and_fig : PawnsVec) {
        window->draw(*paw_and_fig);
    }
}

void Game::meow() {
    

    if (!buffer.loadFromFile("Grafika/cat.wav"))
    {
        std::cout << "Nieznaleziono dzwieku";
    }


    sound.setBuffer(buffer);

    sound.play();
}

void Game::allKoniecEvents() {
    sf::Event KoniecEventy;
    
    while (KoniecWindow->pollEvent(KoniecEventy)) {
        if (KoniecEventy.type == sf::Event::Closed)
            KoniecWindow->close();


        if (KoniecEventy.type == sf::Event::MouseButtonPressed) {
            if (KoniecEventy.mouseButton.button == sf::Mouse::Left) {
                if (Restart.getGlobalBounds().contains(sf::Mouse::getPosition(*KoniecWindow).x, sf::Mouse::getPosition(*KoniecWindow).y)) {
                    std::cout << "Restart Pressed\n";
                    KoniecWindow->close();
                    PawnsVec.clear();
                    Game* g = new Game;
                    g->play();
                    restart = true;

                }
            }
        }
    }
}

void Game::allGameEvents() {
    while (window->pollEvent(BoardEventy)) {
        if (BoardEventy.type == sf::Event::Closed)
            window->close();
        else if (BoardEventy.type == sf::Event::KeyPressed) {
            if (BoardEventy.key.code == sf::Keyboard::Escape) {
                window->close();
                meow();
            }
        }
    }

}

void Game::read_file(std::string file_name_txt){
    std::ifstream dziennik(file_name_txt);
    std::system("cls");
    if (dziennik.is_open()) {
        std::string line;
        while (std::getline(dziennik, line)) {
            std::cout << line << std::endl;
        }
        dziennik.close();
    }
    else {
        std::cout << "Nie mozna otworzyc pliku." << std::endl;
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
                     play_chess = true;
                    if (play_chess = true) {
                        MenuWindow->close();
                    }
                }
            }
        }

        if (MenuEventy.type == sf::Event::MouseButtonPressed) {
            if (MenuEventy.mouseButton.button == sf::Mouse::Left) {
                if (Conf1.getGlobalBounds().contains(sf::Mouse::getPosition(*MenuWindow).x, sf::Mouse::getPosition(*MenuWindow).y)) {
                    std::cout << "Pressed conf1\n";
                    GreenAndBlue = false;
                    BlackAndWhite = true;
                }
            }
        }

        if (MenuEventy.type == sf::Event::MouseButtonPressed) {
            if (MenuEventy.mouseButton.button == sf::Mouse::Left) {
                if (Conf2.getGlobalBounds().contains(sf::Mouse::getPosition(*MenuWindow).x, sf::Mouse::getPosition(*MenuWindow).y)) {
                    std::cout << "Pressed conf2\n";
                  GreenAndBlue = true;
                  BlackAndWhite = false;
                }
            }
        }
    }

    if (MenuEventy.type == sf::Event::MouseButtonPressed) {
        if (MenuEventy.mouseButton.button == sf::Mouse::Left) {
            if (History.getGlobalBounds().contains(sf::Mouse::getPosition(*MenuWindow).x, sf::Mouse::getPosition(*MenuWindow).y)) {
                std::cout << "History\n";
                read_file("Dziennik_rozegranych_partii.txt");
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


void Game::Pressed() {
    for (auto& el : board) {
        el->set_Tile_marked_for_Black(false);
        el->set_Tile_marked_for_White(false);
    }
    for (auto& el : PawnsVec) {
        el->mark_Tiles(board, PawnsVec);
    }

    is_King_checked(board, Mouse_pos, PawnsVec);
    is_Pawn_promoted(board, PawnsVec);

    if (BoardEventy.type == sf::Event::MouseButtonPressed) {
        if (BoardEventy.mouseButton.button == sf::Mouse::Left) {
            Mouse_pos = sf::Mouse::getPosition(*window);
            for (auto& el : PawnsVec) {
                el->chosen(board, Mouse_pos, PawnsVec);
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
                el->unchosen();
            }
        }
    }
    if (BoardEventy.type == sf::Event::MouseButtonReleased) {
        if (BoardEventy.mouseButton.button == sf::Mouse::Left) {
            Mouse_pos = sf::Mouse::getPosition(*window);
            for (auto& el : PawnsVec) {
                el->move(board, Mouse_pos, PawnsVec);
                el->take(board, Mouse_pos, PawnsVec);
                el->unchosen();
            }
        }
    }
}

void Game::is_King_checked(std::vector<BoardTile*>& _board, const sf::Vector2i& mouse_position, std::vector<Piece*>& _PawnsVec) {

    King_White_checked = false;
    King_Black_checked = false;

    auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
        return _piece->get_Piece_type() == K && _piece->get_Piece_color() == Black; });

    auto it = std::find_if(_board.begin(), _board.end(), [itr](BoardTile* Tile) {
        return Tile->get_Tile_position() == (*itr)->getPosition(); });
    if (it != _board.end()) {
        if ((*it)->get_Tile_marked_for_White()) {
            King_Black_checked = true;
        }
    }

    if (King_Black_checked) {
        int counter = 0;

        auto it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(112, 112); });
        if (it1 != board.end()) {
            if ((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_White()) {
                counter++;
            }
        }
        else {
            counter++;
        }

        
        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(-1 * 112, 1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_White()) && counter == 1) {
                counter++;
            }
        }
        else {
            counter++;
        }

        
        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(-1 * 112, -1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_White()) && counter == 2) {
                counter++;
            }
        }
        else {
            counter++;
        }

        
        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(1 * 112, -1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_White()) && counter == 3) {
                counter++;
            }
        }
        else {
            counter++;
        }

        
        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(1 * 112, 0 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_White()) && counter == 4) {
                counter++;
            }
        }
        else {
            counter++;
        }

        
        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(-1 * 112, 0 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_White()) && counter == 5) {
                counter++;
            }
        }
        else {
            counter++;
        }

      
        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(0 * 112, 1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_White()) && counter == 6) {
                counter++;
            }
        }
        else {
            counter++;
        }

        
        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(0 * 112, -1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_White()) && counter == 7) {
                counter++;
            }
        }
        else {
            counter++;
        }

        if (counter == 8) {

            WhiteWin = true;
            play_chess == false;
            for (auto &el : _PawnsVec) {
                if (el->get_Piece_color() == White)

                    el->dance(Game::counter);
      
            }
        
        }
 
    }



    itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [](Piece* _piece) {
        return _piece->get_Piece_type() == K && _piece->get_Piece_color() == White; });

    it = std::find_if(_board.begin(), _board.end(), [itr](BoardTile* Tile) {
        return Tile->get_Tile_position() == (*itr)->getPosition(); });
    if (it != _board.end()) {
        if ((*it)->get_Tile_marked_for_Black()) {
            King_White_checked = true;
        }
    }
    if (King_White_checked) {
        int counterr = 0;

        auto it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(112, 112); });
        if (it1 != board.end()) {
            if ((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_Black()) {
                counterr++;
            }
        }
        else {
            counterr++;
        }


        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(-1 * 112, 1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_Black()) && counterr == 1) {
                counterr++;
            }
        }
        else {
            counterr++;
        }


        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(-1 * 112, -1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_Black()) && counterr == 2) {
                counterr++;
            }
        }
        else {
            counterr++;
        }


        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(1 * 112, -1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_Black()) && counterr == 3) {
                counterr++;
            }
        }
        else {
            counterr++;
        }


        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(1 * 112, 0 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_Black()) && counterr == 4) {
                counterr++;
            }
        }
        else {
            counterr++;
        }


        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(-1 * 112, 0 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_Black()) && counterr == 5) {
                counterr++;
            }
        }
        else {
            counterr++;
        }


        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(0 * 112, 1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_Black()) && counterr == 6) {
                counterr++;
            }
        }
        else {
            counterr++;
        }


        it1 = std::find_if(board.begin(), board.end(), [it](BoardTile* Tile) {
            return Tile->get_Tile_position() == (*it)->get_Tile_position() + sf::Vector2f(0 * 112, -1 * 112); });
        if (it1 != board.end()) {
            if (((*itr)->collider_for_King(_PawnsVec, (*it1)->get_Tile_position()) == false || (*it1)->get_Tile_marked_for_Black()) && counterr == 7) {
                counterr++;
            }
        }
        else {
            counterr++;
        }

        if (counterr == 8) {
         
            BlackWin = true;
            play_chess == false;
            for (auto el : _PawnsVec) {
                if (el->get_Piece_color() == Black)

                    el->dance(Game::counter);

            }
            counterr = 0;
        }
    }
}

void Game::is_Pawn_promoted(std::vector<BoardTile*>& _board, std::vector<Piece*>& _PawnsVec) {
    auto it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "a8"; });
    if (it != _board.end()){
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == White && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQW1 == false) {
            (*itr)->setPosition(0,0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQW1 = true;
            PawnsVec.push_back(new Queen("a8", White, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "b8"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == White && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQW2 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQW2 = true;
            PawnsVec.push_back(new Queen("b8", White, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "c8"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == White && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQW3 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQW3 = true;
            PawnsVec.push_back(new Queen("c8", White, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "d8"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == White && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQW4 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQW4 = true;
            PawnsVec.push_back(new Queen("d8", White, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "e8"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == White && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQW5 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQW5 = true;
            PawnsVec.push_back(new Queen("e8", White, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "f8"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == White && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQW6 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQW6 = true;
            PawnsVec.push_back(new Queen("f8", White, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "g8"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == White && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQW7 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQW7 = true;
            PawnsVec.push_back(new Queen("g8", White, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "h8"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == White && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQW8 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQW8 = true;
            PawnsVec.push_back(new Queen("h8", White, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }

    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "a1"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == Black && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQB1 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQB1 = true;
            PawnsVec.push_back(new Queen("a1", Black, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "b1"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == Black && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQB2 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQB2 = true;
            PawnsVec.push_back(new Queen("b1", Black, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "c1"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == Black && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQB3 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQB3 = true;
            PawnsVec.push_back(new Queen("c1", Black, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "d1"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == Black && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQB4 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQB4 = true;
            PawnsVec.push_back(new Queen("d1", Black, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "e1"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == Black && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQB5 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQB5 = true;
            PawnsVec.push_back(new Queen("e1", Black, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "f1"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == Black && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQB6 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQB6 = true;
            PawnsVec.push_back(new Queen("f1", Black, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "g1"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == Black && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQB7 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQB7 = true;
            PawnsVec.push_back(new Queen("g1", Black, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
    it = std::find_if(_board.begin(), _board.end(), [](BoardTile* Tile) {
        return Tile->get_Tile_id() == "h1"; });
    if (it != _board.end()) {
        auto itr = std::find_if(_PawnsVec.begin(), _PawnsVec.end(), [it](Piece* piece) {
            return piece->get_Starting_Piece_pos() == (*it)->get_Tile_position() && piece->get_Piece_color() == Black && piece->get_Piece_type() == P; });
        if (itr != _PawnsVec.end() && madeQB8 == false) {
            (*itr)->setPosition(0, 0);
            (*itr)->scale(0, 0);
            _PawnsVec.erase(itr);
            madeQB8 = true;
            PawnsVec.push_back(new Queen("h1", Black, Q, _board, BlackAndWhite, GreenAndBlue));
        }
    }
}

void Game::if_end_block_Pieces(bool WhiteWon, bool BlackWon, std::vector<Piece*>& _PawnsVec) {
    if (WhiteWon || BlackWon) {
        for (auto& el : _PawnsVec) {
            el->cant_be_chosen_f();
        }
    }
}

void Game::set_that_Piece_can_be_chosen(std::vector<Piece*>& _PawnsVec) {
    for (auto& el : _PawnsVec) {
        el->can_be_chosen_f();
    }
}

bool Game::check_whether_Black_or_white_win(bool WhiteWon, bool BlackWon) {
    if (WhiteWon || BlackWon) {
        return true;
    }
    else {
        return false;
    }
}
