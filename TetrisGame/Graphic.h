#pragma once
#include <Windows.h>
#include "Screen.h"
#include "Constant.h"
#include "Color.h"
#include <fstream>
#include <string>

class Graphic {
private:
    static Graphic* instance;
    static mutex mutex_;
public:
    // Constructor and destructor
    Graphic();
    ~Graphic();

    // Singleton
    static Graphic* getInstance();
    static void deleteInstance();

    // Console functions
    void artAtPosition(std::string fileName, int backgroundColor, int textColor, int x, int y);
    void readFileAtPosition(std::string fileName, int x, int y, int backgroundColor, int textColor);
    void tetris1(int x, int y);
};