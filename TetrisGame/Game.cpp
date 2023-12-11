#include "Game.h"

Game::Game() {
	grid = Grid();
	blocks = getBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
	score = 0;
	mode = 1;
	gameOver = false;
	speed = 300;
}

Game::~Game() {
	Color::deleteInstance();
	Screen::deleteInstance();
}

vector<Block> Game::getBlocks() const {
	return this->allBlocks;
}

int Game::getMode() const {
	return this->mode;
}

void Game::setMode(int level) {
	this->mode = level;
}

bool Game::getGameOver() const {
	return this->gameOver;
}

void Game::setSpeed(int speed) {
	this->speed = speed;
}

int Game::getSpeed() const {
	return this->speed;
}

Block Game::getRandomBlock() {
	srand(time(NULL));
	int random = rand() % blocks.size();
	Block block = blocks[random];
	return block;
}

void Game::handleInput() {
	int key = _getch();
	if (gameOver && key != 0) {
		//newGame();
		Screen::getInstance()->clearScreen();
		Screen::getInstance()->moveCursor(0, 0);
		cout << "Game over! Your score is: " << score << endl;
		Sleep(1000);
	}
	switch (key) {
		case KEY_a:
		case KEY_A:
		case KEY_LEFT:
			moveLeft();
			break;
		case KEY_d:
		case KEY_D:
		case KEY_RIGHT:
			moveRight();
			break;
		case KEY_s:
		case KEY_S:
		case KEY_DOWN:
			moveDown();
			break;
		case KEY_w:
		case KEY_W:
		case KEY_UP:
			rightRotateBlock();
			break;
		case KEY_e:
		case KEY_E:
		case KEY_SPACE:
			leftRotateBlock();
			break;
	}
}

void Game::drawNextBlock() {
	int cellSize = nextBlock.getCellSize();
	int cellValue = nextBlock.id;
	vector<Position> blockCells = nextBlock.getCellsPositions();
	for (Position cell : blockCells) {
		Screen::getInstance()->DrawRectangle(45 + 2 * cell.getCol(), 15 + cell.getRow(), cellSize, cellSize, Color::getInstance()->getBlockColors()[cellValue], blockSymbols[cellValue]);
	}
}

void Game::gameDisplay() {
	Screen::getInstance()->clearScreen();
	grid.drawGrid();
	currentBlock.Draw();
	drawNextBlock();
	if (mode == 1) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 10; j++) {
				if (grid.grid[i][j] != 0) {
					int cellValue = grid.grid[i][j];
					int cellSize = currentBlock.getCellSize();
					Screen::getInstance()->DrawRectangle(COL + 2 * j, ROW + i, cellSize, cellSize, Color::getInstance()->getBlockColors()[cellValue], blockSymbols[cellValue]);
				}
			}
		}
	}
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

void Game::rightRotateBlock() {
	if (!gameOver) {
		currentBlock.rightRotate();
		if (verticalCollision() || horizontalCollision() == false) {
			currentBlock.leftRotate();
		}
	}
}

void Game::leftRotateBlock() {
	if (!gameOver) {
		currentBlock.leftRotate();
		if (verticalCollision() || horizontalCollision() == false) {
			currentBlock.rightRotate();
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
	if (mode == 1) {
		score += rowsDestroy * 10;
	}
	else if (mode == 2) {
		score += rowsDestroy * 50;
	}
}

bool Game::checkLose() {
	for (int i = 0; i < 10; i++) {
		if (grid.grid[0][i] != 0) {
			gameOver = true;
			return true;
		}
	}
	return false;
}

void Game::newGame() {
	grid.initGrid();
	blocks = getBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
	score = 0;
	gameOver = false;
	mode = 1;
	speed = 300;
}

void Game::runTetris() {
	Game game = Game();
	const milliseconds updateInterval(speed);

    future<void> handleInputFuture = async(launch::async, [&game]() {
        while (true) {
            game.handleInput();
        }
    });
    while (true) {
        game.gameDisplay();
        sleep_for(updateInterval);
        game.moveDown();

		if (game.checkLose()) {
			Screen::getInstance()->clearScreen();
			Screen::getInstance()->moveCursor(0, 0);
			cout << "Game over! Your score is: " << game.score << endl;
			Sleep(1000);
			break;
		}
    }
}