#include "Sound.h"

Sound::Sound() {

}

Sound::~Sound() {

}

Sound* Sound::instance = nullptr;
mutex Sound::mutex_;
Sound* Sound::getInstance() {
	lock_guard<mutex> lock(mutex_);
	if (instance == nullptr) {
		instance = new Sound();
	}
	return instance;
}

void Sound::deleteInstance() {
	lock_guard<mutex> lock(mutex_);
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

void Sound::playSound(int sound) {
	switch (sound) {
	case 1:
		PlaySound(TEXT("sounds\\carelesswhisper.wav"), NULL, SND_ASYNC);
		break;
	case 2:
		PlaySound(TEXT("sounds\\clear.wav"), NULL, SND_ASYNC);
		break;
	case 3:
		PlaySound(TEXT("sounds\\fluffingofducks.wav"), NULL, SND_ASYNC);
		break;
	case 4:
		PlaySound(TEXT("sounds\\lose.wav"), NULL, SND_ASYNC);
		break;
	case 5:
		PlaySound(TEXT("sounds\\mario.wav"), NULL, SND_ASYNC);
		break;
	case 6:
		PlaySound(TEXT("sounds\\miichannel.wav"), NULL, SND_ASYNC | SND_LOOP);
		break;
	case 7:
		PlaySound(TEXT("sounds\\rickroll.wav"), NULL, SND_ASYNC);
		break;
	case 8:
		PlaySound(TEXT("sounds\\sadviolin.wav"), NULL, SND_ASYNC);
		break;
	case 9:
		PlaySound(TEXT("sounds\\saul.wav"), NULL, SND_ASYNC);
		break;
	case 10:
		PlaySound(TEXT("sounds\\tobecontinued.wav"), NULL, SND_ASYNC);
		break;
	case 11:
		PlaySound(TEXT("sounds\\whistle.wav"), NULL, SND_ASYNC);
		break;
	case 12:
		PlaySound(TEXT("sounds\\win.wav"), NULL, SND_ASYNC);
		break;
	case 13:
		PlaySound(TEXT("sounds\\wish.wav"), NULL, SND_ASYNC);
		break;
	}
}