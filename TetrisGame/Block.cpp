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

int Block::getCellSize() const {
	return cellSize;
}

void Block::Draw() {
	vector<Position> blockCells = getCellsPositions();
	for (Position cell : blockCells) {
		Screen::getInstance()->DrawRectangle(COL + 2*cell.getCol(), ROW + cell.getRow(), cellSize, cellSize, colors[id], getSymbol());
	}
}

void Block::Move(int rows, int cols) {
	rowOffset += rows;
	colOffset += cols;
}

vector<Position> Block::getCellsPositions() {
	vector<Position> blockCells = cells[rotationState];
	vector<Position> move;
	for (Position cell : blockCells) {
		move.push_back(Position(cell.getRow() + rowOffset, cell.getCol() + colOffset));
	}
	return move;
}

void Block::rightRotate() {
	rotationState++;
	if (rotationState == cells.size()) {
		rotationState = 0;
	}
}

void Block::leftRotate() {
	rotationState--;
	if (rotationState == -1) {
		rotationState = cells.size() - 1;
	}
}