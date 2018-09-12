//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Graphical interface
//

#ifndef IGRAPHICAL_HPP_
# define IGRAPHICAL_HPP_

# include <iostream>
# include <vector>
# include <functional>
# include <string>
# include <chrono>
#include <thread>

class   IGraphical {
public:
	enum ENTITY {
		PLAYER,
		ENEMY,
		ITEM,
		WALL,
		NONE
	};

	virtual ~IGraphical() = default;

	virtual void init() = 0;
	virtual void display(std::vector<std::string> toDisplay, int selection) = 0;
	virtual void destroy() = 0;
	virtual int  getKeyPress() = 0;
};


typedef IGraphical *create_graph_t();

#endif /* !IGRAPHICAL_HPP_ */
