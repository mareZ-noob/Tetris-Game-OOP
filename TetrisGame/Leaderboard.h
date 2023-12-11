#pragma once

#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Player.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;
using std::sort;

class Leaderboard {
public:
	// Constructor and destructor
	Leaderboard();
	~Leaderboard();

	// Methods
	bool comparePlayers(const Player& p1, const Player& p2);
	void pushRecord(Player player);
	void printLeaderboard();
};