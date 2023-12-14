#include "Menu.h"

Menu::Menu() {

}

Menu::~Menu() {

}

Menu* Menu::instance = nullptr;
mutex Menu::mutex_;
Menu* Menu::getInstance() {
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr) {
        instance = new Menu();
    }
    return instance;
}

void Menu::deleteInstance() {
    lock_guard<mutex> lock(mutex_);
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

void Menu::quit() {
    Screen::getInstance()->clearScreen();
    //pikachu_bye(4, 4);
    Graphic::getInstance()->readFileAtPosition("static\\ascii\\lose.txt", 20, 10, Color::BLACK, Color::CYAN);
    Color::getInstance()->consoleColor(Color::BLACK, Color::BLACK);
    Sleep(5000);
    Screen::getInstance()->clearScreen();
    exit(1);
}

void Menu::PlayGame() {
    Color::getInstance()->consoleTextColor(Color::BROWN);
    Screen::getInstance()->drawRectangle(32, 12, 40, 12);
    Screen::getInstance()->Button(33, 13, 19, 2, Color::LIGHTGREEN, Color::BLACK, Color::BLACK, " ENTER YOUR NAME:");

    //Color::getInstance()->consoleTextColor(Color::WHITE);
    //Screen::getInstance()->goToXY(48, 22);
    Screen::getInstance()->Button(36, 16, 32, 2, Color::WHITE, Color::BROWN, Color::BLACK, " ");
    Screen::getInstance()->goToXY(41, 23);
    Color::getInstance()->consoleTextColor(Color::YELLOW);
    printf("Press ENTER to continue");

    Screen::getInstance()->goToXY(37, 17);
    Color::getInstance()->consoleTextColor(Color::WHITE);
    Screen::getInstance()->showCursor(1);
    std::string PlayerName;
    getline(std::cin, PlayerName);

    if (!PlayerName.empty()) {
        Screen::getInstance()->clearScreen();
        //Game ở đây
    }
    else {
        Color::getInstance()->consoleTextColor(Color::RED);
        Screen::getInstance()->goToXY(41, 21);
        printf("Please enter your name!");
        return Menu::PlayGame();
    }
}

void Menu::selectionMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor) {
    int Color = textColor;

    if (selection == 1) {
        Screen::getInstance()->Button(x, y, w, h, Color::RED, buttonColor, backgroundColor, "  >> PLAY GAME <<");
    }
    else {
        Screen::getInstance()->Button(x, y, w, h, Color, buttonColor, backgroundColor, "     PLAY GAME");
    }

    if (selection == 2) {
        Screen::getInstance()->Button(x, y + 2, w, h, Color::RED, buttonColor, backgroundColor, " >> HIGH SCORES <<");
        Screen::getInstance()->Screen::goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->Screen::goToXY(x + w, y + 2);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "    HIGH SCORES");
        Screen::getInstance()->Screen::goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->Screen::goToXY(x + w, y + 2);
        cout << char(180);
    }

    if (selection == 3) {
        Screen::getInstance()->Button(x, y + 4, w, h, Color::RED, buttonColor, backgroundColor, " >> INSTRUCTION <<");
        Screen::getInstance()->Screen::goToXY(x, y + 4);
        cout << char(195);
        Screen::getInstance()->Screen::goToXY(x + w, y + 4);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 4, w, h, Color, buttonColor, backgroundColor, "    INSTRUCTION");
        Screen::getInstance()->Screen::goToXY(x, y + 4);
        cout << char(195);
        Screen::getInstance()->Screen::goToXY(x + w, y + 4);
        cout << char(180);
    }

    if (selection == 4) {
        Screen::getInstance()->Button(x, y + 6, w, h, Color::RED, buttonColor, backgroundColor, "   >> CREDITS <<");
        Screen::getInstance()->Screen::goToXY(x, y + 6);
        cout << char(195);
        Screen::getInstance()->Screen::goToXY(x + w, y + 6);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 6, w, h, Color, buttonColor, backgroundColor, "      CREDITS");
        Screen::getInstance()->Screen::goToXY(x, y + 6);
        cout << char(195);
        Screen::getInstance()->Screen::goToXY(x + w, y + 6);
        cout << char(180);
    }

    if (selection == 5) {
        Screen::getInstance()->Button(x, y + 8, w, h, Color::RED, buttonColor, backgroundColor, "  >> QUIT GAME <<");
        Screen::getInstance()->Screen::goToXY(x, y + 8);
        cout << char(195);
        Screen::getInstance()->Screen::goToXY(x + w, y + 8);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 8, w, h, Color, buttonColor, backgroundColor, "     QUIT GAME");
        Screen::getInstance()->Screen::goToXY(x, y + 8);
        cout << char(195);
        Screen::getInstance()->Screen::goToXY(x + w, y + 8);
        cout << char(180);
    }
}

void Menu::printMainMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor) {
    //Color::getInstance()->consoleTextColor(Color::LIGHTGREEN);
    Graphic::getInstance()->artAtPosition("static\\ascii\\TetrisGame.txt", 20, 3, Color::BLACK, Color::YELLOW);
    //Graphic::getInstance()->tetris1(70, 10);
    Screen::getInstance()->drawBorder();
    selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
}

void Menu::MainMenu() {
    x = 42, y = 20, w = 20, h = 2;

    int textColor = Color::WHITE;
    int buttonColor = Color::LIGHTCYAN;
    int backgroundColor = Color::BLACK;
    string email;
    Screen::getInstance()->showCursor(0);
    int selection = 1;
    printMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor);

    while (true) {
        char c = _getch();

        if (c == KEY_w || c == KEY_W || c == KEY_UP) { // move up
            selection--;
            if (selection == 0) {
                selection = 5;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
        }
        else if (c == KEY_s || c == KEY_S || c == KEY_DOWN) { // move down
            selection++;
            if (selection == 6) {
                selection = 1;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
        }
        else if (c == ENTER_KEY || c == '\n') { // pressed enter
            switch (selection) {
            case 1:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Menu::PlayGame();
                break;
            case 2:
                Screen::getInstance();
                //HowToPlay();
                while (true) {
                    if (_kbhit()) {
                        char key = _getch();
                        if (key == ESC_KEY) {
                            Screen::getInstance()->clearScreen();
                            return MainMenu();
                            break;
                        }
                    }
                }
                break;
            case 3:
                Screen::getInstance();
                /*art_at_pos("ascii_art\\credit.txt", LIGHT_GREEN, backgroundColor, 36, 2);
                read_file_at_pos("ascii_art\\content.txt", WHITE, backgroundColor, 4, 12);*/
                Color::getInstance()->consoleTextColor(Color::LIGHTGREEN);
                Screen::getInstance()->DrawRectangle(5, 10, 108, 20, Color(Color::BLACK, Color::YELLOW), char(179));
                while (true) {
                    if (_kbhit()) {
                        char key = _getch();
                        if (key == ESC_KEY) {
                            Screen::getInstance()->clearScreen();
                            return MainMenu();
                            break;
                        }
                    }
                }
                break;
            case 4:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                quit();
                break;
            case 5:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                quit();
                break;
            }
        }
    }
    system("pause");
}

//void selectionMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor)
//{
//    int Color = textColor;
//
//    if (selection == 1)
//    {
//        textColor = RED;
//        button(x, y, w, h, textColor, buttonColor, backgroundColor, "   > PLAY GAME <");
//    }
//    else
//    {
//        textColor = Color;
//        button(x, y, w, h, Color, buttonColor, backgroundColor, "     PLAY GAME");
//    }
//
//    if (selection == 2)
//    {
//        textColor = RED;
//        button(x, y + 2, w, h, textColor, buttonColor, backgroundColor, "  > CUSTOM PLAY <");
//        moveCursor(x, y + 2);
//        cout << char(195);
//        moveCursor(x + w, y + 2);
//        cout << char(180);
//    }
//    else
//    {
//        textColor = Color;
//        button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "    CUSTOM PLAY");
//        moveCursor(x, y + 2);
//        cout << char(195);
//        moveCursor(x + w, y + 2);
//        cout << char(180);
//    }
//
//    if (selection == 3)
//    {
//        textColor = RED;
//        button(x, y + 4, w, h, textColor, buttonColor, backgroundColor, "  > LEADERBOARD <");
//        moveCursor(x, y + 4);
//        cout << char(195);
//        moveCursor(x + w, y + 4);
//        cout << char(180);
//    }
//    else
//    {
//        textColor = Color;
//        button(x, y + 4, w, h, Color, buttonColor, backgroundColor, "    LEADERBOARD");
//        moveCursor(x, y + 4);
//        cout << char(195);
//        moveCursor(x + w, y + 4);
//        cout << char(180);
//    }
//
//    if (selection == 4)
//    {
//        textColor = RED;
//        button(x, y + 6, w, h, textColor, buttonColor, backgroundColor, "     > BACK <");
//        moveCursor(x, y + 6);
//        cout << char(195);
//        moveCursor(x + w, y + 6);
//        cout << char(180);
//    }
//    else
//    {
//        textColor = Color;
//        button(x, y + 6, w, h, Color, buttonColor, backgroundColor, "       BACK");
//        moveCursor(x, y + 6);
//        cout << char(195);
//        moveCursor(x + w, y + 6);
//        cout << char(180);
//    }
//}
////void printMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor)
////{
////    drawBorder();
////    pikachu_ava(3, 3);
////    charmander_ava(70, 1);
////    bulbasaur_ava(85, 15);
////    clefairy_ava(20, 23);
////    selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
////}
//
////void LoginMenu()
////{
////    int x = 50;
////    int y = 14;
////    int w = 20;
////    int h = 2;
////    int textColor = CYAN;
////    int buttonColor = OCEAN;
////    int backgroundColor = BLACK;
////    showCursor(0);
////    int selection = 1; // start with the first button selected
////    printMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
////
////    while (true)
////    {
////        char c = _getch();
////
////        if (c == KEY_w || c == KEY_W)
////        { // move up
////            selection--;
////            if (selection == 0)
////            {
////                selection = 4;
////            }
////            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
////        }
////        else if (c == KEY_s || c == KEY_S)
////        { // move down
////            selection++;
////            if (selection == 5)
////            {
////                selection = 1;
////            }
////            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
////        }
////        else if (c == ENTER_KEY || c == '\n')
////        { // pressed enter
////            switch (selection)
////            {
////            case 1:
////                clearScreen();
////                drawBorder();
////                GamePlayMenu();
////                break;
////            case 2:
////                createScreen();
////                Players p;
////                customGame(p);
////                break;
////            case 3:
////                printLeaderboard();
////                break;
////            case 4:
////                clearScreen();
////                drawBorder();
////                return MainMenu();
////                Sleep(5000);
////                break;
////            }
////        }
////    }
////    system("pause");
////}
//
//void selectionPlayGame(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor)
//{
//    int Color = textColor;
//
//    if (selection == 1)
//    {
//        textColor = RED;
//        button(x, y, w, h, textColor, buttonColor, backgroundColor, "     > EASY <");
//    }
//    else
//    {
//        textColor = Color;
//        button(x, y, w, h, Color, buttonColor, backgroundColor, "       EASY");
//    }
//
//    if (selection == 2)
//    {
//        textColor = RED;
//        button(x, y + 2, w, h, textColor, buttonColor, backgroundColor, "    > MEDIUM <");
//        moveCursor(x, y + 2);
//        cout << char(195);
//        moveCursor(x + w, y + 2);
//        cout << char(180);
//    }
//    else
//    {
//        textColor = Color;
//        button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "      MEDIUM");
//        moveCursor(x, y + 2);
//        cout << char(195);
//        moveCursor(x + w, y + 2);
//        cout << char(180);
//    }
//
//    if (selection == 3)
//    {
//        textColor = RED;
//        button(x, y + 4, w, h, textColor, buttonColor, backgroundColor, "     > HARD <");
//        moveCursor(x, y + 4);
//        cout << char(195);
//        moveCursor(x + w, y + 4);
//        cout << char(180);
//    }
//    else
//    {
//        textColor = Color;
//        button(x, y + 4, w, h, Color, buttonColor, backgroundColor, "       HARD");
//        moveCursor(x, y + 4);
//        cout << char(195);
//        moveCursor(x + w, y + 4);
//        cout << char(180);
//    }
//
//    if (selection == 4)
//    {
//        textColor = RED;
//        button(x, y + 6, w, h, textColor, buttonColor, backgroundColor, "     > BACK <");
//        moveCursor(x, y + 6);
//        cout << char(195);
//        moveCursor(x + w, y + 6);
//        cout << char(180);
//    }
//    else
//    {
//        textColor = Color;
//        button(x, y + 6, w, h, Color, buttonColor, backgroundColor, "       BACK");
//        moveCursor(x, y + 6);
//        cout << char(195);
//        moveCursor(x + w, y + 6);
//        cout << char(180);
//    }
//}
//
//void printPlayGame(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor)
//{
//    drawBorder();
//    selectionPlayGame(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
//}
//
//void GamePlayMenu()
//{
//    int x = 50;
//    int y = 13;
//    int w = 19;
//    int h = 2;
//    int textColor = CYAN;
//    int buttonColor = OCEAN;
//    int backgroundColor = BLACK;
//    showCursor(0);
//    int selection = 1; // start with the first button selected
//    printPlayGame(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
//
//    while (true)
//    {
//        char c = _getch();
//
//        if (c == KEY_w || c == KEY_W)
//        { // move up
//            selection--;
//            if (selection == 0)
//            {
//                selection = 4;
//            }
//            selectionPlayGame(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
//        }
//        else if (c == KEY_s || c == KEY_S)
//        { // move down
//            selection++;
//            if (selection == 5)
//            {
//                selection = 1;
//            }
//            selectionPlayGame(selection, x, y, w, h, textColor, buttonColor, backgroundColor);
//        }
//        else if (c == ENTER_KEY || c == '\n')
//        { // pressed enter
//            switch (selection)
//            {
//            case 1:
//                drawBorder();
//                Players p1;
//                normalGame(p1, 1);
//
//                break;
//            case 2:
//                drawBorder();
//                Players p2;
//                normalGame(p2, 2);
//
//                break;
//            case 3:
//                drawBorder();
//                Players p3;
//                normalGame(p3, 3);
//
//                break;
//            case 4:
//                clearScreen();
//                drawBorder();
//                return LoginMenu();
//                Sleep(5000);
//                break;
//            }
//        }
//    }
//    system("pause");
//}
//
//void HowToPlay()
//{
//    art_at_pos("ascii_art\\howtoplay.txt", CYAN, BLACK, 30, 2);
//    drawRectangle(15, 8, 90, 20);
//    drawRectangle(15, 8, 20, 4);
//    drawRectangle(15, 12, 90, 12);
//    drawRectangle(15, 12, 20, 12);
//    drawRectangle(15, 24, 20, 4);
//
//    moveCursor(15, 12);
//    cout << char(195);
//    moveCursor(15, 24);
//    cout << char(195);
//    moveCursor(36, 8);
//    cout << char(194);
//    moveCursor(36, 12);
//    cout << char(197);
//    moveCursor(36, 24);
//    cout << char(197);
//    moveCursor(36, 28);
//    cout << char(193);
//    moveCursor(106, 12);
//    cout << char(180);
//    moveCursor(106, 24);
//    cout << char(180);
//
//    moveCursor(23, 10);
//    TextColor(LIGHT_YELLOW);
//    cout << "MOVES:";
//    moveCursor(21, 18);
//    TextColor(LIGHT_GREEN);
//    cout << "GAME RULES:";
//    moveCursor(23, 26);
//    TextColor(LIGHT_BLUE);
//    cout << "SCORES:";
//    read_file_at_pos("ascii_art\\howtoplay_content.txt", WHITE, BLACK, 38, 9);
//}