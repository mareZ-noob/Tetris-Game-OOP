#include "Color.h"
#include "Screen.h"
#include "Game.h"

int main() {
	Screen::getInstance()->consoleInit();
	Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);
	Game game = Game();
	game.runTetris();

	return 0;
}