//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Nibbler.hpp
//

#ifndef NIBBLER_HPP_
# define NIBBLER_HPP_

#include "IGames.hpp"

const int RESTART = 114;
const int SPEED_UP = 339;
const int SPEED_DOWN = 338;

class Nibbler: public IGame {
public:
	enum GAME_ACTION {
		NOTHING,
		ENDGAME,
		EXITPGRM
	};
	Nibbler(); 
	~Nibbler();
	Nibbler(const Nibbler &cpy);

	void init() override;
	void applyKeyPress(int key) override;
	unsigned int getSelect() override;
	std::vector<std::string> getMap() override;
	int	getAction() override;
	void	setUsername(std::string username) override;

	void	setScore();
	bool	canMove();
	void	newScoreInFile();
	void	restartGame();
	void	checkQueuePos(int *y, int *x, const int i);
	void	checkSpecialKey(int key);
	void	newHeadPos();
	void	moveSnake();
	void	generateFood();
	void	generateFruit();
	void	getQueuePos();
	void	initFood();
	void	initSnakePos();
	void	prepareMap();
	void	addScoreboard();
	void	checkTimerGame();

private:
	std::vector<std::string>	_saveNibblerMap;
	std::vector<std::string>	_nibblerMap;
	std::vector<std::array<int, 2>>	_saveSnakePos;
	std::vector<std::array<int, 2>>	_snakePos;
	std::vector<std::array<int, 2>>	_enemyPos;
	int				_movement;
	int				_snakeNumber;
	int				_enemyNumber;
	int				_action;
	int				_foodNbr;
	int				_fruitNbr;
	int				_gameSpeed;
	struct timeb			_time;
	unsigned int			_score;
	std::string			_username;
	int				_timerGame;
};

#endif /* NIBBLER_HPP_ */
