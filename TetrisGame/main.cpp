#include "Screen.h"
#include "Menu.h"
#include <iostream>

using std::cin;
using std::ios_base;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Screen::getInstance()->consoleInit();
	Menu menu;
	menu.MainMenu();

	return 0;
}