#include "Game.h"

Game::~Game()
{
	Color::deleteInstance();
	Screen::deleteInstance();
}