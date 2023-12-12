#pragma once
#include <conio.h>
#include <Windows.h>

#include "Color.h"
#include "Constant.h"
#include "Screen.h"

using std::string;

class Menu {
private:
    static Menu* instance;
    static mutex mutex_;

    int x;
    int y;
    int w;
    int h;
    int textColor;
    int buttonColor;
    int backgroundColor;
    string email;
    int selection;
public:
    // Constructor and destructor
    Menu();
    ~Menu();

    // Singleton
    static Menu* getInstance();
    static void deleteInstance();

    // Console functions
    //void quit();
    //void login(std::string& email);
    void selectionMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
    void printMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
    void MainMenu();
    //void selectionMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
    //void printMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
    ////void LoginMenu();
    //void selectionPlayGame(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
    //void printPlayGame(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
    //void GamePlayMenu();
    //void HowToPlay();
};