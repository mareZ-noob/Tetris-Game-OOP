#include "Menu.h"

Menu::Menu() {
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
    this->textColor = 0;
    this->buttonColor = 0;
    this->backgroundColor = 0;
    this->selection = 0;
}

Menu::~Menu() {

}

void Menu::setX(int x) {
    this->x = x;
}

void Menu::setY(int y) {
    this->y = y;
}

void Menu::setW(int w) {
    this->w = w;
}

void Menu::setH(int h) {
    this->h = h;
}

void Menu::setTextColor(int textColor) {
    this->textColor = textColor;
}

void Menu::setButtonColor(int buttonColor) {
	this->buttonColor = buttonColor;
}

void Menu::setBackgroundColor(int backgroundColor) {
    this->backgroundColor = backgroundColor;
}

void Menu::setSelection(int selection) {
    this->selection = selection;
}

void Menu::setPlayerName(string playerName) {
    this->playerName = playerName;
}

int Menu::getX() const{
    return this->x;
}

int Menu::getY() const {
    return this->y;
}

int Menu::getW() const {
    return this->w;
}

int Menu::getH() const {
    return this->h;
}

int Menu::getTextColor() const {
    return this->textColor;
}

int Menu::getButtonColor() const {
    return this->buttonColor;
}

int Menu::getBackgroundColor() const {
    return this->backgroundColor;
}

int Menu::getSelection() const {
    return this->selection;
}

string Menu::getPlayerName() const {
    return this->playerName;
}

//MENU 1:
void Menu::MainMenu() {
    setX(42);
    setY(20);
    setW(20);
    setH(2);
    setTextColor(Color::WHITE);
    setButtonColor(Color::LIGHTCYAN);
    setBackgroundColor(Color::BLACK);

    setSelection(1);
    Screen::getInstance()->showCursor(0);
    printMainMenu();

    while (true) {
        char c = _getch();

        if (c == KEY_w || c == KEY_W || c == KEY_UP) { 
            this->selection--;
            if (getSelection() == 0) {
                setSelection(5);
            }
            selectionMenu1();
        }
        else if (c == KEY_s || c == KEY_S || c == KEY_DOWN) { 
            this->selection++;
            if (getSelection() == 6) {
                setSelection(1);
            }
            selectionMenu1();
        }
        else if (c == ENTER_KEY || c == '\n') { 
            switch (this->selection) {
            case 1:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Menu::PlayGame();
                break;
            case 2:
                Screen::getInstance()->createScreen();
                Leaderboard::getInstance()->printLeaderboard();
                Sound::getInstance()->playSound(Sound::SAUL);
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
                Screen::getInstance()->createScreen();
                Sound::getInstance()->playSound(Sound::MII_CHANNEL);
                Graphic::getInstance()->readFileAtPosition("static\\ascii\\HowToPlay.txt", 22, 2, backgroundColor, Color::LIGHTRED);
                Graphic::getInstance()->readFileAtPosition("static\\text\\instructions.txt", 4, 8, backgroundColor, textColor);
                Color::getInstance()->consoleTextColor(Color::LIGHTRED);
                Screen::getInstance()->drawRectangle(24, 7, 58, 6);
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
                Screen::getInstance()->createScreen();
                Sound::getInstance()->playSound(Sound::RICK_ROLL);
                Graphic::getInstance()->readFileAtPosition("static\\ascii\\credit.txt", 32, 2, backgroundColor, Color::YELLOW);
                Graphic::getInstance()->readFileAtPosition("static\\text\\credit.txt", 4, 12, backgroundColor, textColor);
                Color::getInstance()->consoleTextColor(Color::YELLOW);
                Screen::getInstance()->drawRectangle(5, 11, 95, 7);
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

void Menu::selectionMenu1() {
    int Color = textColor;

    if (getSelection() == 1) {
        Screen::getInstance()->Button(x, y, w, h, Color::RED, buttonColor, backgroundColor, "  >> PLAY GAME <<");
    }
    else {
        Screen::getInstance()->Button(x, y, w, h, Color, buttonColor, backgroundColor, "     PLAY GAME");
    }

    if (getSelection() == 2) {
        Screen::getInstance()->Button(x, y + 2, w, h, Color::RED, buttonColor, backgroundColor, " >> HIGH SCORES <<");
        Screen::getInstance()->goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 2);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "    HIGH SCORES");
        Screen::getInstance()->goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 2);
        cout << char(180);
    }

    if (getSelection() == 3) {
        Screen::getInstance()->Button(x, y + 4, w, h, Color::RED, buttonColor, backgroundColor, " >> INSTRUCTION <<");
        Screen::getInstance()->goToXY(x, y + 4);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 4);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 4, w, h, Color, buttonColor, backgroundColor, "    INSTRUCTION");
        Screen::getInstance()->goToXY(x, y + 4);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 4);
        cout << char(180);
    }

    if (getSelection() == 4) {
        Screen::getInstance()->Button(x, y + 6, w, h, Color::RED, buttonColor, backgroundColor, "   >> CREDITS <<");
        Screen::getInstance()->goToXY(x, y + 6);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 6);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 6, w, h, Color, buttonColor, backgroundColor, "      CREDITS");
        Screen::getInstance()->goToXY(x, y + 6);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 6);
        cout << char(180);
    }

    if (getSelection() == 5) {
        Screen::getInstance()->Button(x, y + 8, w, h, Color::RED, buttonColor, backgroundColor, "  >> QUIT GAME <<");
        Screen::getInstance()->goToXY(x, y + 8);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 8);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 8, w, h, Color, buttonColor, backgroundColor, "     QUIT GAME");
        Screen::getInstance()->goToXY(x, y + 8);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 8);
        cout << char(180);
    }
}

void Menu::printMainMenu() {
    Graphic::getInstance()->artAtPosition("static\\ascii\\TetrisGame.txt", 20, 3, Color::BLACK, Color::YELLOW);
    Screen::getInstance()->drawBorder();
    selectionMenu1();
}

void Menu::PlayGame() {
    Color::getInstance()->consoleTextColor(Color::BROWN);
    Screen::getInstance()->drawRectangle(32, 12, 40, 12);
    Screen::getInstance()->Button(43, 13, 19, 2, Color::LIGHTGREEN, Color::BLACK, Color::BLACK, " ENTER YOUR NAME:");

    Screen::getInstance()->Button(36, 16, 32, 2, Color::WHITE, Color::BROWN, Color::BLACK, " ");
    Screen::getInstance()->goToXY(41, 23);
    Color::getInstance()->consoleTextColor(Color::YELLOW);
    printf("Press ENTER to continue");

    Screen::getInstance()->goToXY(37, 17);
    Color::getInstance()->consoleTextColor(Color::WHITE);
    Screen::getInstance()->showCursor(1);

    string temp;
    getline(cin, temp);
    if (!temp.empty()) {
        setPlayerName(temp);
        Screen::getInstance()->createScreen();
        return ClassicModernMenu();
    }
    else {
        Color::getInstance()->consoleTextColor(Color::RED);
        Screen::getInstance()->goToXY(41, 21);
        printf("Please enter your name!");
        return PlayGame();
    }
}

void Menu::quit() {
    Screen::getInstance()->clearScreen();
    Graphic::getInstance()->readFileAtPosition("static\\ascii\\quit.txt", 23, 13, Color::BLACK, Color::YELLOW);
    Screen::getInstance()->drawBorder();
    Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);
    Sound::getInstance()->playSound(Sound::TO_BE_CONTINUED);
    Sleep(11000);
    Screen::getInstance()->clearScreen();
    exit(1);
}

//MENU 2:
void Menu::ClassicModernMenu() {
    setX(42);
    setY(18);
    setW(20);
    setH(2);
    setTextColor(Color::WHITE);
    setButtonColor(Color::LIGHTCYAN);
    setBackgroundColor(Color::BLACK);

    setSelection(1);
    Screen::getInstance()->showCursor(0);
    printClassicModernMenu();

    while (true) {
        char c = _getch();

        if (c == ESC_KEY) {
            Screen::getInstance()->clearScreen();
            return MainMenu();
        }
        else if (c == KEY_w || c == KEY_W || c == KEY_UP) { 
            this->selection--;
            if (getSelection() == 0) {
                setSelection(2);
            }
            selectionMenu2();
        }
        else if (c == KEY_s || c == KEY_S || c == KEY_DOWN) { 
            this->selection++;
            if (getSelection() == 3) {
                setSelection(1);
            }
            selectionMenu2();
        }
        else if (c == ENTER_KEY || c == '\n') { 
            switch (this->selection) {
            case 1:
                Screen::getInstance()->createScreen();
                ClassicModeMenu();
                break;
            case 2:
                Screen::getInstance()->createScreen();
                ModernModeMenu();
                break;
            
            }
        }
    }
    system("pause");
}

void Menu::selectionMenu2() {
    if (getSelection() == 1) {
        Screen::getInstance()->Button(x, y, w, h, Color::RED, buttonColor, backgroundColor, "   >> CLASSIC <<");
    }
    else {
        Screen::getInstance()->Button(x, y, w, h, textColor, buttonColor, backgroundColor, "      CLASSIC");
    }

    if (getSelection() == 2) {
        Screen::getInstance()->Button(x, y + 2, w, h, Color::RED, buttonColor, backgroundColor, "   >> MODERN <<");
        Screen::getInstance()->goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 2);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 2, w, h, textColor, buttonColor, backgroundColor, "      MODERN");
        Screen::getInstance()->goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 2);
        cout << char(180);
    }
}

void Menu::printClassicModernMenu() {
    Graphic::getInstance()->artAtPosition("static\\ascii\\ChooseMode.txt", 20, 3, Color::BLACK, Color::LIGHTGRAY);
    Screen::getInstance()->drawBorder();
    selectionMenu2();
}

//MENU 3: (CLASSIC)
void Menu::ClassicModeMenu() {
    setX(42);
    setY(20);
    setW(20);
    setH(2);
    setTextColor(Color::WHITE);
    setButtonColor(Color::LIGHTCYAN);
    setBackgroundColor(Color::BLACK);

    setSelection(1);
    Screen::getInstance()->showCursor(0);
    printClassicModeMenu();

    while (true) {
        char c = _getch();

        if (c == ESC_KEY) {
            Screen::getInstance()->createScreen();
            return ClassicModernMenu();
        }
        else if (c == KEY_w || c == KEY_W || c == KEY_UP) {
            this->selection--;
            if (getSelection() == 0) {
                setSelection(4);
            }
            selectionMenu3();
        }
        else if (c == KEY_s || c == KEY_S || c == KEY_DOWN) { 
            this->selection++;
            if (getSelection() == 5) {
                setSelection(1);
            }
            selectionMenu3();
        }
        else if (c == ENTER_KEY || c == '\n') { 
            unique_ptr<Game> Tetris(new Game());
            switch (this->selection) {
            case 1:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Tetris->runTetris(playerName, 1, 1);
                break;
            case 2:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Tetris->runTetris(playerName, 1, 2);
                break;
            case 3:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Tetris->runTetris(playerName, 1, 3);
                break;
            case 4:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Tetris->runTetris(playerName, 1, 4);
                break;
            }
        }
    }
    system("pause");
}

void Menu::selectionMenu3() {
    if (getSelection() == 1) {
        Screen::getInstance()->Button(x, y, w, h, Color::RED, buttonColor, backgroundColor, "    >> EASY <<");
    }
    else {
        Screen::getInstance()->Button(x, y, w, h, textColor, buttonColor, backgroundColor, "       EASY");
    }

    if (getSelection() == 2) {
        Screen::getInstance()->Button(x, y + 2, w, h, Color::RED, buttonColor, backgroundColor, "   >> MEDIUM <<");
        Screen::getInstance()->goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 2);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 2, w, h, textColor, buttonColor, backgroundColor, "      MEDIUM");
        Screen::getInstance()->goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 2);
        cout << char(180);
    }

    if (getSelection() == 3) {
        Screen::getInstance()->Button(x, y + 4, w, h, Color::RED, buttonColor, backgroundColor, "    >> HARD <<");
        Screen::getInstance()->goToXY(x, y + 4);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 4);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 4, w, h, textColor, buttonColor, backgroundColor, "       HARD");
        Screen::getInstance()->goToXY(x, y + 4);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 4);
        cout << char(180);
    }

    if (getSelection() == 4) {
        Screen::getInstance()->Button(x, y + 6, w, h, Color::RED, buttonColor, backgroundColor, "   >> EXTREME <<");
        Screen::getInstance()->goToXY(x, y + 6);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 6);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 6, w, h, textColor, buttonColor, backgroundColor, "      EXTREME");
        Screen::getInstance()->goToXY(x, y + 6);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 6);
        cout << char(180);
    }
}

void Menu::printClassicModeMenu() {
    Graphic::getInstance()->artAtPosition("static\\ascii\\ChooseDifficulty.txt", 6, 3, Color::BLACK, Color::LIGHTGRAY);
    Graphic::getInstance()->artAtPosition("static\\ascii\\classic.txt", 35, 11, Color::BLACK, Color::BROWN);
    Screen::getInstance()->drawBorder();
    selectionMenu3();
}


//MENU 4: (MODERN)
void Menu::ModernModeMenu() {
    setX(42);
    setY(20);
    setW(20);
    setH(2);
    setTextColor(Color::WHITE);
    setButtonColor(Color::LIGHTCYAN);
    setBackgroundColor(Color::BLACK);

    setSelection(1);
    Screen::getInstance()->showCursor(0);
    printModernModeMenu();

    while (true) {
        char c = _getch();

        if (c == ESC_KEY) {
            Screen::getInstance()->createScreen();
            return ClassicModernMenu();
        }
        else if (c == KEY_w || c == KEY_W || c == KEY_UP) { 
            this->selection--;
            if (getSelection() == 0) {
                setSelection(4);
            }
            selectionMenu4();
        }
        else if (c == KEY_s || c == KEY_S || c == KEY_DOWN) { 
            this->selection++;
            if (getSelection() == 5) {
                setSelection(1);
            }
            selectionMenu4();
        }
        else if (c == ENTER_KEY || c == '\n') { 
            unique_ptr<Game> Tetris(new Game());
            switch (this->selection) {
            case 1:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Tetris->runTetris(playerName, 2, 1);
                break;
            case 2:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Tetris->runTetris(playerName, 2, 2);
                break;
            case 3:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Tetris->runTetris(playerName, 2, 3);
                break;
            case 4:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Tetris->runTetris(playerName, 2, 4);
                break;
            }
        }
    }
    system("pause");
}

void Menu::selectionMenu4() {
    if (getSelection() == 1) {
        Screen::getInstance()->Button(x, y, w, h, Color::RED, buttonColor, backgroundColor, "    >> EASY <<");
    }
    else {
        Screen::getInstance()->Button(x, y, w, h, textColor, buttonColor, backgroundColor, "       EASY");
    }

    if (getSelection() == 2) {
        Screen::getInstance()->Button(x, y + 2, w, h, Color::RED, buttonColor, backgroundColor, "   >> MEDIUM <<");
        Screen::getInstance()->goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 2);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 2, w, h, textColor, buttonColor, backgroundColor, "      MEDIUM");
        Screen::getInstance()->goToXY(x, y + 2);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 2);
        cout << char(180);
    }

    if (getSelection() == 3) {
        Screen::getInstance()->Button(x, y + 4, w, h, Color::RED, buttonColor, backgroundColor, "    >> HARD <<");
        Screen::getInstance()->goToXY(x, y + 4);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 4);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 4, w, h, textColor, buttonColor, backgroundColor, "       HARD");
        Screen::getInstance()->goToXY(x, y + 4);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 4);
        cout << char(180);
    }

    if (getSelection() == 4) {
        Screen::getInstance()->Button(x, y + 6, w, h, Color::RED, buttonColor, backgroundColor, "   >> EXTREME <<");
        Screen::getInstance()->goToXY(x, y + 6);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 6);
        cout << char(180);
    }
    else {
        Screen::getInstance()->Button(x, y + 6, w, h, textColor, buttonColor, backgroundColor, "      EXTREME");
        Screen::getInstance()->goToXY(x, y + 6);
        cout << char(195);
        Screen::getInstance()->goToXY(x + w, y + 6);
        cout << char(180);
    }
}

void Menu::printModernModeMenu() {
    Graphic::getInstance()->artAtPosition("static\\ascii\\ChooseDifficulty.txt", 6, 3, Color::BLACK, Color::LIGHTGRAY);
    Graphic::getInstance()->artAtPosition("static\\ascii\\modern.txt", 35, 11, Color::BLACK, Color::YELLOW);
    Screen::getInstance()->drawBorder();
    selectionMenu3();
}