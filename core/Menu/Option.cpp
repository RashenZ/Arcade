//
// EPITECH PROJECT, 2018
// arcade
// File description:
// menu/option ncurses 
//

#include "Menu.hpp"

void	Menu::changeOption()
{
	switch(_selectOption) {
	case 4:
		_action = CHANGELIB;
		break;
	case 5:
		fillCaseUsername();
		_sumWindow = USERNAME;
		break;
	case 6:
		_sumWindow = MENU;
		break;
	};
}

void	Menu::keyPressOption(int key)
{
	if (key == KEY_UP) {
		if (_selectOption == 4)
			_selectOption = 6;
		else
			_selectOption = _selectOption - 1;
	} else if (key == KEY_DOWN) {
		if (_selectOption == 6)
			_selectOption = 4;
		else
			_selectOption = _selectOption + 1;
	}
	if (key == 10)
		changeOption();
}

void	Menu::prepareOption()
{
	std::ifstream   myFile("./core/Menu/menuboard_map/option");
        std::string     line;

        if (myFile.is_open()) {
                while (!myFile.eof()) {
			getline(myFile, line);
                        _optionMap.push_back(line);
                }
		std::cout << "option saved." << std::endl;
	} else {
                std::cerr << "Error: cannot open option file" << std::endl;
        }
	myFile.close();
}
