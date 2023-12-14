#pragma once
#include <iostream>
#include <map>
#include <vector>

#include "Color.h"
#include "Constant.h"
#include "Screen.h"

using std::cout;
using std::map;
using std::pair;
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
	void clearRow(int row, int &bonus);
	void moveRowDown(int row, int numRows);
	pair<int, int> clearRows();
};