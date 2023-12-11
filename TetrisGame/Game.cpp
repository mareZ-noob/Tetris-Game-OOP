#include "Game.h"

Game::Game() {
	grid = Grid();
	blocks = getBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
	score = 0;
	level = 1;
	gameOver = false;
}

Game::~Game() {
	Color::deleteInstance();
	Screen::deleteInstance();
}

vector<Block> Game::getBlocks() const {
	return this->allBlocks;
}


Block Game::getRandomBlock() {
	srand(time(NULL));
	int random = rand() % blocks.size();
	Block block = blocks[random];
	return block;
}

void Game::handleInput() {
	int key = _getch();
	/*if (gameOver && key != 0) {
		gameOver = false;
		newGame();
	}*/
	switch (key) {
		case KEY_LEFT:
			moveLeft();
			break;
		case KEY_RIGHT:
			moveRight();
			break;
		case KEY_DOWN:
			moveDown();
			break;
		case KEY_UP:
			rotateBlock();
			break;
	}
}

void Game::gameDisplay() {
	Screen::getInstance()->clearScreen();
	grid.drawGrid();
	currentBlock.Draw();
}

void Game::moveLeft() {
	if (!gameOver) {
		currentBlock.Move(0, -1);
		if (verticalCollision() || horizontalCollision() == false) {
			currentBlock.Move(0, 1);
		}
	}
}

void Game::moveRight() {
	if (!gameOver) {
		currentBlock.Move(0, 1);
		if (verticalCollision() || horizontalCollision() == false) {
			currentBlock.Move(0, -1);
		}
	}
}

void Game::moveDown() {
	if (!gameOver) {
		currentBlock.Move(1, 0);
		if (verticalCollision() || horizontalCollision() == false) {
			currentBlock.Move(-1, 0);
			disableBlock();
		}
	}
}

void Game::rotateBlock() {
	if (!gameOver) {
		currentBlock.Rotate();
		if (verticalCollision() || horizontalCollision() == false) {
			currentBlock.disRotate();
		}
	}
}

bool Game::verticalCollision() {
	vector<Position> blockCells = currentBlock.getCellsPositions();
	for (Position cell : blockCells) {
		if (grid.isCellOutside(cell.getRow(), cell.getCol())) {
			return true;
		}
	}
	return false;
}

bool Game::horizontalCollision() {
	vector<Position> blockCells = currentBlock.getCellsPositions();
	for (Position cell : blockCells) {
		if (grid.isCellEmpty(cell.getRow(), cell.getCol()) == false) {
			return false;
		}
	}
	return true;
}

void Game::disableBlock() {
	vector<Position> blockCells = currentBlock.getCellsPositions();
	for (Position cell : blockCells) {
		grid.grid[cell.getRow()][cell.getCol()] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (horizontalCollision() == false) {
		gameOver = true;
	}
	nextBlock = getRandomBlock();
	int rowsDestroy = grid.clearRows();
	if (rowsDestroy > 0) {
		updateScore(rowsDestroy);
	}
}

void Game::updateScore(int rowsDestroy) {
	score += rowsDestroy * 100;
}

bool Game::checkWin() {
	return false;
}

void Game::newGame() {
	grid.initGrid();
	blocks = getBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
	level++;
	score = 0;
}