#include "Screen.h"
#include "Menu.h"

int main() {
	Screen::getInstance()->consoleInit();
	Menu menu;
	menu.MainMenu();

	return 0;
}