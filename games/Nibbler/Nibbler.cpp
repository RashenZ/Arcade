//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Nibbler.cpp
//

#include "Nibbler.hpp"
#include <utility>

Nibbler::Nibbler()
	:_snakeNumber(0), _enemyNumber(0), _action(NOTHING), _gameSpeed(200),
	 _score(0), _timerGame(120)
{
	
	std::srand(std::time(nullptr));
	std::cout << "Nibbler Initialized" << std::endl;
}

Nibbler::Nibbler(const Nibbler &cpy)
{
	_nibblerMap = cpy._nibblerMap;
	_snakePos = cpy._snakePos;
	_enemyPos = cpy._enemyPos;
	_movement = cpy._movement;
	_snakeNumber = cpy._snakeNumber;
	_enemyNumber = cpy._enemyNumber;
	_action = cpy._action;
	_foodNbr = cpy._foodNbr;
	_fruitNbr = cpy._fruitNbr;
	_gameSpeed = cpy._gameSpeed;
	_time = cpy._time;
	_score = cpy._score;
	_username = cpy._username;
	_timerGame = cpy._timerGame;

}

Nibbler::~Nibbler()
{
//	myFile.close();
}

/*
** GETTER
*/
std::vector<std::string>	Nibbler::getMap()
{
	return (_nibblerMap);
}

unsigned int	Nibbler::getSelect()
{
	return (-1);
}

int	Nibbler::getAction()
{
	if ((_foodNbr <= 0 && _fruitNbr <= 0) || _timerGame <= 0) {
		_gameSpeed -= 25;
		restartGame();
	}
	return (_action);
}

/*
** SETTER
*/
void	Nibbler::setUsername(std::string username)
{
	unsigned int i = 0;
	std::size_t	pos = 0;
	
	_username = username;
	while (i < _nibblerMap.size()) {
		pos = _nibblerMap[i].find("Username");
		if (pos != std::string::npos) {
			for (unsigned int j = 0; j < _nibblerMap[i].size(); j++) {
				_nibblerMap[i][11 + j] = ' ';
			}
			for (unsigned int j = 0; j < _username.size(); j++) {
				_nibblerMap[i][11 + j] = _username[j];
			}
		}
		i = i + 1;
	}
}

void	Nibbler::setScore()
{
	std::ostringstream s;
	unsigned int i = 0;
	std::size_t	pos = 0;

	while (i < _nibblerMap.size()) {
		pos = _nibblerMap[i].find("score");
		if (pos != std::string::npos) {
			for (unsigned int j = pos; j < 10; j++) {
				_nibblerMap[i][7 + j] = ' ';
			}
			s << _score;
			const std::string score = s.str();
			for (unsigned int j = pos; j < score.size(); j++) {
				_nibblerMap[i][7 + j] = score[j];
			}
		}
		i = i + 1;
	}
}

void	Nibbler::newScoreInFile()
{
	std::ofstream file("./games/Nibbler/hallOfFame.txt", std::ofstream::app);
	std::ostringstream tmp_score;	
	std::ostringstream tmp_time;

	tmp_score << _score;
	const std::string score = tmp_score.str();
	tmp_time << _timerGame;
	const std::string time = tmp_time.str();
	file << "NAME: " << _username.c_str() << "\tSCORE: " << score << "\tTIME: " << time << std::endl;

	file.close();
}

void	Nibbler::restartGame()
{
	_nibblerMap = _saveNibblerMap;
	_snakePos = _saveSnakePos;
	_enemyPos.erase(_enemyPos.begin(), _enemyPos.end());
	_timerGame = 120;
	initFood();
	_movement = NONE;
	std::cout << "GOING TO INIT AGAIN"  << std::endl;
}

bool	Nibbler::canMove()
{
	switch (_movement) {
	case UP:
		if (_nibblerMap[_snakePos[0][0] - 1][_snakePos[0][1]] != '#')
			return (true);
		break;
	case DOWN:
		if (_nibblerMap[_snakePos[0][0] + 1][_snakePos[0][1]] != '#')
			return (true);
		break;
	case LEFT:
		if (_nibblerMap[_snakePos[0][0]][_snakePos[0][1] - 1] != '#')
			return (true);
		break;
	case RIGHT:
		if (_nibblerMap[_snakePos[0][0]][_snakePos[0][1] + 1] != '#')
			return (true);
		break;
	};
	return (false);
}

void	Nibbler::newHeadPos()
{
	switch (_movement) {
	case UP:
		_snakePos[0] = { _snakePos[1][0] - 1, _snakePos[1][1]};
		break;
	case DOWN:
		_snakePos[0] = { _snakePos[1][0] + 1, _snakePos[1][1]};
		break;
	case LEFT:
		_snakePos[0] = { _snakePos[1][0], _snakePos[1][1] - 1};
		break;
	case RIGHT:
		_snakePos[0] = { _snakePos[1][0], _snakePos[1][1] + 1};
		break;
	};
}

void	Nibbler::moveSnake()
{
	int	limit = _snakePos.size();
	int	i = 1;
	std::vector<std::array<int, 2>>	cpy_snakePos = _snakePos;

	if (canMove() == true) {
		while (i < limit) {
			_snakePos[i] = { cpy_snakePos[i - 1][0], cpy_snakePos[i - 1][1] };
			_nibblerMap[_snakePos[i][0]][_snakePos[i][1]] = 'E';
			i++;
		}
		_nibblerMap[cpy_snakePos[i - 1][0]][cpy_snakePos[i - 1][1]] = ' ';
		newHeadPos();
		switch (_nibblerMap[_snakePos[0][0]][_snakePos[0][1]]) {
		case '*':
			_snakePos.push_back({cpy_snakePos[i - 1][0], cpy_snakePos[i - 1][1]});
			_foodNbr--;
			_score += 100;
			setScore();
			break;
		case 'O':			
			_snakePos.push_back({ cpy_snakePos[i - 1][0], cpy_snakePos[i - 1][1]});
			_snakePos.push_back({ cpy_snakePos[i - 1][0], cpy_snakePos[i - 1][1]});
			_fruitNbr--;
			_score += 200;
			setScore();
			break;
		case 'E':
			newScoreInFile();
			_action = ENDGAME;
			_score = 0;
			restartGame();
			break;
		};
		_nibblerMap[_snakePos[0][0]][_snakePos[0][1]] = 'S';
	}
}

void	Nibbler::checkSpecialKey(int key)
{
	switch (key) {
	case RESTART:
		_action = NOTHING;
		restartGame();
		break;
	case SPEED_UP:
		_gameSpeed -= 25;
		break;
	case SPEED_DOWN:
		_gameSpeed += 25;
		break;
	};
}

void	Nibbler::checkTimerGame()
{
	std::ostringstream s;
	std::time_t result = std::time(nullptr);
	static std::time_t oldTime = 0;
	unsigned int	i = 0;
	std::size_t	pos = 0;

	if (oldTime != result) {
		_timerGame--;
		oldTime = result;
	}
	while (i < _nibblerMap.size()) {
		pos = _nibblerMap[i].find("time");
		if (pos != std::string::npos) {
			for (unsigned int j = pos; j < _nibblerMap[i].size(); j++) {
				_nibblerMap[i][7 + j] = ' ';
			}
			s << _timerGame;
			const std::string timerGame = s.str();
			for (unsigned int j = 0; j < timerGame.size(); j++) {
				_nibblerMap[i][pos + 6 + j] = timerGame[j];
			}
		}
		i = i + 1;
	}
}

void	Nibbler::applyKeyPress(int key)
{
	static int	incr = 0;
	
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
	if (_movement != NONE && incr >= _gameSpeed) {
		moveSnake();
		incr = 0;
	}
	checkTimerGame();
	incr++;
}

void	Nibbler::addScoreboard()
{
	std::ifstream myFile("./games/Nibbler/map/scoreboard");
	std::string     line;

	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, line);
			_saveNibblerMap.push_back(line);
		}
		std::cout << "scoreboard saved." << std::endl;
	} else {
		std::cerr << "Error: cannot open scoreboard file" << std::endl;
	}
}

void	Nibbler::prepareMap()
{
	std::ifstream myFile("./games/Nibbler/map/nibbler_map_game");
	std::string     line;

	addScoreboard();
	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, line);
			_saveNibblerMap.push_back(line);
		}
		myFile.close();
		std::cout << "map1 saved." << std::endl;;
	} else {
		std::cerr << "Error: cannot open map file" << std::endl;
	}
	_nibblerMap = _saveNibblerMap;
}

void	Nibbler::checkQueuePos(int *y, int *x, const int i)
{
	if (_enemyPos[i][0] == *y + 1 && _enemyPos[i][1] == *x) {
		_saveSnakePos.push_back({ *y + 1, *x });
		*y = *y + 1;
		_enemyPos.erase(_enemyPos.begin() + i);
		_enemyNumber--;
	} else if (_enemyPos[i][0] == *y - 1 && _enemyPos[i][1] == *x) {
		_saveSnakePos.push_back({ *y - 1, *x });
		*y = *y - 1;
		_enemyPos.erase(_enemyPos.begin() + i);
		_enemyNumber--;
	} else if (_enemyPos[i][0] == *y && _enemyPos[i][1] == *x + 1) {
		_saveSnakePos.push_back({ *y, *x + 1 });
		*x = *x + 1;
		_enemyPos.erase(_enemyPos.begin() + i);
		_enemyNumber--;
	} else if (_enemyPos[i][0] == *y && _enemyPos[i][1] == *x - 1) {
		_saveSnakePos.push_back({ *y, *x - 1 });
		_enemyPos.erase(_enemyPos.begin() + i);
		*x = *x - 1;
		_enemyNumber--;
	}
	       
}

void	Nibbler::getQueuePos()
{
	int	y = _saveSnakePos[0][0];
	int	x = _saveSnakePos[0][1];
	unsigned int	i = 0;
	bool		isNear = true;
	int		cpyEnemy = _enemyNumber;

	while (isNear) {
	        while (i < _enemyPos.size()) {
			checkQueuePos(&y, &x, i);
			i++;
		}
		if(cpyEnemy == _enemyNumber)
			isNear = false;
		else
			cpyEnemy = _enemyNumber;
		i = 0;
	}
	if (_enemyNumber != 0) {
		std::cerr << "Problem occur with ennemy" << std::endl;
		_action = EXITPGRM;
	}
}

void	Nibbler::initSnakePos()
{
	unsigned int	i = 0;
	size_t		pos = 0;

	while (i < _nibblerMap.size()) {
		pos = _nibblerMap[i].find("S");
		while (pos != std::string::npos) {
			_saveSnakePos.push_back( {static_cast<int>(i), static_cast<int>(pos) });
			_snakeNumber++;
			pos = _nibblerMap[i].find("S", pos + 1);
		}
		pos = _nibblerMap[i].find("E");
		while (pos != std::string::npos) {
			_enemyNumber++;
			_enemyPos.push_back( {static_cast<int>(i), static_cast<int>(pos) });
			pos = _nibblerMap[i].find("E", pos + 1);
		}
		i = i + 1;
	}
	getQueuePos();
	_snakePos = _saveSnakePos;
}

void	Nibbler::generateFood()
{
	int	y = std::rand() / ((RAND_MAX) / ((int)_nibblerMap.size() - 1));
	int	x = std::rand() / ((RAND_MAX) /(int)_nibblerMap[5].size());

	if (_nibblerMap[y][x] != ' ' || y < 4)
		generateFood();
	else {
		_nibblerMap[y][x] = '*';
	}
}

void	Nibbler::generateFruit()
{
	int	y = std::rand() / ((RAND_MAX) / ((int)_nibblerMap.size() - 1));
	int	x = std::rand() % (int)_nibblerMap[5].size();
        
	if (y < 4 || y > (int)_nibblerMap.size())
		generateFruit();
	else if (_nibblerMap[y][x] != ' ')
		generateFruit();
	else {
		_nibblerMap[y][x] = 'O';
	}

}

void	Nibbler::initFood()
{
	int	i = 0;

	_foodNbr = 50;
	_fruitNbr = 10;
	while (i < _foodNbr) {
		generateFood();
		i = i + 1;
	}
	i = 0;
	while (i < _fruitNbr) {
		generateFruit();
		i = i + 1;
	}
}

void	Nibbler::init()
{
	_movement = NONE;
	prepareMap();
	initFood();
	initSnakePos(); 
}

// Class factories
extern "C" IGame *create()
{
        return (new Nibbler);
}
