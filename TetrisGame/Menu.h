#pragma once
#include <conio.h>
#include <Windows.h>

#include "Color.h"
#include "Constant.h"
#include "Graphic.h"
#include "Screen.h"

using std::cout;
using std::endl;
using std::lock_guard;
using std::mutex;
using std::string;

class Menu {
private:
    static Menu* instance;
    static mutex mutex_;

    int x, y, w, h;
    int textColor;
    int buttonColor;
    int backgroundColor;
    int selection;
public:
    // Constructor and destructor
    Menu();
    ~Menu();

    // Setter
    void setX(int x);
    void setY(int y);
    void setW(int w);
    void setH(int h);

    //Getter
    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;

    // Singleton
    static Menu* getInstance();
    static void deleteInstance();

    // Console functions
    void quit();
    void PlayGame();
    void selectionMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
    void printMainMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
    void MainMenu();
    //void ClassicModernMode(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
};