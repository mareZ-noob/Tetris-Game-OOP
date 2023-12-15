#include <iostream>
#include <memory>

#include "Menu.h"
#include "Screen.h"
#include "Sound.h"

using std::cin;
using std::ios_base;
using std::unique_ptr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Screen::getInstance()->consoleInit();
	
	unique_ptr<Menu> menu(new Menu());
	Sound::getInstance()->playSound(Sound::MARIO);
	menu->MainMenu();

	return 0;
}