#pragma once
#include <chrono>
#include <conio.h>
#include <cstdlib>
#include <future>
#include <map>
#include <memory>
#include <random>
#include <time.h>
#include <thread>
#include <vector>

#include "Block.h"
#include "Color.h"
#include "Constant.h"
#include "Graphic.h"
#include "Grid.h"
#include "Leaderboard.h"
#include "Player.h"
#include "Screen.h"
#include "Sound.h"

using std::async;
using std::chrono::milliseconds;
using std::future;
using std::launch;
using std::thread;
using std::this_thread::sleep_for;
using std::unique_ptr;
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
	int classicMode; // 1: Full blocks display each set, 2: Random blocks display each set
	bool gameOver;
	int speed;
	int score;
public:
	// Constructor and destructor
	Game();
	~Game();

	// Getters and setters
	vector<Block> getBlocks() const;
	Block getRandomBlock();
	void setCurrentBlock(Block block);
	void setNextBlock(Block block);
	int getMode() const;
	void setMode(int mode);
	int getClassicMode() const;
	void setClassicMode(int classicMode);
	bool getGameOver() const;
	void setGameOver(bool gameOver);
	int getSpeed() const;
	void setSpeed(int speed);
	int getScore() const;
	void setScore(int score);

	// Game display
	void handleInput();
	void drawNextBlock();
	void gameDisplay(string name, int score);

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
	void updateScore(int rowsDestroy, int bonus);
	bool checkGameFinish();
	void newGame();

	// Game mode
	void easyMode();
	void mediumMode();
	void hardMode();
	void veryHardMode();

	// Game's Information
	void gameInformation();

	// Game start
	void runTetris(const string playerName, int classic, int mode);

	// Delete all instances
	void deleteAllInstances();
};