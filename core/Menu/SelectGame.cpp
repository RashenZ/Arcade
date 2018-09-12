//
// EPITECH PROJECT, 2018
// arcade
// File description:
// menu/selectGame arcade 
//

#include "Menu.hpp"

void	Menu::changeSelectGame()
{
	if (_selectSelectGame == 4) {
		_gameName = "Nibbler";
                _sumWindow = MENU;
        }
        if (_selectSelectGame == 5) {
		_gameName = "Pacman";
		_sumWindow = MENU;
        }
}

void	Menu::keyPressSelectGame(int ch)
{
	if (ch == KEY_UP) {
                if (_selectSelectGame == 4)
                        _selectSelectGame = 5;
                else
                        _selectSelectGame = _selectSelectGame - 1;
        } else if (ch == KEY_DOWN) {
                if (_selectSelectGame == 5)
                        _selectSelectGame = 4;
                else
                        _selectSelectGame = _selectSelectGame + 1;
        }
	if (ch == 10)
		changeSelectGame();
}

void	Menu::prepareSelectGame()
{
	std::ifstream   myFile("./core/Menu/menuboard_map/selectGame");
	std::string     line;

	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, line);
			_selectGameMap.push_back(line);
		}
                std::cout << "selectGame saved." << std::endl;
	} else {
                std::cerr << "Error: cannot open selectGame file" << std::endl;
	}
	myFile.close();
}
