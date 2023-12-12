#pragma once
#include <fstream>
#include <Windows.h>

#include "Color.h"
#include "Constant.h"
#include "Screen.h"

using std::ifstream;
using std::string;

class Graphic {
private:
    static Graphic* instance;
    static mutex mutex_;

    void drawCharacter(char character, double x, double y, int textColor, int backgroundColor);
    void drawTextFromFile(string fileName, int x, int y, int textColor, int backgroundColor);
public:
    // Constructor and destructor
    Graphic();
    ~Graphic();

    // Singleton
    static Graphic* getInstance();
    static void deleteInstance();

    // Console functions
    void artAtPosition(string fileName, int textColor, int backgroundColor, int x, int y);
    void readFileAtPosition(string fileName, int textColor, int backgroundColor, int x, int y);
    void pokemonBall(int x, int y);
};