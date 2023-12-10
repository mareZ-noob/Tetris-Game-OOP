#include "Color.h"
#include "Screen.h"
#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	vector<Color> colors = Color::getColors();
	Screen::getInstance()->consoleInit();
	Screen::getInstance()->DrawRectangle(Position(1, 10), 10, 10, colors[2]);

	Sleep(5000);
	Screen::deleteInstance();
	Color::deleteInstance();

	return 0;
}