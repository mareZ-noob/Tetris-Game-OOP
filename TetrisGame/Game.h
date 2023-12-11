#pragma once
#include <conio.h>
#include <cstdlib>
#include <random>
#include <time.h>
#include <vector>

#include "Block.h"
#include "Grid.h"
#include "header.h"

using std::vector;

class Game {
private:
	vector<Block> blocks;
	vector<Block> allBlocks = { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
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