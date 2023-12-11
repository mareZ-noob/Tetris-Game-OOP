#include "Screen.h"

Screen::Screen() {

}

Screen::~Screen() {

}

Screen* Screen::instance = nullptr;
mutex Screen::mutex_;
Screen* Screen::getInstance() {
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr) {
        instance = new Screen();
    }
    return instance;
}

void Screen::deleteInstance() {
    lock_guard<mutex> lock(mutex_);
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

void Screen::SetWindowSize(const int width, const int height) {
	MoveWindow(hWnd, 280, 50, width, height, TRUE);
}

void Screen::SetScreenBufferSize(SHORT width, SHORT height) {
    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(console, NewSize);
}

void Screen::DisableResizeWindow() {
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void Screen::DisableCtrButton(bool Close, bool Min, bool Max) {
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1) {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1) {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1) {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void Screen::ShowScrollbar(BOOL Show) {
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void Screen::showCursor(bool visible) {
    CONSOLE_CURSOR_INFO cursor = { 1, visible };
    SetConsoleCursorInfo(console, &cursor);
}

void Screen::moveCursor(const double posX, const double posY) {
    COORD CursorPosition;
    CursorPosition.X = 2*posX;
    CursorPosition.Y = posY;
    SetConsoleCursorPosition(console, CursorPosition);
}

void Screen::disableMouseInput() {
    DWORD prev_mode;
    GetConsoleMode(hStdin, &prev_mode);
    SetConsoleMode(hStdin, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

void Screen::consoleTitle() {
    SetConsoleTitleW(L"Tetris Game");
}

void Screen::clearScreen() {
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return;

    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
        return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count))
        return;
    
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count))
        return;

    SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Screen::resetConsoleColor() {
    Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);
}

void Screen::consoleInit() {
    Screen::clearScreen();
    Screen::SetWindowSize(895, 620);
    Screen::consoleTitle();
    Screen::disableMouseInput();
    Screen::showCursor(0);
    Screen::ShowScrollbar(0);
    Screen::DisableResizeWindow();
    Screen::DisableCtrButton(0, 1, 1);
}

void Screen::DrawRectangle(double posX, double posY, int width, int height, Color color, const char c) {
    Color::getInstance()->consoleColor(color.getBackground(), color.getText());
    for (int i = 0; i < height; ++i) {
        moveCursor(posX/2, posY + i);
        for (int j = 0; j < width; ++j) {
            cout << c;
        }
    }
    Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);
}