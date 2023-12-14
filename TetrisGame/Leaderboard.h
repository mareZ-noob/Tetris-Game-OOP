#pragma once
#include <algorithm>
#include <fstream>
#include <mutex>
#include <string>
#include <sstream>
#include <vector>

#include "Player.h"

using std::ifstream;
using std::lock_guard;
using std::mutex;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;
using std::sort;

class Leaderboard {
private:
	static Leaderboard* instance;
	static mutex mutex_;
public:
	// Constructor and destructor
	Leaderboard();
	~Leaderboard();

	// Methods
	static bool comparePlayers(const Player& p1, const Player& p2);
	void pushRecord(Player player);
	void printLeaderboard();

	// Singleton
	static Leaderboard* getInstance();
	static void deleteInstance();
};