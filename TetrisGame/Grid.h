#pragma once
#include <iostream>
#include <vector>

#include "Color.h"
#include "Constant.h"
#include "Screen.h"

using std::cout;
using std::vector;

class Grid {
private:
	int numRows;
	int numCols;
	int cellSize;
	vector<Color> colors;
public:
	// Public attributes
	int grid[20][10];

	// Constructor and destructor
	Grid();
	~Grid();

	// Grid drawing
	void initGrid();
	void drawGrid();
	void drawBlock();

	// Check cells
	bool isCellEmpty(int row, int col);
	bool isCellOutside(int row, int col);
	bool isRowFull(int row);

	// Clear full rows
	void clearRow(int row);
	void moveRowDown(int row, int numRows);
	int clearRows();
};