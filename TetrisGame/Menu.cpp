#include "Menu.h"

Menu::Menu() {

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
    Graphic::getInstance()->readFileAtPosition("static\\ascii\\quit.txt", 23, 13, Color::BLACK, Color::YELLOW);
    Screen::getInstance()->drawBorder();
    Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);
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
        //Menu::getInstance()->ClassicModernMode();
    }
    else {
        Color::getInstance()->consoleTextColor(Color::RED);
        Screen::getInstance()->goToXY(41, 21);
        printf("Please enter your name!");
        return Menu::PlayGame();
    }
}

void Menu::selectionMenu() {
    int Color = textColor;

    if (getSelection() == 1) {
        Screen::getInstance()->Button(x, y, w, h, Color::RED, buttonColor, backgroundColor, "  >> PLAY GAME <<");
    }
    else {
        Screen::getInstance()->Button(x, y, w, h, Color, buttonColor, backgroundColor, "     PLAY GAME");
    }

    if (getSelection() == 2) {
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

    if (getSelection() == 3) {
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

    if (getSelection() == 4) {
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

    if (getSelection() == 5) {
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

void Menu::printMainMenu() {
    Graphic::getInstance()->artAtPosition("static\\ascii\\TetrisGame.txt", 20, 3, Color::BLACK, Color::YELLOW);
    Screen::getInstance()->drawBorder();
    selectionMenu();
}

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

        if (c == KEY_w || c == KEY_W || c == KEY_UP) { // move up
            this->selection--;
            if (getSelection() == 0) {
                setSelection(5);
            }
            selectionMenu();
        }
        else if (c == KEY_s || c == KEY_S || c == KEY_DOWN) { // move down
            this->selection++;
            if (getSelection() == 6) {
                setSelection(1);
            }
            selectionMenu();
        }
        else if (c == ENTER_KEY || c == '\n') { // pressed enter
            switch (this->selection) {
            case 1:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Menu::PlayGame();
                /*while (true) {
                    if (_kbhit()) {
                        char key = _getch();
                        if (key == ESC_KEY) {
                            Screen::getInstance()->clearScreen();
                            return MainMenu();
                            break;
                        }
                    }
                }*/
                break;
            case 2:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
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
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
                Graphic::getInstance()->readFileAtPosition("static\\ascii\\howtoplay.txt", 22, 2, backgroundColor, Color::LIGHTRED);
                Graphic::getInstance()->readFileAtPosition("static\\text\\instructions.txt", 4, 10, backgroundColor, textColor);
                Color::getInstance()->consoleTextColor(Color::LIGHTRED);
                Screen::getInstance()->drawRectangle(24, 9, 58, 6);
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
                break;
            case 4:
                Screen::getInstance()->clearScreen();
                Screen::getInstance()->drawBorder();
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

void Menu::ClassicModernMode() {
    int Color = textColor;

    if (getSelection() == 1) {
        Screen::getInstance()->Button(x, y, w, h, Color::RED, buttonColor, backgroundColor, "  >> PLAY GAME <<");
    }
    else {
        Screen::getInstance()->Button(x, y, w, h, Color, buttonColor, backgroundColor, "     PLAY GAME");
    }

    if (getSelection() == 2) {
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

    if (getSelection() == 3) {
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

    if (getSelection() == 4) {
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

    if (getSelection() == 5) {
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