#pragma once
class Position
{
private:
	int row;
	int col;
public:
	Position(int row, int col);
	~Position();
	int getRow();
	int getCol();
	void setRow(int row);
	void setCol(int col);
};

