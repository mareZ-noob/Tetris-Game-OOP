#include "Game.h"

Game::Game() {
	grid = Grid();
	blocks = getBlocks();
	setClassicMode(1);
	setCurrentBlock(getRandomBlock());
	setNextBlock(getRandomBlock());
	if (getClassicMode() == 1) {
		setScore(10);
	}
	else if (getClassicMode() == 2) {
		setScore(20);
	}
	setMode(1);
	setGameOver(false);
	setSpeed(300);
}

Game::~Game() {
	Leaderboard::deleteInstance();
	Screen::deleteInstance();
}

vector<Block> Game::getBlocks() const {
	return this->allBlocks;
}

Block Game::getRandomBlock() {
	if (getClassicMode() == 1) {
		srand(time(NULL));
		int random = rand() % blocks.size();
		Block block = blocks[random];
		return block;
	}
	else if (getClassicMode() == 2) {
		if (blocks.size() == 0) {
			blocks = getBlocks();
		}
		srand(time(NULL));
		int random = rand() % blocks.size();
		Block block = blocks[random];
		blocks.erase(blocks.begin() + random);
		return block;
	}
	return Block();
}

void Game::setCurrentBlock(Block block) {
	this->currentBlock = block;
}

void Game::setNextBlock(Block block) {
	this->nextBlock = block;
}

int Game::getMode() const {
	return this->mode;
}

void Game::setMode(int mode) {
	this->mode = mode;
}

int Game::getClassicMode() const {
	return this->classicMode;
}

void Game::setClassicMode(int classicMode) {
		this->classicMode = classicMode;
}

bool Game::getGameOver() const {
	return this->gameOver;
}

void Game::setGameOver(bool gameOver) {
	this->gameOver = gameOver;
}

int Game::getSpeed() const {
	return this->speed;
}

void Game::setSpeed(int speed) {
	this->speed = speed;
}

int Game::getScore() const {
	return this->score;
}

void Game::setScore(int score) {
	this->score = score;
}

void Game::handleInput() {
	int key = _getch();
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
		case ENTER_KEY:
			leftRotateBlock();
			break;
		case KEY_x:
		case KEY_X:
		case KEY_SPACE:
			dropBlock();
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
	if (getMode() == 1) {
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
		if (verticalCollision() || !horizontalCollision()) {
			currentBlock.Move(0, 1);
		}
	}
}

void Game::moveRight() {
	if (!gameOver) {
		currentBlock.Move(0, 1);
		if (verticalCollision() || !horizontalCollision()) {
			currentBlock.Move(0, -1);
		}
	}
}

void Game::moveDown() {
	if (!gameOver) {
		currentBlock.Move(1, 0);
		if (verticalCollision() || !horizontalCollision()) {
			currentBlock.Move(-1, 0);
			disableBlock();
		}
	}
}

void Game::rightRotateBlock() {
	if (!gameOver) {
		currentBlock.rightRotate();
		if (verticalCollision() || !horizontalCollision()) {
			currentBlock.leftRotate();
		}
	}
}

void Game::leftRotateBlock() {
	if (!gameOver) {
		currentBlock.leftRotate();
		if (verticalCollision() || !horizontalCollision()) {
			currentBlock.rightRotate();
		}
	}
}

void Game::dropBlock() {	
	if (!gameOver) {
		while (true) {
			currentBlock.Move(1, 0);
			if (verticalCollision() || !horizontalCollision()) {
				currentBlock.Move(-1, 0);
				disableBlock();
				break;
			}
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
		if (!grid.isCellEmpty(cell.getRow(), cell.getCol())) {
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
	setCurrentBlock(nextBlock);
	if (horizontalCollision() == false) {
		setGameOver(true);
	}
	setNextBlock(getRandomBlock());
	int rowsDestroy = grid.clearRows().first;
	if (rowsDestroy > 0) {
		updateScore(rowsDestroy, grid.clearRows().second);
	}
}

void Game::updateScore(int rowsDestroy, int bonus) {
	if (getMode() == 1) {
		score += (rowsDestroy * 10 + bonus);
	}
	else if (getMode() == 2) {
		score += (rowsDestroy * 30 + bonus);
	}
}

bool Game::checkGameFinish() {
	if (getScore() > MAX_SCORE) {
		setScore(MAX_SCORE);
		gameOver = true;
		return true;
	}
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
	speed = 200;
}

void Game::runTetris() {
	Game game = Game();
	game.easyMode();
	const milliseconds updateInterval(game.getSpeed());

    future<void> handleInputFuture = async(launch::async, [&game]() {
        while (true) {
			if (game.checkGameFinish()) {
				break;
			}
			game.handleInput();
        }
    });
	Player player = Player("nam");
	clock_t time_req = clock();
    while (!checkGameFinish()) {
		if (game.getGameOver()) {
			break;
		}
        game.gameDisplay();
        sleep_for(updateInterval);
        game.moveDown();
		if (game.getGameOver()) {
			break;
		}
    }
	time_req = clock() - time_req;
	int time = time_req / CLOCKS_PER_SEC;
	player.setScore(game.getScore());
	player.setTime(time);
	Leaderboard::getInstance()->pushRecord(player);
	if (game.getScore() == MAX_SCORE) {
		Screen::getInstance()->clearScreen();
		Screen::getInstance()->moveCursor(0, 0);
		cout << "You win! Your score is is: " << game.score << " time: " << time << endl;
		Sleep(2000);
		exit(0);
	}
	else {
		Screen::getInstance()->clearScreen();
		Screen::getInstance()->moveCursor(0, 0);
		cout << "Game over! Your score is is: " << game.score << " time: " << time << endl;
		Sleep(2000);
		exit(0);
	}
}

void Game::easyMode() {
	setMode(1);
	setSpeed(300);
}

void Game::mediumMode() {
	setMode(1);
	setSpeed(100);
}

void Game::hardMode() {
	setMode(2);
	setSpeed(300);
}

void Game::veryHardMode() {
	setMode(2);
	setSpeed(200);
}