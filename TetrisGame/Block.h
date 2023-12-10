#pragma once
#include <map>
#include <vector>

#include "Position.h"
#include "Color.h"

using std::vector;
using std::map;

class Block
{
private:
	int cellSize;
	int rotationState;
	vector<Color> colors;
	int rowOffset;
	int colOffset;
protected:
	int id;
	std::map<int, std::vector<Position>> cells;

	Block();
	~Block();

	void Move(int rows, int cols);
	void Rotate();
	void UndoRotate();

};

class IBlock : public Block
{
public:
	IBlock() {

	};

	~IBlock() = default;
};

class JBlock : public Block
{
public:
	JBlock();
	~JBlock();
};

class LBlock : public Block
{
public:
	LBlock();
	~LBlock();
};

class OBlock : public Block
{
public:
	OBlock();
	~OBlock();
};

class SBlock : public Block
{
public: 
	SBlock();
	~SBlock();
};

class TBlock : public Block
{
public: 
	TBlock();
	~TBlock();
};

class ZBlock : public Block
{
public: 
	ZBlock();
	~ZBlock();
};