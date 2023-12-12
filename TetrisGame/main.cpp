#include "Color.h"
#include "Screen.h"
#include "Game.h"
#include "Menu.h"

int main() {
	Screen::getInstance()->consoleInit();
	Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);
	Game game = Game();
	game.runTetris();
	/*Menu menu = Menu();
	menu.MainMenu();*/

	return 0;
}