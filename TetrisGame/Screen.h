#pragma once
#include <iostream>
#include <mutex>
#include <Windows.h>

#include "Color.h"
#include "Position.h"

using std::string;
using std::cout;
using std::endl;
using std::mutex;
using std::lock_guard;

class Screen
{
private:
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	HWND hWnd = GetConsoleWindow();

	static Screen* instance;
	static mutex mutex_;
public:
	Screen();
	~Screen();

	static Screen* getInstance();
	static void deleteInstance();

	void SetWindowSize(const int width, const int height);
	void SetScreenBufferSize(SHORT width, SHORT height);
	void DisableResizeWindow();
	void DisableCtrButton(bool Close, bool Min, bool Max);
	void ShowScrollbar(BOOL Show);
	void showCursor(bool visible);
	void moveCursor(const int posX, const int posY);
	void disableMouseInput();
	void consoleTitle();
	void clearScreen();
	void consoleInit();

	void DrawRectangle(Position pos, int width, int height, Color color);
};