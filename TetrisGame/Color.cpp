#include "Color.h"

Color::Color()
{
}

Color::Color(int background, int text)
{
	this->background = background;
	this->text = text;
	consoleColor(background, text);
}

Color::~Color()
{
}

int Color::getBackground() const { 
	return background; 
}
void Color::setBackground(int background) { 
	this->background = background; 
}
int Color::getText() const { 
	return text; 
}
void Color::setText(int text) { 
	this->text = text; 
}

void Color::consoleColor(int background, int text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background * 16 + text);
}

void Color::consoleTextColor(int text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

vector<Color> Color::getColors()
{
	return {
		Color(BLACK, BLACK),
		Color(BLUE, BLUE),
		Color(GREEN, GREEN),
		Color(CYAN, CYAN),
		Color(RED, RED),
		Color(MAGENTA, MAGENTA),
		Color(BROWN, BROWN),
		Color(LIGHTGRAY, LIGHTGRAY),
		Color(DARKGRAY, DARKGRAY),
		Color(LIGHTBLUE, LIGHTBLUE),
		Color(LIGHTGREEN, LIGHTGREEN),
		Color(LIGHTCYAN, LIGHTCYAN),
		Color(LIGHTRED, LIGHTRED),
		Color(LIGHTMAGENTA, LIGHTMAGENTA),
		Color(YELLOW, YELLOW),
		Color(WHITE, WHITE)
	};
}

vector<Color> Color::getBlockColors()
{
	return {
		Color(Color::BLACK, Color::BLACK),
		Color(Color::BLACK, Color::GREEN),
		Color(Color::BLACK, Color::RED),
		Color(Color::BLACK, Color::BROWN),
		Color(Color::BLACK, Color::YELLOW),
		Color(Color::BLACK, Color::MAGENTA),
		Color(Color::BLACK, Color::CYAN),
		Color(Color::BLACK, Color::BLUE),
	};
}

Color* Color::instance = nullptr;
mutex Color::mutex_;
Color* Color::getInstance()
{
	lock_guard<mutex> lock(mutex_);
	if (instance == nullptr)
	{
		instance = new Color();
	}
	return instance;
}

void Color::deleteInstance()
{
	lock_guard<mutex> lock(mutex_);
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}