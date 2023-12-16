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