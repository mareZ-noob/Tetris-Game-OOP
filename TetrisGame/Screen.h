#pragma once
#include <iostream>
#include <mutex>
#include <Windows.h>

#include "Color.h"
#include "Position.h"

using std::cout;
using std::endl;
using std::mutex;
using std::lock_guard;
using std::string;

class Screen {
private:
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	HWND hWnd = GetConsoleWindow();

	static Screen* instance;
	static mutex mutex_;
public:
	// Constructor and destructor
	Screen();
	~Screen();

	// Singleton
	static Screen* getInstance();
	static void deleteInstance();

	// Console functions
	void SetWindowSize(const int width, const int height);
	void SetScreenBufferSize(SHORT width, SHORT height);
	void DisableResizeWindow();
	void DisableCtrButton(bool Close, bool Min, bool Max);
	void ShowScrollbar(BOOL Show);
	void showCursor(bool visible);
	void moveCursor(const double posX, const double posY);
	void goToXY(const int posX, const int posY);
	void disableMouseInput();
	void consoleTitle();
	void clearScreen();
	void resetConsoleColor();
	void consoleInit();

	// Draw functions
	void DrawRectangle(double posX, double posY, int width, int height, Color color, const char c);
	void drawRectangle(int left, int top, int width, int height);
	void drawBorder();
	void drawBackButton();
	void createScreen();
	void Button(int x, int y, int w, int h, int textColor, int buttonColor, int color, string text);
};