#include "Grid.h"

Grid::Grid()
{
	numRows = 20;
	numCols = 10;
	cellSize = 1;
	colors = Color::getInstance()->getBlockColors();
	InitGrid();
}

Grid::~Grid()
{
}

void Grid::InitGrid()
{
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			grid[i][j] = 0;
		}
	}
}

void Grid::DrawGrid()
{
	for (int i = 0; i <= numRows; i++) {
		for (int j = 0; j <= numCols; j++) {
			Screen::getInstance()->moveCursor(j * cellSize + 10, i * cellSize + 10);
			cout << ".";
		}
	}
	Screen::getInstance()->resetConsoleColor();
}

void Grid::DrawBlock()
{
	const int row = 11, col = 21;
	int pX = 0;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			int cellValue = grid[i][j];
			Screen::getInstance()->DrawRectangle(col + j + pX, row + i, cellSize, cellSize, colors[cellValue], 'A');
			pX+=1;
		}
		pX = 0;
	}
}