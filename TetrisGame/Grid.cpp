#include "Grid.h"

Grid::Grid() {
	numRows = 20;
	numCols = 10;
	cellSize = 1;
	colors = Color::getInstance()->getBlockColors();
	initGrid();
}

Grid::~Grid() {

}

void Grid::initGrid() {
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			grid[i][j] = 0;
		}
	}
}

void Grid::drawGrid() {
	Screen::getInstance()->resetConsoleColor();
	for (int i = 0; i <= numRows; i++) {
		for (int j = 0; j <= numCols; j++) {
			Screen::getInstance()->moveCursor(j * cellSize + 10, i * cellSize + 10);
			cout << ".";
		}
	}
}

void Grid::drawBlock() {
	const int row = 11;
	const int col = 21;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			int cellValue = grid[i][j];
			Screen::getInstance()->DrawRectangle(col + 2*j, row + i, cellSize, cellSize, colors[cellValue], 'A');
		}
	}
}

bool Grid::isCellEmpty(int row, int col) {
	if (grid[row][col] == 0) {
		return true;
	}
	return false;
}

bool Grid::isCellOutside(int row, int col) {
	if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
		return false;
	}
	return true;
}

bool Grid::isRowFull(int row) {
	for (int column = 0; column < numCols; column++) {
		if (grid[row][column] == 0) {
			return false;
		}
	}
	return true;
}

void Grid::clearRow(int row) {
	for (int column = 0; column < numCols; column++) {
		grid[row][column] = 0;
	}
}

void Grid::moveRowDown(int row, int numRows) {
	for (int column = 0; column < numCols; column++) {
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}

int Grid::clearRows() {
	int completed = 0;
	for (int row = numRows - 1; row >= 0; row--) {
		if (isRowFull(row)) {
			clearRow(row);
			completed++;
		}
		else if (completed > 0) {
			moveRowDown(row, completed);
		}
	}
	return completed;
}