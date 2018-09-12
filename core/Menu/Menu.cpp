//
// EPITECH PROJECT, 2018
// arcade
// File description:
// menu.cpp
//

#include "Menu.hpp"

Menu::Menu()
	:_selectMenu(6), _selectOption(4), _selectSelectGame(4),
	 _gameName("Nibbler"), _libName(""), _sumWindow(MENU), 
	 _action(NOTHING)
{
	std::cout << "Menu Initialized" << std::endl;
}

Menu::~Menu()
{
}

/*
** GETTER
*/
std::vector<std::string>	Menu::getMap()
{
	switch(_sumWindow) {
	case SELECTGAME:
		return _selectGameMap;
	case OPTION:
		return _optionMap;
	case USERNAME:
		return _userNameMap;
	default:
		return _summaryMap;
	};
}

unsigned int		Menu::getSelect()
{
	switch(_sumWindow) {
	case SELECTGAME:
		 return _selectSelectGame;
	case OPTION:
		return _selectOption;
	case USERNAME:
		return _selectUserName;
	default:
		return _selectMenu;
	};
}

int			Menu::getAction()
{
	return _action;
}

std::string		Menu::getLibName()
{
	return _libName;
}

std::string		Menu::getGameName()
{
	return _gameName;
}

std::string		Menu::getUsername()
{
	return _username;
}

/*
** ACTION
*/
void	Menu::changeMenu()
{
	if (_selectMenu == 6) {
		if (_gameName == "Pacman")
			_action = PACMAN;
		else if (_gameName == "Nibbler")
			_action = NIBBLER;
	}
	if (_selectMenu == 7) {
		_sumWindow = SELECTGAME;
	}
	if (_selectMenu == 8) {
		_sumWindow = OPTION;
	}
	if (_selectMenu == 10) {
		_action = EXITPGRM;
	}
}

void	Menu::keyPressMenu(int key)
{
	if (key == KEY_UP) {
		if (_selectMenu == 6)
			_selectMenu = 10;
		else
			_selectMenu = _selectMenu - 1;
	} else if (key == KEY_DOWN) {
		if (_selectMenu == 10)
			_selectMenu = 6;
		else
			_selectMenu = _selectMenu + 1;
	}
	if (key == 10)
		changeMenu();
}

void	Menu::applyKeyPress(int key)
{
	_action = NOTHING;
	switch(_sumWindow) {
	case MENU:
		keyPressMenu(key);
		break;
	case SELECTGAME:
		keyPressSelectGame(key);
		break;
	case OPTION:
		keyPressOption(key);
		break;
	case USERNAME:
		keyPressUserName(key);
		break;
	};
}

/*
** INITIALIZATION
*/
void	Menu::prepareMenu()
{
	std::ifstream	myFile("./core/Menu/menuboard_map/summary");
	std::string	line;

	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, line);
			_summaryMap.push_back(line);
		}
		std::cout << "summary saved." << std::endl;
	} else {
		std::cerr << "Error: cannot open summary file" << std::endl;
	}
	myFile.close();
}

void	Menu::init()
{
	prepareMenu();
	prepareOption();
	prepareSelectGame();
	prepareUserName();
}
