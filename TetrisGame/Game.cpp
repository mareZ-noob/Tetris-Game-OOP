#include "Game.h"

Game::Game() {
	grid = Grid();
	blocks = getBlocks();
	setClassicMode(1);
	setCurrentBlock(getRandomBlock());
	setNextBlock(getRandomBlock());
	setScore(0);
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
		srand(unsigned int(time(NULL)));
		int random = rand() % blocks.size();
		Block block = blocks[random];
		return block;
	}
	else if (getClassicMode() == 2) {
		if (blocks.size() == 0) {
			blocks = getBlocks();
		}
		srand(unsigned int(time(NULL)));
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
	if (this->classicMode == 1) {
		setScore(10);
	}
	else if (this->classicMode == 2) {
		setScore(20);
	}
	else {
		setScore(0);
	}
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
		case KEY_x:
		case KEY_X:
		case KEY_SPACE:
			leftRotateBlock();
			break;
		case KEY_e:
		case KEY_E:
		case ENTER_KEY:
			dropBlock();
			break;
	}
}

void Game::drawNextBlock() {
	int cellSize = nextBlock.getCellSize();
	int cellValue = nextBlock.id;
	vector<Position> blockCells = nextBlock.getCellsPositions();
	for (Position cell : blockCells) {
		Screen::getInstance()->DrawRectangle(60 + 2 * cell.getCol(), 23 + cell.getRow(), cellSize, cellSize, Color::getInstance()->getBlockColors()[cellValue], blockSymbols[cellValue]);
	}
}

void Game::gameDisplay() {
	Screen::getInstance()->clearScreen();
	gameInformation();
	Screen::getInstance()->drawBorder();
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

void Game::runTetris(const string playerName, int classic, int mode) {
	unique_ptr<Game> game(new Game());
	unique_ptr<Player> pPlayer(new Player());
	pPlayer->setName(playerName);

	switch (classic) {
		case 1:
			game->setClassicMode(1);
			break;
		case 2:
			game->setClassicMode(2);
			break;
	}

	switch (mode) {
		case 1:
			game->easyMode();
			break;
		case 2:
			game->mediumMode();
			break;
		case 3:
			game->hardMode();
			break;
		case 4:
			game->veryHardMode();
			break;
	}
	const milliseconds updateInterval(game->getSpeed());

	future<void> handleInputFuture = async(launch::async, [&game]() {
		while (true) {
			if (game->checkGameFinish()) {
				break;
			}
			game->handleInput();
		}
	});

	clock_t time_req = clock();
	while (!checkGameFinish()) {
		if (game->getGameOver()) {
			break;
		}
		game->gameDisplay();
		sleep_for(updateInterval);
		game->moveDown();
		if (game->getGameOver()) {
			break;
		}
	}
	time_req = clock() - time_req;
	int time = time_req / CLOCKS_PER_SEC;
	pPlayer->setScore(game->getScore());
	pPlayer->setTime(time);
	Leaderboard::getInstance()->pushRecord(*pPlayer);
	if (game->getScore() == MAX_SCORE) {
		Screen::getInstance()->clearScreen();
		Graphic::getInstance()->artAtPosition("static\\ascii\\YouWin.txt", 32, 10, Color::BLACK, Color::LIGHTGREEN);
		Color::getInstance()->consoleTextColor(Color::WHITE);
		Screen::getInstance()->moveCursor(17, 20);
		cout << "YOUR SCORES: " << game->score << "pts  -  YOUR TIME: " << time << "s" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		exit(0);
	}
	else {
		Screen::getInstance()->clearScreen();
		Graphic::getInstance()->artAtPosition("static\\ascii\\GameOver.txt", 24, 10, Color::BLACK, Color::LIGHTRED);
		Color::getInstance()->consoleTextColor(Color::WHITE);
		Screen::getInstance()->moveCursor(17, 20);
		cout << "YOUR SCORES: " << game->score << "pts  -  YOUR TIME: " << time << "s" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
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

void Game::gameInformation() {
	// display name & score
	Screen::getInstance()->showCursor(0);
	Color::getInstance()->consoleTextColor(Color::WHITE);
	Screen::getInstance()->drawRectangle(50, 8, 36, 8);
	Screen::getInstance()->Button(50, 8, 37, 2, Color::LIGHTRED, Color::WHITE, Color::BLACK, "        PLAYER'S INFORMATION");
	Screen::getInstance()->goToXY(50, 10);
	cout << char(195);
	Screen::getInstance()->goToXY(87, 10);
	cout << char(180);

	Color::getInstance()->consoleTextColor(Color::CYAN);
	Screen::getInstance()->goToXY(52, 12);
	printf("Player's name:");
	Screen::getInstance()->goToXY(52, 14);
	printf("Score:");

	// display next block
	Color::getInstance()->consoleTextColor(Color::WHITE);
	Screen::getInstance()->drawRectangle(50, 19, 36, 7);
	Screen::getInstance()->Button(50, 19, 37, 2, Color::LIGHTRED, Color::WHITE, Color::BLACK, "             NEXT BLOCK");
	Screen::getInstance()->goToXY(50, 21);
	cout << char(195);
	Screen::getInstance()->goToXY(87, 21);
	cout << char(180);

	//// key guide
	//Screen::getInstance()->Button(45, 24, 27, 2, Color::LIGHTGREEN, Color::WHITE, Color::BLACK, " D/RIGHT KEY : Move right");
	//Screen::getInstance()->Button(78, 24, 25, 2, Color::LIGHTGREEN, Color::WHITE, Color::BLACK, " A/LEFT KEY : Move left");
	//Screen::getInstance()->Button(45, 27, 25, 2, Color::YELLOW, Color::WHITE, Color::BLACK, " S/DOWN KEY : Move down");
	//Screen::getInstance()->Button(78, 27, 17, 2, Color::YELLOW, Color::WHITE, Color::BLACK, " E/ENTER : DROP");
	//Screen::getInstance()->Button(45, 30, 26, 2, Color::LIGHTBLUE, Color::WHITE, Color::BLACK, " W/UP KEY : Rotate right");
	//Screen::getInstance()->Button(78, 30, 24, 2, Color::LIGHTBLUE, Color::WHITE, Color::BLACK, " X/SPACE : Rotate left");
	////Screen::getInstance()->Button(65, 32, 13, 2, Color::LIGHTRED, Color::WHITE, Color::BLACK, " ESC : EXIT");
}