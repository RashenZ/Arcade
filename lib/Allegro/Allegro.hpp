//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Allegro.hpp
//

#ifndef ALLEGRO_HPP_
# define ALLEGRO_HPP_

# include <iostream>
# include <map>
# include <allegro5/allegro.h>
# include <allegro5/allegro_font.h>
# include <allegro5/allegro_ttf.h>
# include <allegro5/allegro_image.h>
# include <allegro5/allegro_native_dialog.h>
# include "IGraphical.hpp"

class Allegro : public IGraphical {
public:
	Allegro();
	~Allegro();
	void	init() override;
	void	destroy() override;
	void	display(std::vector<std::string> toDisplay, int selection) override;
	void	displayGame(std::vector<std::string> toDisplay);
	void	init_keyval(int, int);
	int	getKeyPress();

private:
	const float _pxSize;
	ALLEGRO_DISPLAY *_display;
	ALLEGRO_FONT *_font;
	ALLEGRO_EVENT_QUEUE *_event_queue;
	std::vector<std::pair<int, int>> _key_val;
	std::map<char, ALLEGRO_BITMAP *>_bitmap;
};

#endif /* !ALLEGRO_HPP_ */
