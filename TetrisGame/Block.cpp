#include "Block.h"

Block::Block() {
	cellSize = 1;
	rotationState = 0;
	colors = Color::getInstance()->getBlockColors();
	rowOffset = 0;
	colOffset = 0;
	symbol = ' ';
}

Block::~Block() {
	
}

void Block::setSymbol(char symbol) { 
	this->symbol = symbol; 
}

char Block::getSymbol() const {
	return symbol; 
}

void Block::Draw() {
	vector<Position> blockCells = getCellsPositions();
	const int row = 11;
	const int col = 21;
	for (Position cell : blockCells) {
		Screen::getInstance()->DrawRectangle(col + 2*cell.getCol(), row + cell.getRow(), cellSize, cellSize, colors[id], getSymbol());
	}
}

void Block::Move(int rows, int cols) {
	rowOffset += rows;
	colOffset += cols;
}

vector<Position> Block::getCellsPositions() {
	vector<Position> blockCells = cells[rotationState];
	vector<Position> movedTiles;
	for (Position cell : blockCells) {
		movedTiles.push_back(Position(cell.getRow() + rowOffset, cell.getCol() + colOffset));
	}
	return movedTiles;
}

void Block::Rotate() {
	rotationState++;
	if (rotationState == cells.size()) {
		rotationState = 0;
	}
}

void Block::disRotate() {
	rotationState--;
	if (rotationState == -1) {
		rotationState = cells.size() - 1;
	}
}