//
// EPITECH PROJECT, 2018
// arcade
// File description:
// menu/username
//

#include "Menu.hpp"

void	Menu::changeUserName()
{
	switch (_userName_y) {
	case 11:
		_username = _oldUsername;
		_sumWindow = OPTION;
		emptyCaseUsername();
		return;
	case 12:
		_oldUsername = _username;
		_sumWindow = OPTION;
		emptyCaseUsername();
		return;
	};
        if (_userName_y == 5 && _userName_x == 31) {
		if ( _oldUsername.size() > 0) {
			_userNameMap[3][_userName_pos] = ' ';
			_oldUsername.pop_back();
			_userName_pos = _userName_pos - 1;
			_userNameMap[3][_userName_pos] = ']';
		}
	} else {
		_userNameMap[3][_userName_pos] = _userNameMap[_userName_y][_userName_x + 1];
		_oldUsername.push_back(_userNameMap[_userName_y][_userName_x + 1]);
		_userName_pos = _userName_pos + 1;
		_userNameMap[3][_userName_pos] = ']';
	}
}

void	Menu::userNameKeyUp()
{
	if (_userName_y > 5 && _userName_y < 10) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 2] = ' ';
		_userName_y = _userName_y - 1;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 2] = ']';
	}
	if (_userName_y == 11) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 8] = ' ';
		_userName_y -= 2;
		_userName_x = 10;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 2] = ']';
	} else if (_userName_y == 12) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 7] = ' ';
		_userName_y -= 1;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 8] = ']';
	}
}

void	Menu::userNameKeyDown()
{
	if (_userName_y < 9 && _userName_x < 30) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 2] = ' ';
		_userName_y = _userName_y + 1;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 2] = ']';
		return ;
	}
	if (_userName_y == 9) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 2] = ' ';
		_userName_y += 2;
		_userName_x = 10;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 8] = ']';
	} else if (_userName_y == 11) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 8] = ' ';
		_userName_y += 1;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 7] = ']';
	}
}

void	Menu::userNameKeyLeft()
{
	if (_userName_y <= 9 && _userName_x > 10 && _userName_x < 30) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 2] = ' ';
		_userName_x = _userName_x - 2;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 2] = ']';
	} else if (_userName_y == 5 && _userName_x == 31) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 4] = ' ';
		_userName_x = _userName_x - 3;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 2] = ']';
	}
}

void	Menu::userNameKeyRight()
{
	if (_userName_y <= 9 && _userName_x < 28) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 2] = ' ';
		_userName_x = _userName_x + 2;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 2] = ']';
	} else if (_userName_y == 5 && _userName_x == 28) {
		_userNameMap[_userName_y][_userName_x] = ' ';
		_userNameMap[_userName_y][_userName_x + 2] = ' ';
		_userName_x = _userName_x + 3;
		_userNameMap[_userName_y][_userName_x] = '[';
		_userNameMap[_userName_y][_userName_x + 4] = ']';
	}
}

void	Menu::emptyCaseUsername()
{
	while (_userName_pos > 16) {
		_userNameMap[3][_userName_pos] = ' ';
		_userName_pos--;
		_userNameMap[3][_userName_pos] = ']';
	}
}

void	Menu::fillCaseUsername()
{
	unsigned int	i = 0;

	while (i < _username.size()) {
		_userNameMap[3][_userName_pos] = _username[i];
		i = i + 1;
		_userName_pos = _userName_pos + 1;
		_userNameMap[3][_userName_pos] = ']';
	}
}

void	Menu::keyPressUserName(int key)
{
	switch(key) {
	case KEY_UP:
		userNameKeyUp();
		break;
	case KEY_DOWN:
		userNameKeyDown();
		break;
	case KEY_LEFT:
		userNameKeyLeft();
		break;
	case KEY_RIGHT:
		userNameKeyRight();
		break;
	};
	if (key == 10)
		changeUserName();
}

void	Menu::prepareUserName()
{
	std::ifstream   myFile("./core/Menu/menuboard_map/userName");
        std::string     line;

	_userName_y = 5;
	_userName_x = 10;
	_userName_pos = 16;
        if (myFile.is_open()) {
                while (!myFile.eof()) {
			getline(myFile, line);
                        _userNameMap.push_back(line);
                }
                std::cout << "userName saved." << std::endl;
        } else {
                std::cerr << "Error: cannot open userName file" << std::endl;
        }
	_username = "";
	_oldUsername = _username;
	_userNameMap[_userName_y][_userName_x] = '[';
	_userNameMap[_userName_y][_userName_x + 2] = ']';
	_userNameMap[3][_userName_pos] = ']';
	myFile.close();
}
