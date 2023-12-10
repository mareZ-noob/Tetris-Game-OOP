#include "Color.h"
#include "Screen.h"
#include <Windows.h>
#include "Grid.h"
#include "Block.h"
using namespace std;

int main()
{
	Screen::getInstance()->clearScreen();
	Grid grid = Grid();
	/*for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			grid.grid[i][j] = 1;
		}
	}
	grid.grid[0][0] = 1;
	grid.grid[0][1] = 2;
	grid.grid[0][2] = 3;*/
	Block block = OBlock();
	//block.Move(4, 3);

	Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);
	grid.DrawGrid();
	//grid.DrawBlock();
	block.Draw();
	Sleep(500000);

	return 0;
}