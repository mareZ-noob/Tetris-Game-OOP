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

void Screen::goToXY(const int posX, const int posY) {
    COORD CursorPosition;
    CursorPosition.X = posX;
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
    if (hStdOut == INVALID_HANDLE_VALUE) {
        return;
    }

    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        return;
    }
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count)) {
        return;
    }
    
    if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) {
        return;
    }

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

void Screen::drawRectangle(int left, int top, int width, int height) {
    int i;
    goToXY(left, top);
    putchar(218);
    for (i = 0; i < width; i++) {
        putchar(196);
    }
    putchar(191);

    for (i = 0; i < height; i++) {
        goToXY(left, top + i + 1);
        putchar(179);
        goToXY(left + width + 1, top + i + 1);
        putchar(179);
    }

    goToXY(left, top + i);
    putchar(192);
    for (i = 0; i < width; i++) {
        putchar(196);
    }
    putchar(217);
}

void Screen::drawBorder() {
    Color::getInstance()->consoleTextColor(Color::LIGHTCYAN);
    drawRectangle(0, 0, 105, 35);
}

void Screen::drawBackButton()
{
    drawRectangle(0, 33, 21, 2);
    goToXY(1, 34);
    Color::getInstance()->consoleTextColor(Color::WHITE);
    printf("<< Press ");
    Color::getInstance()->consoleTextColor(Color::LIGHTRED);
    printf("Esc");
    Color::getInstance()->consoleTextColor(Color::WHITE);
    printf(" to back");

    Color::getInstance()->consoleTextColor(Color::LIGHTCYAN);
    goToXY(0, 33);
    cout << char(195);
    goToXY(22, 35);
    cout << char(193);
}


void Screen::createScreen()
{
    clearScreen();
    drawBorder();
    drawBackButton();
}

void Screen::Button(int x, int y, int w, int h, int textColor, int buttonColor, int color, string text) {
    Color::getInstance()->consoleColor(color, textColor);
    for (int iy = y + 1; iy <= y + h - 1; iy++) {
        for (int ix = x + 1; ix <= x + w - 1; ix++) {
            goToXY(ix, iy);
            cout << " ";
        }
    }

    goToXY(x + 1, y + 1);
    Color::getInstance()->consoleTextColor(textColor);
    cout << text;

    Color::getInstance()->consoleColor(color, textColor);
    Color::getInstance()->consoleTextColor(buttonColor);
    if (h <= 1 || w <= 1) {
        return;
    }

    for (int ix = x; ix <= x + w; ix++) {
        goToXY(ix, y);
        cout << char(196);
        goToXY(ix, y + h);
        cout << char(196);
    }

    for (int iy = y; iy <= y + h; iy++) {
        goToXY(x, iy);
        cout << char(179);
        goToXY(x + w, iy);
        cout << char(179);
    }

    goToXY(x, y);
    cout << char(218);
    goToXY(x + w, y);
    cout << char(191);
    goToXY(x, y + h);
    cout << char(192);
    goToXY(x + w, y + h);
    cout << char(217);
}