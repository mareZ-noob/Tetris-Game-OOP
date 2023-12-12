#pragma once
#include <Windows.h>
#include "Screen.h"
#include "Constant.h"
#include "Color.h"
#include <fstream>

class Graphic {
private:
    static Graphic* instance;
    static mutex mutex_;

    void drawCharacter(char character, double x, double y, int textColor, int backgroundColor);
    void drawTextFromFile(std::string fileName, int x, int y, int textColor, int backgroundColor);
public:
    // Constructor and destructor
    Graphic();
    ~Graphic();

    // Singleton
    static Graphic* getInstance();
    static void deleteInstance();

    // Console functions
    void artAtPosition(std::string fileName, int textColor, int backgroundColor, int x, int y);
    void readFileAtPosition(std::string fileName, int textColor, int backgroundColor, int x, int y);
    void pokemonBall(int x, int y);
};