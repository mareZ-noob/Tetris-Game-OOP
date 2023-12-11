#include "Color.h"
#include "Screen.h"
#include <Windows.h>
#include "Grid.h"
#include "Block.h"
#include "Game.h"
using namespace std;

int main() {
	Screen::getInstance()->consoleInit();
	
	Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);

	Game game = Game();
	while (true) {
		game.gameDisplay();
		game.handleInput();
	}
	Sleep(500000);

	return 0;
}