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
	int grid[20][10];

	Grid();
	~Grid();

	void initGrid();
	void drawGrid();
	void drawBlock();

	bool isCellEmpty(int row, int col);
	bool isCellOutside(int row, int col);
	bool isRowFull(int row);
	void clearRow(int row);
	void moveRowDown(int row, int numRows);
	int clearRows();
};