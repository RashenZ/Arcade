//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Libcaca.hpp
//

#ifndef LIBCACA_HPP_
# define LIBCACA_HPP_

# include <iostream>
# include <caca.h>
# include <map>
# include "IGraphical.hpp"

class Libcaca : public IGraphical {
public:
	Libcaca();
	~Libcaca();
	void	init() override;
	void	destroy() override;
	void	display(std::vector<std::string> toDisplay, int selection) override;
	int	getKeyPress();
	void	clear_screen();

private:
	std::map<char, int> _entities;
	caca_display_t *_display;
	caca_canvas_t *_canvas;
	caca_event_t _event;

	unsigned int _lenmax;
	int _sizemax;
};

#endif /* !LIBCACA_HPP_ */
