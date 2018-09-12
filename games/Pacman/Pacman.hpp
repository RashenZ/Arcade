//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Pacman.hpp
//

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

# include "IGames.hpp"
# include <sys/timeb.h>

class Pacman : public IGame {
public:
	enum MOVEMENT {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		NONE
	};
	enum ACTION {
		NOTHING,
		CHANGELIB,
		EXIT,
		MENU,
		NIBBLER,
		PACMAN,
		PAUSE,
		RESTART,
		CHANGEGAME
	};
	Pacman();
	~Pacman();

	void init() override;
	void applyKeyPress(int key) override;
	unsigned int getSelect() override;
	std::vector<std::string> getMap() override;
	int	getAction() override;
	void	setUsername(std::string username) override;
	void 	prepareMap();
	void 	initPacmanPos();
	void 	putSomeEnnemies(int begin_line);
	void 	putSomeCoins(int nb_coins, int nb_fruits, int begin_line);
	void 	fill_sides(int x, int y, std::string side);
	void 	move_ennemys();
	void 	pacmanisdead();
	void	checkSpecialKey(int key);
	void 	movePacman(int key);
	void	eat_it(int y, int x, int new_y, int new_x);
	void	kill_or_die(int y, int x, int new_y, int new_x);
	void	move(int y, int x, int new_y, int new_x);
	void	countCoins(int begin_line);
	void 	check_sayan();
	void	addScoreboard();
	int  	possible_to_move(int id);
	void	setScore();
	void	restartGame();
	void 	gameTimer();
	void 	copyCoins();
	void 	fillEnnemys(int nb_ennemys);
	void 	printPaquito();

private:
	std::vector<std::array<int, 5>> 	_pacmanPos;
	std::vector<std::array<int, 4>> 	_ennemysPos;
	std::vector<std::string>			_pacmanMap;
	std::vector<std::string>			_coins;
	std::vector<std::string> 			_clearMap;
	int 		_movement;
	std::string	_username;
	int 		_action;
	int 		_score;
	int 		_nbCoins;
	int 		_nbFruits;
	int 		_superSayan;
	int 		_timer;

};

#endif /* PACMAN_HPP_ */
