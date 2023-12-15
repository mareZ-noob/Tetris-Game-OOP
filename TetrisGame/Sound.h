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
public:
	Sound();
	~Sound();

	static const int MARIO = 1;
	static const int CLEAR = 2;
	static const int WIN = 3;
	static const int LOSE = 4;
	static const int SIU = 5;
	static const int WHISTLE = 6;
	static const int RICKROLL = 7;
	static const int SAUL = 8;
	static const int HAPPY = 9;

	static Sound* getInstance();
	static void deleteInstance();

	void playSound(int sound);
};