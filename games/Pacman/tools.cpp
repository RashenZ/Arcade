#include "Pacman.hpp"

Pacman::Pacman()
{
	std::cout << "Pacman initialized" << std::endl;
}

Pacman::~Pacman()
{
}

void	Pacman::setUsername(std::string username)
{
	unsigned int i = 0;
	std::size_t	pos = 0;
	
	_username = username;
	while (i < _clearMap.size()) {
		pos = _clearMap[i].find("Username");
		if (pos != std::string::npos) {
			for (unsigned int j = 0; j < _clearMap[i].size(); j++) {
				_clearMap[i][11 + j] = ' ';
			}
			for (unsigned int j = 0; j < _username.size(); j++) {
				_clearMap[i][11 + j] = _username[j];
			}
		}
		i = i + 1;
	}	
}

std::vector<std::string>	Pacman::getMap()
{
	return (_pacmanMap);
}

unsigned int	Pacman::getSelect()
{
	return (-1);
}

int		Pacman::getAction()
{
	if (_score == -1) {
		_action = MENU;
		_pacmanMap.clear();
		_ennemysPos.clear();
		_pacmanPos.clear();
		_movement = NONE;
		
		init();
	}
	return (_action);
}

void	Pacman::checkSpecialKey(int key)
{
	switch (key) {
	case 114:
		_score = 0;
		getAction();
		_action = NOTHING;
		break;
	case 266:
		_action = CHANGELIB;
		break;
	case 267:
		_action = CHANGELIB;
		break;
	case 272:
		_action = CHANGEGAME;
		break;
	case 273:
		_action = CHANGEGAME;
		break;
	};
}

int 	Pacman::possible_to_move(int id)
{
	int hor = _ennemysPos[id][2];
	int ver = _ennemysPos[id][3];

	if (hor == 0 && ver == 0)
		return (0);
	return (1);
}

void 		Pacman::move_ennemys()
{
	int 	id = 0;

	for (int i = 0; i <= 4; i++)
	{
		int pos_y = _ennemysPos[id][0];
		int pos_x = _ennemysPos[id][1];
		int y = 0;
		int x = 0;
		bool ok = false;
		int block = 0;
		_pacmanMap[pos_y][pos_x] = 'E';
		while (ok != true) {
			if (possible_to_move(id) == 0 || _pacmanMap[pos_y + y][pos_x + x] == '#') {
				int 	dir = ((rand() % 2) * 2) - 1;
				x = 0;
				y = 0;
				if (dir == -1) // déplacement vertical
					y = ((rand() % 2) * 2) - 1;
				if (dir == 1) // déplacement horizontal
					x = ((rand() % 2) * 2) - 1;
			}
			else {
				y = _ennemysPos[id][2];
				x = _ennemysPos[id][3];
			}
			if (_pacmanMap[pos_y + y][pos_x + x] == 'C') {
				if (_superSayan == 0) {
					getAction();
					_action = NOTHING;
				}
				if (_superSayan == 1)
					break;
			}
			else if (_pacmanMap[pos_y + y][pos_x + x] == 'E') {
				_ennemysPos[id][2] = -_ennemysPos[id][2];
				_ennemysPos[id][3] = -_ennemysPos[id][3];
				break ;
			}
			else if (_pacmanMap[pos_y + y][pos_x + x] == '*' ||
				_pacmanMap[pos_y + y][pos_x + x] == ' ' ||
				_pacmanMap[pos_y + y][pos_x + x] == 'O') {
					ok = true;
				}
			block++;
			if (block > 50)
				break;
		}
		_ennemysPos[id][0] = _ennemysPos[id][0] + y;
		_ennemysPos[id][1] = _ennemysPos[id][1] + x;
		_ennemysPos[id][2] = y;
		_ennemysPos[id][3] = x;
		id++;
	}
}

void	Pacman::setScore()
{
	std::ostringstream s;
	unsigned int i = 0;
	std::size_t	pos = 0;

	while (i < _clearMap.size()) {
		pos = _clearMap[i].find("score");
		if (pos != std::string::npos) {
			for (unsigned int j = pos; j < 10; j++) {
				_clearMap[i][7 + j] = ' ';
			}
			s << _score;
			const std::string score = s.str();
			for (unsigned int j = pos; j < score.size(); j++) {
				_clearMap[i][7 + j] = score[j];
			}
		}
		i = i + 1;
	}
}

void	Pacman::eat_it(int y, int x, int new_y, int new_x)
{
	if (_pacmanMap[new_y][new_x] == '*') {
		_nbCoins = _nbCoins - 1;
		_score = _score + 100;
		setScore();	
	}
	if (_pacmanMap[new_y][new_x] == 'O') {
		_nbFruits = _nbFruits - 1;
		_score = _score + 500;
//		go super
		_superSayan = 1;
		setScore();

	}
	_coins[y][x] = ' ';
	_pacmanPos[0][0] = new_y;
	_pacmanPos[0][1] = new_x;
}

void 	Pacman::kill_or_die(int y, int x, int new_y, int new_x)
{
	if (_superSayan == 0) {
		;
	}
	if (_superSayan == 1) {
		_coins[y][x] = ' ';
		_pacmanPos[0][0] = new_y;
		_pacmanPos[0][1] = new_x;
	}
}

void 	Pacman::move(int y, int x, int new_y, int new_x)
{
	_coins[y][x] = ' ';
	_pacmanPos[0][0] = new_y;
	_pacmanPos[0][1] = new_x;
}

void 	Pacman::movePacman(int key)
{
	int 	y = _pacmanPos[0][0];
	int 	x = _pacmanPos[0][1];
	_pacmanPos[0][2] = key;

	if (_movement == UP)
	{
		if (_pacmanMap[y - 1][x] == '*' || _pacmanMap[y - 1][x] == 'O')
			eat_it(y, x, y - 1, x);
		else if (_pacmanMap[y - 1][x] == 'E')
			kill_or_die(y, x, y - 1, x);
		else if (_pacmanMap[y - 1][x] == ' ')
			move(y, x, y - 1, x);
		_pacmanPos[0][2] = UP;
	}
	if (_movement == DOWN)
	{
		if (_pacmanMap[y + 1][x] == '*' || _pacmanMap[y + 1][x] == 'O')
			eat_it(y, x, y + 1, x);
		else if (_pacmanMap[y + 1][x] == 'E')
			kill_or_die(y, x, y + 1, x);
		else if (_pacmanMap[y + 1][x] == ' ')
			move(y, x, y + 1, x);
		_pacmanPos[0][2] = DOWN;
	}
	if (_movement == LEFT)
	{
		if (_pacmanMap[y][x - 1] == '*' || _pacmanMap[y][x - 1] == 'O')
			eat_it(y, x, y, x - 1);
		else if (_pacmanMap[y][x - 1] == 'E')
			kill_or_die(y, x, y, x - 1);
		else if (_pacmanMap[y][x - 1] == ' ')
			move(y, x, y, x - 1);
		_pacmanPos[0][2] = LEFT;
	}
	if (_movement == RIGHT)
	{
		if (_pacmanMap[y][x + 1] == '*' || _pacmanMap[y][x + 1] == 'O')
			eat_it(y, x, y, x + 1);
		else if (_pacmanMap[y][x + 1] == 'E')
			kill_or_die(y, x, y, x + 1);
		else if (_pacmanMap[y][x + 1] == ' ')
			move(y, x, y, x + 1);
		_pacmanPos[0][2] = RIGHT;
	}
}

void	Pacman::addScoreboard()
{
	std::ifstream   myFile("./games/Pacman/map/scoreboard");
	std::string     line;

	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, line);
			_clearMap.push_back(line);
		}
		std::cout << "scoreboard saved." << std::endl;
	} else {
		std::cerr << "Error: cannot open scoreboard file" << std::endl;
	}
}

void 	Pacman::prepareMap()
{
	std::ifstream   myFile("./games/Pacman/map/map_3");
	std::string     line;

	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, line);
			_clearMap.push_back(line);
		}
		std::cout << "map1 saved." << std::endl;
	} else {
		std::cerr << "Error: cannot open summary file" << std::endl;
	}
	_coins = _clearMap;
	_pacmanMap = _clearMap;
}

void 	Pacman::fill_sides(int x, int y, std::string side)
{
	if (side == "right") {
		while ((x >= 0 && (unsigned int)x < _coins[0].size()) &&
			   (_coins[y][x] == ' ' || _coins[y][x] == '*')) {
			_coins[y][x] = '*';
			x++;
		}
	}
	if (side == "left") {
		while ((x > 0 && (unsigned int)x < _coins[0].size()) &&
			   (_coins[y][x] == ' ' ||  _coins[y][x] == '*')) {
				_coins[y][x] = '*';
			x--;
		}
	}
}

void		Pacman::countCoins(int begin_line)
{
	int 	line = 0;

	_nbCoins = 0;
	_nbFruits = 0;
	for (auto it = _coins.begin(); it != _coins.end(); it++) {
		if (line >= begin_line) {
			_nbCoins = _nbCoins + std::count(it->begin(), it->end(), '*');
			_nbFruits = _nbFruits + std::count(it->begin(), it->end(), 'O');
		}
		line = line + 1;
	}
}

void 		Pacman::putSomeCoins(int nb_coins, int nb_fruits, int begin_line)
{
	int 	y = 0;
	int 	x = 0;

	for (int i = 0; i < nb_coins;) {
		y = std::rand() % _coins.size();
		x = std::rand() % _coins[0].size();
		if ((_coins[y][x] == ' ' || _coins[y][x] == '*') && y >= begin_line) {
			fill_sides(x + 1, y, "right");
			fill_sides(x - 1, y, "left");
			_coins[y][x] = '*';
			i++;
		}
	}
	for (int i = 0; i < nb_fruits;)
	{
		y = std::rand() % _coins.size();
		x = std::rand() % _coins[0].size();
		if ((_coins[y][x] == ' ' || _coins[y][x] == '*') && y >= begin_line) {
			_coins[y][x] = 'O';
			i++;
		}
	}
}

void 	Pacman::copyCoins()
{
	unsigned int y = 3;

	while (y < _coins.size())
	{
		unsigned int x = 0;
		while (x < _coins[0].size())
		{
			if (_coins[y][x] == '*')
				_pacmanMap[y][x] = '*';
			if (_coins[y][x] == 'O')
				_pacmanMap[y][x] = 'O';
			x++;
		}
		y++;
	}
}

void 	Pacman::putSomeEnnemies(int begin_line)
{
	for (int i = 0; i < 5;) {
		int y = std::rand() % _pacmanMap.size();
		int x = std::rand() % _pacmanMap[0].size();
		if ((_pacmanMap[y][x] == ' ' || _pacmanMap[y][x] == '*') && y >= begin_line) {
			_pacmanMap[y][x] = 'E';
			_ennemysPos.push_back({y, x, 0, 0});
			i++;
		}
	}
}

void 	Pacman::initPacmanPos()
{
	size_t	pos = 0;
	int k = 0;

	for (int i = 0; (unsigned int)i < _pacmanMap.size(); i++) {
		pos = _pacmanMap[i].find("C");
		if (pos != std::string::npos) {
			_pacmanPos.push_back({(int)i, (int)pos});
			k = i;
			break;
		}
	}
	_clearMap[k][pos] = ' ';
}

void 	Pacman::fillEnnemys(int nb_ennemys)
{
	for (int idx = 0; idx != nb_ennemys; idx++)
	{
		int y = _ennemysPos[idx][0];
		int x = _ennemysPos[idx][1];
		_pacmanMap[y][x] = 'E';
	}
}

void 	Pacman::printPaquito()
{
	int y = _pacmanPos[0][0];
	int x = _pacmanPos[0][1];

	_pacmanMap[y][x] = 'C';
}