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
	int mode; // 1: easy, 2: hard
	int score;
	bool gameOver;
public:
	// Constructor and destructor
	Game();
	~Game();

	// Getters and setters
	vector<Block> getBlocks() const;
	int getMode() const;
	void setMode(int level);

	// Game display
	Block getRandomBlock();
	void handleInput();
	void drawNextBlock();
	void gameDisplay();

	// Movement
	void moveLeft();
	void moveRight();
	void moveDown();
	void rightRotateBlock();
	void leftRotateBlock();

	// Collision
	bool verticalCollision();
	bool horizontalCollision();
	void disableBlock();

	// Score
	void updateScore(int rowsDestroy);
	bool checkWin();
	void newGame();
};