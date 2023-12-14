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
    void setTextColor(int textColor);
    void setButtonColor(int buttonColor);
    void setBackgroundColor(int backgroundColor);
    void setSelection(int selection);

    //Getter
    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;
    int getTextColor() const;
    int getButtonColor() const;
    int getBackgroundColor() const;
    int getSelection() const;

    // Singleton
    static Menu* getInstance();
    static void deleteInstance();

    // Console functions
    void quit();
    void PlayGame();
    void selectionMenu();
    void printMainMenu();
    void MainMenu();
    void ClassicModernMode();
};