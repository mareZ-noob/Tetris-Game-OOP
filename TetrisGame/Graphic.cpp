#include "Graphic.h"

Graphic::Graphic() {

}

Graphic::~Graphic() {

}

Graphic* Graphic::instance = nullptr;
mutex Graphic::mutex_;
Graphic* Graphic::getInstance() {
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr) {
        instance = new Graphic();
    }
    return instance;
}

void Graphic::deleteInstance() {
    lock_guard<mutex> lock(mutex_);
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

void Graphic::drawCharacter(char character, double x, double y, int textColor, int backgroundColor) {
    Screen::getInstance()->gotoXY(x, y);
    Color::getInstance()->consoleColor(Color::BLACK, Color::BLACK);
    Color::getInstance()->consoleTextColor(Color::BLACK);
    cout << character;
}

void Graphic::drawTextFromFile(string fileName, int x, int y, int textColor, int backgroundColor) {
    ifstream file(fileName);
    if (file.is_open()) {
        char c;
        int posX = x, posY = y;
        while (file.get(c)) {
            if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                drawCharacter(c, posX, posY, textColor, backgroundColor);
                posX++;
            }
        }
        file.close();
    }
}

void Graphic::artAtPosition(string fileName, int textColor, int backgroundColor, int x, int y) {
    drawTextFromFile(fileName, x, y, textColor, backgroundColor);
}

void Graphic::readFileAtPosition(string fileName, int textColor, int backgroundColor, int x, int y) {
    drawTextFromFile(fileName, x, y, textColor, backgroundColor);
}

void Graphic::pokemonBall(int x, int y) {
    ifstream file("ascii_art\\pokemonball.txt");
    int backgroundColor = 0;
    if (file.is_open()) {
        char c;
        int posX = x, posY = y;
        while (file.get(c)) {
            if (c == '7') {
                Color::getInstance()->consoleColor(Color::BLACK, Color::BLACK);
                Screen::getInstance()->gotoXY(posX, posY);
                Color::getInstance()->consoleTextColor(Color::BLACK);
                cout << c;
                posX++;
            }
            else if (c == 'J') {
                Color::getInstance()->consoleColor(Color::BLACK, Color::BLACK);
                Screen::getInstance()->gotoXY(posX, posY);
                Color::getInstance()->consoleTextColor(Color::BLACK);
                cout << c;
                posX++;
            }
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                Color::getInstance()->consoleColor(Color::BLACK, Color::BLACK);
                Screen::getInstance()->gotoXY(posX, posY);
                Color::getInstance()->consoleTextColor(Color::BLACK);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}