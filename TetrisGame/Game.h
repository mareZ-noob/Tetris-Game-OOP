#pragma once
#include <conio.h>
#include <cstdlib>
#include <map>
#include <random>
#include <time.h>
#include <vector>

#include "Block.h"
#include "Grid.h"
#include "Constant.h"

using std::vector;

class Game {
private:
	vector<Block> blocks;
	vector<Block> allBlocks = { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
	map<int, char> blockSymbols = { {1, 'I'}, {2, 'J'}, {3, 'L'}, {4, 'O'}, {5, 'S'}, {6, 'T'}, {7, 'Z'} };
	Block currentBlock;
	Block nextBlock;
	Grid grid;
	int score;
	int level;
	bool gameOver;
public:
	Game();
	~Game();

	vector<Block> getBlocks() const;
	Block getRandomBlock();
	void handleInput();
	void gameDisplay();

	void moveLeft();
	void moveRight();
	void moveDown();
	void rotateBlock();

	bool verticalCollision();
	bool horizontalCollision();
	void disableBlock();

	void updateScore(int rowsDestroy);
	bool checkWin();
	void newGame();
};