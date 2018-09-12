//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Pacman.cpp
//

#include "Pacman.hpp"


void	Pacman::init()
{
	std::srand(std::time(nullptr));
	int 	start_line = 3;

	_movement = NONE;
	_superSayan = 0;
	addScoreboard();
	prepareMap();
	putSomeCoins(150, 5, start_line);
	countCoins(start_line);
	putSomeEnnemies(start_line);
	initPacmanPos();
}

void	Pacman::applyKeyPress(int key)
{
	_pacmanMap = _clearMap;
	copyCoins();
	fillEnnemys(4);
	printPaquito();

	move_ennemys();
//	check_sayan();
	_action = NOTHING;
	switch (key) {
	case KEY_UP:
		_movement = UP;
		break;
	case KEY_DOWN:
		_movement = DOWN;
		break;
	case KEY_LEFT:
		_movement = LEFT;
		break;
	case KEY_RIGHT:
		_movement = RIGHT;
		break;
	}
	checkSpecialKey(key);
	if (_movement != NONE) {
		movePacman(key);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
//	gameTimer();
}


// Class factories
extern "C" IGame *create()
{
	return (new Pacman);
}
