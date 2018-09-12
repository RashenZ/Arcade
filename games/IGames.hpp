//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Game interface
//

#ifndef IGAMES_HPP_
# define IGAMES_HPP_

# include <iostream>
# include <fstream>
# include <vector>
# include <string>
# include <array>
#include <algorithm>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iterator>
#include <ncurses.h>
#include <random>
#include <sstream>
#include <sys/timeb.h>

class   IGame {	
public:
	enum DIRECTION {
		UP,
		RIGHT,
		DOWN,
		LEFT,
		NONE
	};
	virtual ~IGame() = default;
        
	virtual void init() = 0;
	virtual void applyKeyPress(int key) = 0;
	virtual unsigned int	getSelect() = 0;
	virtual std::vector<std::string>	getMap() = 0;
	virtual int getAction() = 0;
	virtual void setUsername(std::string username) = 0;
};

typedef IGame *create_game_t();

#endif /* !IGAMES_HPP_ */
