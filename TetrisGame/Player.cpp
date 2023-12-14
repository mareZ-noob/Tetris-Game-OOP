#include "Player.h"

Player::Player() {
	name = "";
	score = 0;
	time = 0;
}

Player::Player(string name) {
	this->name = name;
	score = 0;
	time = 0;
}

Player::Player(string name, int score) {
	this->name = name;
	this->score = score;
	time = 0;
}

Player::Player(string name, int score, int time) {
	this->name = name;
	this->score = score;
	this->time = time;
}

Player::~Player() {

}

void Player::setName(string name) {
	this->name = name;
}

string Player::getName() const {
	return name;
}

void Player::setScore(int score) {
	this->score = score;
}

int Player::getScore() const {
	return score;
}

void Player::setTime(int time) {
	this->time = time;
}

int Player::getTime() const {
	return time;
}