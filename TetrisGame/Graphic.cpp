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

void Graphic::artAtPosition(string fileName, int x, int y, int backgroundColor, int textColor) {
    ifstream file(fileName);
    string line;
    while (getline(file, line)) {
        Screen::getInstance()->goToXY(x, y++);
        Color::getInstance()->consoleColor(backgroundColor, textColor);
        Color::getInstance()->consoleTextColor(textColor);
        cout << line << endl;
    }
    file.close();
}

void Graphic::readFileAtPosition(string fileName, int x, int y, int backgroundColor, int textColor) {
    ifstream file(fileName);
    string text;
    while (getline(file, text)) {
        Screen::getInstance()->goToXY(x, y++);
        Color::getInstance()->consoleColor(backgroundColor, textColor);
        Color::getInstance()->consoleTextColor(textColor);
        cout << text << endl;
    }
    file.close();
}

void Graphic::tetris1(int x, int y) {
    ifstream file("static\\ascii\\tetris1.txt");
    int backgroundColor = 0;
    if (file.is_open()) {
        char c;
        int posX = x, posY = y;
        while (file.get(c)) {
            if (c == '~') {
                Color::getInstance()->consoleColor(Color::BLACK, Color::LIGHTBLUE);
                Screen::getInstance()->goToXY(posX, posY);
                Color::getInstance()->consoleTextColor(Color::LIGHTBLUE);
                cout << c;
                posX++;
            }
            else if (c == '?') {
                Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);
                Screen::getInstance()->goToXY(posX, posY);
                Color::getInstance()->consoleTextColor(Color::WHITE);
                cout << c;
                posX++;
            }
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                Color::getInstance()->consoleColor(Color::BLACK, Color::RED);
                Screen::getInstance()->goToXY(posX, posY);
                Color::getInstance()->consoleTextColor(Color::RED);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}