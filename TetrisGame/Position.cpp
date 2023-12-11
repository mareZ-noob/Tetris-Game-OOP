#include "Position.h"

Position::Position(int row, int col) {
	this->row = row;
	this->col = col;
}

Position::~Position() {

}

int Position::getRow() const {
	return this->row;
}

int Position::getCol() const {
	return this->col;
}

void Position::setRow(int row) {
	this->row = row;
}

void Position::setCol(int col) {
	this->col = col;
}