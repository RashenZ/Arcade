//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Ncurses.hpp
//

#ifndef NCURSES_HPP_
# define NCURSES_HPP_

# include <iostream>
# include <ncurses.h>
# include "IGraphical.hpp"

class Ncurses : public IGraphical {
public:
	Ncurses();
	~Ncurses();
	void	init() override;
	void	destroy() override;
	void	display(std::vector<std::string> toDisplay, int selection) override;
	int	getKeyPress() override;

private:
};

#endif /* !NCURSES_HPP_ */
