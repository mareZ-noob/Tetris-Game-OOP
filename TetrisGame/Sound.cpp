#include "Sound.h"

Sound::Sound()
{
}

Sound::~Sound()
{
}

Sound* Sound::instance = nullptr;
mutex Sound::mutex_;

Sound* Sound::getInstance()
{
	lock_guard<mutex> lock(mutex_);
	if (instance == nullptr)
	{
		instance = new Sound();
	}
	return instance;
}

void Sound::deleteInstance()
{
	lock_guard<mutex> lock(mutex_);
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void Sound::playSound(int sound)
{
	switch (sound)
	{
	case 1:
		PlaySound(TEXT("tetris.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 2:
		PlaySound(TEXT("clear.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 3:
		PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 4:
		PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}