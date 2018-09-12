//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Allegro.cpp
//

#include "Allegro.hpp"
#include <unistd.h>

Allegro::Allegro()
	: _pxSize(30.f)
{
	std::cout << "Allegro initialized" << std::endl;
}

Allegro::~Allegro()
{
}

int	Allegro::getKeyPress()
{
	ALLEGRO_KEYBOARD_STATE ret_state;

	al_get_keyboard_state(&ret_state);
	for (const auto &e : _key_val) {
		if (al_key_down(&ret_state, e.first))
			return (e.second);
	}
	return (-1);
}

void	Allegro::displayGame(std::vector<std::string> toDisplay)
{
	size_t x = 1, y = 1;

	for (const auto &s : toDisplay) {
		for (const auto &i : s) {
			if (_bitmap.find(i) != _bitmap.end())
				al_draw_bitmap(_bitmap[i], x * _pxSize, y * _pxSize, 0);
			++x;
		}
		x = 1;
		++y;
	}
}

void	Allegro::display(std::vector<std::string> toDisplay, int selection)
{
	float newline = 600.f / toDisplay.size();
	float start = 100.f;
	int count = 0;
	ALLEGRO_COLOR curr;

	al_clear_to_color(al_map_rgb(0, 0, 0));
	if (selection == -1) {
		newline = 32;
		start = 0;
	}
	for (const auto &elem : toDisplay) {
		curr = al_map_rgb(255, 255, 255);
		if (count == 3 && selection == -1)
			break;
		if (count == selection && selection != -1)
			curr = al_map_rgb(173, 255, 47);
		al_draw_text(_font, curr, 0, start, ALLEGRO_ALIGN_LEFT, elem.c_str());
		start += newline;
		++count;
	}
	if (selection == -1)
		displayGame(toDisplay);
	al_flip_display();
}

void	Allegro::destroy()
{
	for (const auto &e : _bitmap)
		al_destroy_bitmap(e.second);
	al_destroy_display(_display);
}

void	Allegro::init_keyval(int key, int val)
{
	_key_val.push_back(std::make_pair(key, val));
}

void	Allegro::init()
{
	al_init();
	_display = al_create_display(1200, 800);

	al_init_ttf_addon();
	_font = al_load_ttf_font("./arial.ttf", 36, 0);
	al_install_keyboard();

	_event_queue = al_create_event_queue();
	al_register_event_source(_event_queue, al_get_keyboard_event_source());

	al_init_image_addon();
	_bitmap['#'] = al_load_bitmap("./sprites/block.png");
	_bitmap['S'] = al_load_bitmap("./sprites/player.png");
	_bitmap['E'] = al_load_bitmap("./sprites/ennemy.png");
	_bitmap['*'] = al_load_bitmap("./sprites/pin.png");
	_bitmap['O'] = al_load_bitmap("./sprites/pacgum.png");

	init_keyval(ALLEGRO_KEY_ENTER, 10);
	init_keyval(ALLEGRO_KEY_LEFT, 260);
	init_keyval(ALLEGRO_KEY_RIGHT, 261);
	init_keyval(ALLEGRO_KEY_UP, 259);
	init_keyval(ALLEGRO_KEY_DOWN, 258);
	init_keyval(ALLEGRO_KEY_R, 114);
	init_keyval(ALLEGRO_KEY_Q, 113);
	init_keyval(ALLEGRO_KEY_ESCAPE, 27);
	init_keyval(ALLEGRO_KEY_1, 49);
	init_keyval(ALLEGRO_KEY_2, 50);
	init_keyval(ALLEGRO_KEY_9, 57);
	init_keyval(ALLEGRO_KEY_0, 48);
	init_keyval(ALLEGRO_KEY_PGUP, 339);
	init_keyval(ALLEGRO_KEY_PGDN, 338);
}

// Class factories
extern "C" IGraphical	*create()
{
	return (new Allegro);
}
