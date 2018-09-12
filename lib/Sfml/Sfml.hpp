//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Sfml.hpp
//

#ifndef SFML_HPP_
# define SFML_HPP_

# include <SFML/System.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <SFML/Audio.hpp>
# include <iostream>
# include "IGraphical.hpp"

class Sfml : public IGraphical {
public:
	Sfml();
	~Sfml();
	void	init() override;
	void	destroy() override;
	void	display(std::vector<std::string> toDisplay, int selection) override;
	int	getKeyPress();
	void	displayGame(std::vector<std::string> &toDisplay);

private:
	const float _pxSize;
	sf::RenderWindow *_window;
	sf::Music	*_music;
	std::map<char, sf::RectangleShape *> _entities;
};

#endif /* !SFML_HPP_ */
