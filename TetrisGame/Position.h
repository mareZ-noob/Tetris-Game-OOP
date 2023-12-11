#pragma once

class Position {
private:
	int row;
	int col;
public:
	// Constructor and destructor
	Position(int row, int col);
	~Position();

	// Getters and setters
	int getRow() const;
	int getCol() const;
	void setRow(int row);
	void setCol(int col);
};