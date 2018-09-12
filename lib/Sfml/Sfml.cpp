//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Sfml.cpp
//

#include "Sfml.hpp"

Sfml::Sfml()
	: _pxSize(32.f)
{
	std::cout << "Sfml initialized" << std::endl;
}

Sfml::~Sfml()
{
}

int	Sfml::getKeyPress()
{
	sf::Event event;

	_window->pollEvent(event);
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Return:
			return (10);
		case sf::Keyboard::Left:
			return (260);
		case sf::Keyboard::Right:
			return (261);
		case sf::Keyboard::Up:
			return (259);
		case sf::Keyboard::Down:
			return (258);
		case sf::Keyboard::PageUp:
			return (339);
		case sf::Keyboard::PageDown:
			return (338);
		case sf::Keyboard::R:
			return (114);
		case sf::Keyboard::Q:
			return (113);
		case sf::Keyboard::Escape:
			return (27);
		case sf::Keyboard::Num1:
			return (49);
		case sf::Keyboard::Num2:
			return (50);

		case sf::Keyboard::Num9:
			return (57);
		case sf::Keyboard::Num0:
			return (48);
		default:
			return (-1);
		}
	}
	return (-1);
}

void	Sfml::displayGame(std::vector<std::string> &toDisplay)
{
	size_t x = 1, y = 1;

	for (const auto &s : toDisplay) {
		if (y > 3) {
			for (const auto &i : s) {
				if (i != ' ') {
					_entities[i]->setPosition(x * _pxSize, y * _pxSize);
					_window->draw(*_entities[i]);
				}
				++x;
			}
			x = 1;
		}
		++y;
	}
}

void	Sfml::display(std::vector<std::string> toDisplay, int selection)
{
	std::string content;
	static sf::Font font;
	font.loadFromFile("arial.ttf");
	static sf::Text sfText ("hello", font);
	int	count = 0;

	_window->clear();
	for (const auto &i : toDisplay) {
		if (selection == -1 && count == 3)
			break;
		sfText.move(0, 25.0f);
		if (selection == count)
			sfText.setColor(sf::Color::Green);
		else
			sfText.setColor(sf::Color::White);
		content = i + '\n';
		sfText.setString(content);
		sfText.setCharacterSize(24);
		
		_window->draw(sfText);
		count++;
	}
	if (selection == -1)
		displayGame(toDisplay);
	_window->display();
}

void	Sfml::destroy()
{
	_window->close();
}

void	Sfml::init()
{
	sf::SoundBuffer buffer;
	const std::string tmp ("#SE*O");

	for (const auto &i : tmp)
		_entities[i] = new sf::RectangleShape (sf::Vector2f(_pxSize, _pxSize));
	_entities['#']->setFillColor(sf::Color::Blue);
	_entities['S']->setFillColor(sf::Color::Red);
	_entities['E']->setFillColor(sf::Color::Green);
	_entities['*']->setFillColor(sf::Color::Yellow);
	_entities['O']->setFillColor(sf::Color::Magenta);
	_window = new sf::RenderWindow (sf::VideoMode(1200, 800), "SFML mode");
	_window->display();
}

// Class factories
extern "C" IGraphical	*create()
{
	return (new Sfml);
}
