#pragma once
#pragma once
#include <string>

using std::string;

class Player {
private:
	string name;
	int score;
	int time;
public:
	// Constructor and destructor
	Player();
	Player(string name, int score);
	Player(string name, int score, int time);
	~Player();

	// Getters and setters
	void setName(string name);
	string getName() const;
	void setScore(int score);
	int getScore() const;
	void setTime(int time);
	int getTime() const;
};