#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <mutex>

#pragma comment(lib, "winmm.lib")

using std::mutex;
using std::lock_guard;

class Sound {
private:
	static Sound* instance;
	static mutex mutex_;
public:
	// Constructor and destructor
	Sound();
	~Sound();

	// Sound constants
	static const int CARELESS_WHISPER = 1;
	static const int CLEAR = 2;
	static const int FLUFFING_OF_DUCKS = 3;
	static const int LOSE = 4;
	static const int MARIO = 5;
	static const int MII_CHANNEL = 6;
	static const int RICK_ROLL = 7;
	static const int SAD_VIOLIN = 8;
	static const int SAUL = 9;
	static const int TO_BE_CONTINUED = 10;
	static const int WHISTLE = 11;
	static const int WIN = 12;
	static const int WISH = 13;

	// Singleton 
	static Sound* getInstance();
	static void deleteInstance();

	// Play sound
	void playSound(int sound);
};