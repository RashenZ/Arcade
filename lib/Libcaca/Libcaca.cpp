//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Libcaca.cpp
//

#include <unistd.h>
#include <algorithm>
#include "Libcaca.hpp"

Libcaca::Libcaca()
{
	std::cout << "Libcaca initialized" << std::endl;
	_lenmax = 0;
	_sizemax = 0;
}

Libcaca::~Libcaca()
{
}

int	Libcaca::getKeyPress()
{
	const std::vector<int> err = {10, 258, 259, 260, 261};
	int key;

	if (caca_get_event(_display, CACA_EVENT_KEY_PRESS, &_event, 1) != 1)
		return (-1);
	key = caca_get_event_key_ch(&_event);
	if (std::find(err.begin(), err.end(), key) != err.end())
		return (-1);
	switch (key) {
	case 13:
		return (10);
	case 280:
		return (339);
	case 281:
		return (338);
	case 274:
		return (258);
	case 273:
		return (259);
	case 275:
		return (260);
	case 276:
		return (261);
	}
	return (key);
}

void	Libcaca::clear_screen(void)
{
	std::string clear (_lenmax, ' ');
	const char *clear_str = clear.c_str();

	for (int i = 0; i < _sizemax; i++)
		caca_put_str(_canvas, 0, i, clear_str);
}

void	Libcaca::display(std::vector<std::string> toDisplay, int selection)
{
	std::string str;
	int count = 0;
	int posx;

	clear_screen();
	for (const auto &line : toDisplay) {
		if (selection == -1) {
			posx = 0;
			for (const auto &frame : line) {
				caca_set_color_ansi(_canvas, CACA_WHITE, CACA_BLACK);
				if (_entities.find(frame) != _entities.end())
					caca_set_color_ansi(_canvas, _entities[frame], CACA_BLACK);
				str = frame;
				caca_put_str(_canvas, posx++, count, str.c_str());
			}
		} else {
			caca_set_color_ansi(_canvas, CACA_WHITE, CACA_BLACK);
			if (count == selection)
				caca_set_color_ansi(_canvas, CACA_GREEN, CACA_BLACK);
			caca_put_str(_canvas, 0, count, line.c_str());
		}
		++count;
		if (line.size() > _lenmax)
			_lenmax = line.size();
	}
	if (count > _sizemax)
		_sizemax = count;
	caca_refresh_display(_display);
}

void	Libcaca::destroy()
{
	caca_free_display(_display);
}

void	Libcaca::init()
{
	_display = caca_create_display(NULL);
	_canvas = caca_get_canvas(_display);
	caca_set_display_title(_display, "Libcaca mode");
	_entities['#'] = CACA_BLUE;
	_entities['S'] = CACA_RED;
        _entities['E'] = CACA_GREEN;
	_entities['O'] = CACA_YELLOW;
}

// Class factories
extern "C" IGraphical	*create()
{
	return (new Libcaca);
}
