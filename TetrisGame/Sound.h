#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <mutex>

using std::mutex;
using std::lock_guard;

class Sound
{
private:
	static Sound* instance;
	static mutex mutex_;

	Sound();
	~Sound();
public:
	static const int TETRIS = 1;
	static const int CLEAR = 2;
	static const int GAMEOVER = 3;
	static const int MOVE = 4;

	static Sound* getInstance();
	static void deleteInstance();
	
	void playSound(int sound);
};