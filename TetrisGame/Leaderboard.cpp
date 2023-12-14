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