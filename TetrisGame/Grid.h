#pragma once
#include <iostream>
#include <vector>

#include "Color.h"
#include "Screen.h"

using std::cout;
using std::endl;
using std::vector;

class Grid
{
private:
	int numRows;
	int numCols;
	int cellSize;
	vector<Color> colors;
public:
	int grid[20][10];

	Grid();
	~Grid();

	void InitGrid();
	void DrawGrid();
	void DrawBlock();
};