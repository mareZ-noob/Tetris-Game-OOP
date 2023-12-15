#pragma once
#pragma once
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <mutex>
#include <string>
#include <sstream>
#include <vector>

#include "Color.h"
#include "Graphic.h"
#include "Menu.h"
#include "Player.h"
#include "Screen.h"

using std::cout;
using std::ifstream;
using std::lock_guard;
using std::mutex;
using std::ofstream;
using std::sort;
using std::string;
using std::stringstream;
using std::vector;

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