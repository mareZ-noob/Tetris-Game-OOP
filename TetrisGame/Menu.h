#pragma once
#include <conio.h>
#include <memory>
#include <utility>
#include <Windows.h>

#include "Color.h"
#include "Constant.h"
#include "Game.h"
#include "Graphic.h"
#include "Screen.h"

using std::cin;
using std::cout;
using std::endl;
using std::lock_guard;
using std::make_unique;
using std::mutex;
using std::string;
using std::unique_ptr;

class Menu {
private:
    int x, y, w, h;
    int textColor;
    int buttonColor;
    int backgroundColor;
    int selection;

    string playerName;
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
    void setPlayerName(string playerName);

    //Getter
    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;
    int getTextColor() const;
    int getButtonColor() const;
    int getBackgroundColor() const;
    int getSelection() const;
    string getPlayerName() const;

    // Console functions
    //MENU 1
    void MainMenu();
    void selectionMenu1();
    void printMainMenu();
    void PlayGame();
    void quit();

    //MENU 2
    void ClassicModernMenu();
    void selectionMenu2();
    void printClassicModernMenu();
   
    //MENU 3
    void ClassicModeMenu();
    void selectionMenu3();
    void printClassicModeMenu();

    //MENU 4
    void ModernModeMenu();
    void selectionMenu4();
    void printModernModeMenu();
};