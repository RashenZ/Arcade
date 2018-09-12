//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Menu.hpp 
//

#ifndef MENU_HPP_
# define MENU_HPP_

#include <iostream>
#include <vector>
#include <ncurses.h>
#include <dlfcn.h>
#include <thread>
#include <chrono>
#include <exception>
#include <map>
#include <fstream>

class Menu {
public:
	enum WINDOW {
		MENU,
		SELECTGAME,
		OPTION,
		USERNAME,
		HELP_NIBBLER,
		HELP_PACMAN,
	};
	enum MENU_ACTION {
		NOTHING,
		ENDGAME,
		EXITPGRM,
		NIBBLER,
		PACMAN,
		CHANGELIB
	};
	Menu();
	~Menu();
	void	init();
	void	applyKeyPress(int key);
	unsigned int			getSelect();
	std::vector<std::string>	getMap();
	int		getAction();
	
	void	prepareMenu();
	void	prepareOption();
	void	prepareSelectGame();
	void	prepareUserName();

	void	keyPressMenu(int key);
	void	keyPressOption(int key);
	void	keyPressSelectGame(int key);
	void	keyPressUserName(int key);
        
	void	changeMenu();
	void	changeOption();
	void	changeSelectGame();
	void	changeUserName();

	void	userNameKeyUp();
	void	userNameKeyDown();
	void	userNameKeyLeft();
	void	userNameKeyRight();
	void	enterPressUserName();
	void	emptyCaseUsername();
	void	fillCaseUsername();
        
	std::string	getLibName();
	std::string	getGameName();
	std::string	getUsername();

private:
	std::vector<std::string>	_summaryMap;
	std::vector<std::string>	_optionMap;
	std::vector<std::string>	_selectGameMap;
	std::vector<std::string>	_userNameMap;
	
	unsigned int			_selectMenu;
	unsigned int			_selectOption;
	unsigned int			_selectSelectGame;
	unsigned int			_selectUserName;
        
	std::string			_gameName;
	std::string			_libName;
	
	int				_sumWindow;
	int				_action;

	int				_userName_x;
	int				_userName_y;
	int				_userName_pos;
	std::string			_username;
	std::string			_oldUsername;
};

#endif /* MENU_HPP_ */
