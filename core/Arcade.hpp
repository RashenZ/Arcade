//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Core arcade
//

#ifndef ARCADE_HPP_
# define ARCADE_HPP_

#include <dlfcn.h>
#include <exception>
#include <thread>
#include <chrono>
#include <map>
#include "IGraphical.hpp"
#include "IGames.hpp"
#include "Menu/Menu.hpp"

const int PREVLIB = 49;
const int NEXTLIB = 50;
const int PREVGAME = 57;
const int NEXTGAME = 48;
const int BACKTOMENU = 27;
const int EXIT = 113;
	
class Arcade {
public:	
	enum lib_t {
		LGRAPHICALS,
		LGAMES
	};
	enum ACTION {
		NOTHING,
		ENDGAME,
		EXITPGRM,
		NIBBLER,
		PACMAN,
		CHANGELIB
	};
	
	Arcade(char *libarg);
	~Arcade();
	void	openGraphLib(const std::string &libpath, const std::string &libname);
	void	openGameLib(const std::string &libpath, const std::string &libname);
	void	loadDirLibs(const std::string &path, const lib_t ltype);
	void	changeLib();
	void	changeGame();
	void	getNewLib();
	void	checkAction();
	void	start();
	bool	isSpecialKey(int key);
	void	closeme();

private:
	using _createGraphObj = IGraphical	*(*)();
	using _createGameObj = IGame		*(*)();
	
	std::string	_libName;
	std::map<std::string, IGame *>	_gGame;
	std::map<std::string, IGraphical *>	_glib;
	std::string	_gameName;
	std::vector<void *> _handleGraph;
	std::vector<void *> _handleGame;
	std::unique_ptr<Menu>	_menu;
};

#endif /* ARCADE_HPP_ */
