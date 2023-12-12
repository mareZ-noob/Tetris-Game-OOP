#pragma once
#include <chrono>
#include <conio.h>
#include <cstdlib>
#include <future>
#include <map>
#include <random>
#include <time.h>
#include <thread>
#include <vector>

#include "Block.h"
#include "Grid.h"
#include "Constant.h"

using std::async;
using std::chrono::milliseconds;
using std::future;
using std::launch;
using std::this_thread::sleep_for;
using std::vector;

class Game {
private:
	vector<Block> blocks;
	vector<Block> allBlocks = { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
	map<int, char> blockSymbols = { {1, 'I'}, {2, 'J'}, {3, 'L'}, {4, 'O'}, {5, 'S'}, {6, 'T'}, {7, 'Z'} };
	Block currentBlock;
	Block nextBlock;
	Grid grid;
	int mode; // 1: easy, 2: medium, 3: hard, 4: very hard
	int score;
	bool gameOver;
	int speed;
public:
	// Constructor and destructor
	Game();
	~Game();

	// Getters and setters
	vector<Block> getBlocks() const;
	int getMode() const;
	void setMode(int level);
	bool getGameOver() const;
	void setSpeed(int speed);
	int getSpeed() const;

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
	void dropBlock();

	// Collision
	bool verticalCollision();
	bool horizontalCollision();
	void disableBlock();

	// Score
	void updateScore(int rowsDestroy);
	bool checkLose();
	void newGame();

	// Game mode
	void easyMode();
	void mediumMode();
	void hardMode();
	void veryHardMode();

	// Game start
	void runTetris();
};