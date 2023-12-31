#include "Leaderboard.h"

Leaderboard::Leaderboard() {

}

Leaderboard::~Leaderboard() {

}

bool Leaderboard::comparePlayers(const Player& p1, const Player& p2) {
    if (p1.getScore() != p2.getScore()) {
        return p1.getScore() > p2.getScore();
    }
    else {
        return p1.getTime() < p2.getTime();
    }
}

void Leaderboard::pushRecord(Player player) {
    ifstream ifs("Leaderboard.txt");
    vector<Player> players;
    while (!ifs.eof()) {
        string line;
        getline(ifs, line);
		if (line.empty()) {
			break;
		}
		stringstream ss(line);
		string item;
        while (getline(ss, item, '-')) {
			string name = item;
			getline(ss, item, '-');
			int score = stoi(item);
			getline(ss, item, '-');
			int time = stoi(item);
			players.push_back(Player(name, score, time));
		}
	}
    ifs.close();

	players.push_back(player);
	sort(players.begin(), players.end(), &Leaderboard::comparePlayers);
	ofstream ofs("Leaderboard.txt");

	// Top 5 players
	for (int i = 0; i < 5; i++) {
		ofs << players[i].getName() << "-" << players[i].getScore() << "-" << players[i].getTime() << "\n";
	}
	ofs.close();
}

void Leaderboard::printLeaderboard() {
	ifstream ifs("Leaderboard.txt");
	vector<Player> players;
	while (!ifs.eof()) {
		string line;
		getline(ifs, line);
		if (line.empty()) {
			break;
		}
		stringstream ss(line);
		string item;
		while (getline(ss, item, '-')) {
			string name = item;
			getline(ss, item, '-');
			int score = stoi(item);
			getline(ss, item, '-');
			int time = stoi(item);
			players.push_back(Player(name, score, time));
		}
	}
	Screen::getInstance()->drawBorder();
	Graphic::getInstance()->readFileAtPosition("static\\ascii\\leaderboard.txt", 13, 3, Color::BLACK, Color::LIGHTGREEN);

	Color::getInstance()->consoleTextColor(Color::LIGHTGREEN);
	Screen::getInstance()->drawRectangle(28, 14, 32, 15);
	Screen::getInstance()->drawRectangle(61, 14, 9, 15);
	Screen::getInstance()->drawRectangle(71, 14, 8, 15);

	Screen::getInstance()->Button(28, 14, 33, 2, Color::RED, Color::LIGHTGREEN, Color::BLACK, "              NAME");
	Screen::getInstance()->Button(61, 14, 10, 2, Color::RED, Color::LIGHTGREEN, Color::BLACK, "  POINT");
	Screen::getInstance()->Button(71, 14, 9, 2, Color::RED, Color::LIGHTGREEN, Color::BLACK, "  TIME");

	Screen::getInstance()->goToXY(28, 16);
	cout << char(195);
	Screen::getInstance()->goToXY(61, 16);
	cout << char(197);
	Screen::getInstance()->goToXY(71, 16);
	cout << char(197);
	Screen::getInstance()->goToXY(80, 16);
	cout << char(180);
	Screen::getInstance()->goToXY(61, 14);
	cout << char(194);
	Screen::getInstance()->goToXY(61, 29);
	cout << char(193);
	Screen::getInstance()->goToXY(71, 14);
	cout << char(194);
	Screen::getInstance()->goToXY(71, 29);
	cout << char(193);

	Color::getInstance()->consoleTextColor(Color::WHITE);
	for (int i = 0; i < players.size(); i++) {
		Screen::getInstance()->goToXY(30, 17 + i);
		cout << i + 1 << ". " << players[i].getName();
		Screen::getInstance()->goToXY(65, 17 + i);
		cout << players[i].getScore();
		Screen::getInstance()->goToXY(75, 17 + i);
		cout << players[i].getTime();
	}

	ifs.close();
}

Leaderboard* Leaderboard::instance = nullptr;
mutex Leaderboard::mutex_;
Leaderboard* Leaderboard::getInstance() {
	lock_guard<mutex> lock(mutex_);
	if (instance == nullptr) {
		instance = new Leaderboard();
	}
	return instance;
}

void Leaderboard::deleteInstance() {
	lock_guard<mutex> lock(mutex_);
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}