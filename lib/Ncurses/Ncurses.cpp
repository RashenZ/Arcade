//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Ncurses.cpp
//

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
	std::cout << "Ncurses initialized" << std::endl;
}

Ncurses::~Ncurses()
{
}

int	Ncurses::getKeyPress()
{
	int	ch = -1;

	ch = getch();
	return (ch);
}

void	Ncurses::display(std::vector<std::string> toDisplay, int selection)
{
	unsigned int    i = 0;
	int		y;
	int		x;

	clear();
        getmaxyx(stdscr, y, x);
        while (i < toDisplay.size()) {
		if (i == (unsigned int)selection) {
			attron(COLOR_PAIR(1));
			mvprintw(y / 3 + i, x / 3, "%s", toDisplay[i].c_str());
			attroff(COLOR_PAIR(1));
                } else {
			mvprintw(y / 3 + i, x / 3, "%s", toDisplay[i].c_str());
                }
                i++;
        }
}

void	Ncurses::destroy()
{
	endwin();
}

void	Ncurses::init()
{
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	curs_set(0);
	noecho();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	destroy();
}

// Class factories
extern "C"
{
	IGraphical	*create()
	{
		return (new Ncurses);
	}
}
