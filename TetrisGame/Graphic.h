#pragma once
#include <fstream>
#include <string>

#include "Color.h"
#include "Constant.h"
#include "Screen.h"
#include <Windows.h>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

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
    void artAtPosition(string fileName, int backgroundColor, int textColor, int x, int y);
    void readFileAtPosition(string fileName, int x, int y, int backgroundColor, int textColor);
    void tetris1(int x, int y);
};