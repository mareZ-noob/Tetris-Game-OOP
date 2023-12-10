#pragma once
#include <mutex>
#include <vector>
#include <Windows.h>

using std::vector;
using std::mutex;
using std::lock_guard;

class Color
{
private:
	static Color* instance;
	static mutex mutex_;

	int background;
	int text;
public:
	// Constructor and destructor
	Color();
	Color(int background, int text);
	~Color();

	// Getters and setters
	int getBackground() const;
	void setBackground(int background);
	int getText() const;
	void setText(int text);

	// Color constants
	static const int BLACK = 0;
	static const int BLUE = 1;
	static const int GREEN = 2;
	static const int CYAN = 3;
	static const int RED = 4;
	static const int MAGENTA = 5;
	static const int BROWN = 6;
	static const int LIGHTGRAY = 7;
	static const int DARKGRAY = 8;
	static const int LIGHTBLUE = 9;
	static const int LIGHTGREEN = 10;
	static const int LIGHTCYAN = 11;
	static const int LIGHTRED = 12;
	static const int LIGHTMAGENTA = 13;
	static const int YELLOW = 14;
	static const int WHITE = 15;

	// Methods
	static void consoleColor(int background, int text);
	static void consoleTextColor(int text);

	// 0: Black 1: Blue 2: Green 3: Cyan 4: Red 5: Magenta 6: Brown 7: LightGray 8: DarkGray 9: LightBlue 10: LightGreen 11: LightCyan 12: LightRed 13: LightMagenta 14: Yellow 15: White
	static vector<Color> getColors();

	// Singleton
	static Color* getInstance();
	static void deleteInstance();
	//Color(Color const&) = delete;
	//void operator=(Color const&) = delete;
};