#pragma once
#include <map>
#include <vector>

#include "Constant.h"
#include "Position.h"
#include "Screen.h"

using std::vector;
using std::map;

class Block {
private:
	int cellSize;
	int rotationState;
	vector<Color> colors;
	int rowOffset;
	int colOffset;
	char symbol;
public:
	int id;
	map<int, vector<Position>> cells;

	Block();
	~Block();

	void setSymbol(char symbol);
	char getSymbol() const;
	int getCellSize() const;

	void Draw();
	void Move(int rows, int cols);
	vector<Position> getCellsPositions();
	void Rotate();
	void disRotate();
};

class IBlock : public Block {
public:
	IBlock() {
		id = 1;
		setSymbol('I');
		cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
		cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
		cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
		Move(-1, 3);
	};
	~IBlock() = default;
};

class JBlock : public Block {
public:
	JBlock() {
		id = 2;
		setSymbol('J');
		cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
		Move(0, 3);
	}
	~JBlock() = default;
};

class LBlock : public Block {
public:
	LBlock() {
		id = 3;
		setSymbol('L');
		cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
		cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
	~LBlock() = default;
};

class OBlock : public Block {
public:
	OBlock() {
		id = 4;
		setSymbol('O');
		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		Move(0, 4);
	}
	~OBlock() = default;
};

class SBlock : public Block {
public: 
	SBlock() {
		id = 5;
		setSymbol('S');
		cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
		cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
	~SBlock() = default;
};

class TBlock : public Block {
public: 
	TBlock() {
		id = 6;
		setSymbol('T');
		cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
	~TBlock() = default;
};

class ZBlock : public Block {
public: 
	ZBlock() {
		id = 7;
		setSymbol('Z');
		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
		Move(0, 3);
	}
	~ZBlock() = default;
};